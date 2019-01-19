#include "UICreateTilePopup.h"

UICreateTilePopup::UICreateTilePopup(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : UIPopupBase("Create Tile", mapManager, paletteManager, tileManager, mapEditor)
{
}

UICreateTilePopup::UICreateTilePopup()
{
}

UICreateTilePopup::~UICreateTilePopup()
{
}

void UICreateTilePopup::reset()
{

}

void UICreateTilePopup::updateContents()
{
	if (ImGui::BeginPopupModal(this->identifier, nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		if (ImGui::Button("make"))
		{
			tileManager->createTile(paletteManager->getCurrentPalette());
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}