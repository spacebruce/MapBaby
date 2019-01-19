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
}

void UINewFileDialogue::updateContents()
{
	if (ImGui::BeginPopupModal(this->identifier, nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		ImGui::InputText("Name", &name);
		ImGui::InputScalar("Width", ImGuiDataType_U32, &width);
		ImGui::InputScalar("Height", ImGuiDataType_U32, &height);

		ImGui::Separator();

		if (ImGui::Button("create"))
		{
			mapManager->newMap(Map(width, height));
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