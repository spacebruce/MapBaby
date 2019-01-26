#pragma once
#include "Include/Imgui/imgui.h"
#include "UIWindowBase.h"
#include "TileManager.h"
#include "TileType.h"

class UIImageEditor : public UIWindowBase
{
private:
	TileManager::SharedTile * tile;

	void updateContents();
public:
	UIImageEditor(TileManager::SharedTile* Tile);
	UIImageEditor();
	~UIImageEditor();
};