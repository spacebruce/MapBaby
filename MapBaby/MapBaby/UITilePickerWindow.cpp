#include "UITilePickerWindow.h"


UITilePickerWindow::UITilePickerWindow() : WindowBase()
{
}

UITilePickerWindow::UITilePickerWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : WindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

UITilePickerWindow::~UITilePickerWindow()
{
}

void UITilePickerWindow::update()
{
	ImGui::Begin("Tiles", &visible, ImGuiWindowFlags_AlwaysAutoResize);

	if (ImGui::Button("new"))
	{
		tileManager->createTile(paletteManager->getCurrentPalette());
	}

	ImGui::BeginChild("TilePickerScroll", ImVec2(300, 300), true, 0);
	for (std::size_t i = 0; i < tileManager->getCount(); ++i)
	{
		if (tileManager->getTile(i)->getTexture()->isLoaded())
		{
			TileManager::SharedTile tile = tileManager->getTile(i);
			bool selected = (tileManager->getSelectedID() == tile.get()->getID());

			if (ImGui::ImageButton((void*)tile.get()->getTexture()->get(), ImVec2(32, 32)))
			{
				tileManager->setSelected(tile.get()->getID());
			};
			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();
				ImGui::Image((void*)tile->getTexture()->get(), ImVec2(128, 128));
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
	ImGui::EndChild();
	ImGui::End();
}