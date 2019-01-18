#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "WindowBase.h"

class UIFileTabWindow :	public WindowBase
{
public:
	UIFileTabWindow();
	UIFileTabWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	~UIFileTabWindow();
	void update();
};

