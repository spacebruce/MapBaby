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
	Width = 16;
	Height = 16;
	LockSize = true;
}

void UICreateTilePopup::updateContents()
{
	if (ImGui::BeginPopupModal(this->identifier, nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		ImGui::Button("Load from file");
		ImGui::Separator();

		ImGui::BeginChild("thing", ImVec2(300, 140));

		ImGui::Columns(2, nullptr, false);
		ImGui::Image(0, ImVec2(128, 128));

		ImGui::NextColumn();

		ImGui::Checkbox("Lock size", &LockSize);
		ImGui::InputScalar("Width", ImGuiDataType_U32, &Width);
		ImGui::InputScalar("Height", ImGuiDataType_U32, &Height);

		ImGui::EndChild();

		ImGui::Separator();
		if (ImGui::Button("create"))
		{
			tileManager->createTile(paletteManager->getCurrentPalette());
			ImGui::CloseCurrentPopup();
		}
		ImGui::SameLine();
		if (ImGui::Button("close"))
		{
			ImGui::CloseCurrentPopup();
		}
		ImGui::EndPopup();
	}
}