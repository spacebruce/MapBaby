#pragma once
#include "include/Imgui/imgui.h"

namespace ImGui
{
	inline bool ButtonDisable(const char* label, bool enabled = true, const ImVec2& size = ImVec2(0, 0))
	{
		if (enabled)
		{
			return ImGui::Button(label, size);
		}
		else
		{
			ImGuiStyle * style = &ImGui::GetStyle();
			ImVec4 disabled_fg = style->Colors[ImGuiCol_TitleBg];
			ImVec4 disabled_bg = style->Colors[ImGuiCol_Text];

			ImGui::PushStyleColor(ImGuiCol_Text, disabled_fg);
			ImGui::PushStyleColor(ImGuiCol_Button, disabled_bg);
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, disabled_bg);
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, disabled_bg);
			ImGui::Button(label, size);
			ImGui::PopStyleColor(4);

			return false;
		}
	}
}