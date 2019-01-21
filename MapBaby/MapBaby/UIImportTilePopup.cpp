#include "UIImportTilePopup.h"

UIImportTilePopup::UIImportTilePopup() : UIPopupBase("Import tile")
{
}

UIImportTilePopup::~UIImportTilePopup()
{
}

void UIImportTilePopup::reset()
{

}

void UIImportTilePopup::updateContents()
{
	if (ImGui::BeginPopup(this->identifier, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		ImGui::BeginChild("space filler", ImVec2(256, 128));
		ImGui::EndChild();

		ImGui::Separator();
		if (ImGui::Button("create"))
		{
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