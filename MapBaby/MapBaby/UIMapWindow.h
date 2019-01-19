#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UIWindowBase.h"

class UIMapWindow :	public UIWindowBase
{
protected:
	void updateContents();
public:
	UIMapWindow();
	UIMapWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	~UIMapWindow();
};

