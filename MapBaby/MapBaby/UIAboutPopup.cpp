#include "UIAboutPopup.h"


UIAboutPopup::UIAboutPopup() : UIPopupBase("About MapBaby")
{
}

UIAboutPopup::~UIAboutPopup()
{
}

void UIAboutPopup::updateContents()
{
	if (ImGui::BeginPopupModal(this->identifier, nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove))
	{
		ImGui::Text("MapBaby!");

		ImGui::BeginChild("filler box", ImVec2(256, 128));
		ImGui::EndChild();

		ImGui::Separator();
		if (ImGui::Button("Close"))
		{
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}
}