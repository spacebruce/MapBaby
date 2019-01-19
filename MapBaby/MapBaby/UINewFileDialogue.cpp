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

void UINewFileDialogue::updateContents()
{
	if (ImGui::BeginPopupModal("New map"))
	{
		if (ImGui::Button("new"))
		{
			mapManager->newMap();
			selectMap(mapManager->getCount() - 1);
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}