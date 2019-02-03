#pragma once
#include "Include/Imgui/imgui.h"
#include "UIWindowBase.h"
#include "TileManager.h"
#include "TileType.h"

class UIImageEditor : public UIWindowBase
{
private:
	TileManager::SharedTile tile;

	void updateContents();
	void imageView();
public:
	UIImageEditor(PaletteManager * paletteManager, TileManager::SharedTile tile);
	UIImageEditor(TileManager::SharedTile tile);
	UIImageEditor();
	~UIImageEditor();
};