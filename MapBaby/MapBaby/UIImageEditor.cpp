#include "UIImageEditor.h"

UIImageEditor::UIImageEditor(PaletteManager * paletteManager, TileManager::SharedTile tile) : UIWindowBase(nullptr,paletteManager,nullptr,nullptr)
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
		Palette palette = paletteManager->getCurrentPalette();
		ImGui::Text(palette.name.c_str());
		ImGui::BeginChild("Pal area");
		for (std::size_t i = 0; i < palette.getSize(); ++i)
		{
			ColourRGB col = palette.getEntry(i);
			ImVec4 colvec = ImVec4(col.r / 255.0f, col.g / 255.0f, col.b / 255.0f, 1.0);
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, colvec);
			ImGui::PushStyleColor(ImGuiCol_Button, colvec);
			ImGui::SmallButton(" ");
			ImGui::PopStyleColor(2);
			ImGui::SameLine();
		}
		ImGui::EndChild();
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


	ImGui::EndChild();

	ImGui::Separator();
	ImGui::Text("Status bar??");
	
	ImGui::End();
}

void UIImageEditor::imageView()
{

	ImGui::Image((void*)tile.get()->texture.get(), ImVec2(256, 256));
}