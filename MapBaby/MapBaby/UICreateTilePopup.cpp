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
	if (ImGui::BeginPopup(this->identifier, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		ImGui::BeginChild("thing", ImVec2(300, 140));

		ImGui::Columns(2, nullptr, false);
		ImGui::ImageButton(0, ImVec2(128, 128));

		ImGui::NextColumn();

		ImGui::Checkbox("Lock to map size", &LockSize);

		bool tooltip = false;
		ImGui::InputScalar("Width", ImGuiDataType_U32, &Width);
		tooltip = ImGui::IsItemHovered();
		ImGui::InputScalar("Height", ImGuiDataType_U32, &Height);
		tooltip = (tooltip || ImGui::IsItemHovered());

		if (LockSize)
		{
			Map * map = mapManager->getCurrentMap();
			if (map != nullptr)
			{
				Width = map->getTileSize();
				Height = map->getTileSize();
			}
			if (tooltip)
			{
				ImGui::BeginTooltip();
				ImGui::Text("Locked");
				ImGui::EndTooltip();
			}
		}

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