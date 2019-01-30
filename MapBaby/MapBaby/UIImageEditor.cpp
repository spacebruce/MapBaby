#include "UIImageEditor.h"

UIImageEditor::UIImageEditor(TileManager::SharedTile tile)
{
	this->tile = tile;
}

UIImageEditor::UIImageEditor()
{
}

UIImageEditor::~UIImageEditor()
{
}

void UIImageEditor::updateContents()
{
	ImGui::Begin("Image editor", &visible);
	ImGui::Text("Tile ID %i", tile.get()->getID());
	ImGui::Text("Texture %i", tile.get()->texture.get());

	ImGui::Separator();

	const float footer_height_to_reserve = ImGui::GetFrameHeightWithSpacing(); // 1 separator, 1 input text
	ImGui::BeginChild("Body", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar); // Leave room for 1 separator + 1 InputText
	
	ImGui::Columns(2, nullptr, true);

	//Tools and stuff
	if (ImGui::CollapsingHeader("Palette"))
	{
		//draw palette here
	}
	
	if (ImGui::CollapsingHeader("Tools"))
	{
		//buttons!!
	}
	
	if (ImGui::CollapsingHeader("Settings"))
	{
		//Tool settings and view and stuff!
	}

	//Image area
	ImGui::NextColumn();

	ImGui::Image((void*)tile.get()->texture.get(), ImVec2(256, 256));

	ImGui::EndChild();

	ImGui::Separator();
	ImGui::Text("Status bar??");
	
	ImGui::End();
}