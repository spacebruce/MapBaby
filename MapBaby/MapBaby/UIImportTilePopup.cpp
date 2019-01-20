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
	if (ImGui::BeginPopupModal(this->identifier, nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		ImGui::BeginChild("space filler", ImVec2(256, 128));
		ImGui::EndChild();
		ImGui::EndPopup();
	}
}