#include "UIImageEditor.h"

UIImageEditor::UIImageEditor(TileManager::SharedTile* tile)
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
	ImGui::End();
}