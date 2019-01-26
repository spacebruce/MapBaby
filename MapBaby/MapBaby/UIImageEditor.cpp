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
	ImGui::End();
}