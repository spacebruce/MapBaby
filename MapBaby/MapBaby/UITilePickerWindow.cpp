#include "UITilePickerWindow.h"


UITilePickerWindow::UITilePickerWindow() : UIWindowBase()
{
}

UITilePickerWindow::UITilePickerWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : UIWindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
	this->createTilePopup = UICreateTilePopup(mapManager, paletteManager, tileManager, mapEditor);
}

UITilePickerWindow::~UITilePickerWindow()
{
}

void UITilePickerWindow::updateContents()
{
	ImGui::Begin("Tiles", &visible, ImGuiWindowFlags_None);

	//Header
	if (ImGui::Button("New"))
	{
		createTilePopup.open();
	}
	ImGui::SameLine();
	if (ImGui::Button("Import"))
	{
		importTilePopup.open();
	}
	
	ImGui::SameLine();
	if (ImGui::Button("View"))
	{
		ViewGrid = !ViewGrid;
	}

	ImGui::PushItemWidth(ImGui::GetWindowContentRegionWidth());
	ImGui::SliderInt("Zoom", &ViewSize, 8, 64);

	//Box
	ImGui::BeginChild("TileBox", ImVec2(-1, 300), true, 0);

	if (ViewGrid)
		GridView();
	else
		ListView();

	ImGui::EndChild();

	ImGui::End();

	//Popups
	createTilePopup.update();
	importTilePopup.update();
}


void UITilePickerWindow::ListView()
{
	for (std::size_t i = 0; i < tileManager->getCount(); ++i)
	{
		TileManager::SharedTile tile = tileManager->getTile(i);

		int texture = 0;
		if (tileManager->getTile(i)->texture.isLoaded())
		{
			texture = tile.get()->texture.get();
		}

		bool selected = (tileManager->getSelectedID() == tile.get()->getID());

		if (ImGui::ImageButton((void*)texture, ImVec2(ViewSize, ViewSize)))
		{
			tileManager->setSelected(tile.get()->getID());
		};
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::Image((void*)texture, ImVec2(128, 128));
			ImGui::EndTooltip();
		}
		ImGui::SameLine();
		ImGui::Text("ID : %i", tile->getID());
		if (selected)
		{
			ImGui::SameLine();
			ImGui::Text("SELECTED");
		}
	}
}

void UITilePickerWindow::GridView()
{
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec2 icon = ImVec2(ViewSize, ViewSize);

	float ClipRight = ImGui::GetWindowPos().x + ImGui::GetWindowContentRegionMax().x;
	for (std::size_t i = 0; i < tileManager->getCount(); ++i)
	{
		TileManager::SharedTile tile = tileManager->getTile(i);

		int texture = 0;
		if (tileManager->getTile(i)->texture.isLoaded())
		{
			texture = tile.get()->texture.get();
		}

		if (ImGui::ImageButton((void*)texture, icon))
		{
			tileManager->setSelected(tile.get()->getID());
		}
		if (ImGui::IsItemHovered())
		{
			ImGui::BeginTooltip();
			ImGui::Image((void*)texture, ImVec2(128, 128));
			ImGui::EndTooltip();
		}

		float next_button_x2 = ImGui::GetItemRectMax().x + style.ItemSpacing.x + icon.x;
		if (i + 1 < tileManager->getCount() && next_button_x2 < ClipRight)
		{
			ImGui::SameLine();
		}
	}
}