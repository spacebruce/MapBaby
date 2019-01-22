#include "UINewFileDialogue.h"

UINewFileDialogue::UINewFileDialogue() : UIPopupBase()
{
}

UINewFileDialogue::UINewFileDialogue(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : UIPopupBase("New map", mapManager, paletteManager, tileManager, mapEditor)
{
}

UINewFileDialogue::~UINewFileDialogue() 
{
}

void UINewFileDialogue::reset()
{
	name = "unnamed";
	width = 10;
	height = 10;
	TileWidth = 16;
	TileHeight = 16;
}

void UINewFileDialogue::updateContents()
{
	if (ImGui::BeginPopupModal(this->identifier, nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		ImGui::InputText("Name", &name);

		ImGui::InputInt("Width", &width);	
		ImGui::SameLine();
		ImGui::Text("(%i)", width * TileWidth);
		ImGui::InputInt("Height", &height);
		ImGui::SameLine();
		ImGui::Text("(%i)", width * TileHeight);

		ImGui::InputInt("Tile Width", &TileWidth);
		ImGui::InputInt("Tile Height", &TileHeight);

		ImGui::Separator();

		if (ImGui::Button("create") && (name.length() > 0))
		{
			auto map = Map(name, width, height);

			map.setTileSize(TileWidth, TileHeight);

			mapManager->newMap(map);
			selectMap(mapManager->getCount() - 1);
			ImGui::CloseCurrentPopup();
		}
		ImGui::SameLine();

		if (ImGui::Button("cancel"))
		{
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}