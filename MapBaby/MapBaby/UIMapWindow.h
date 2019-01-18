#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "WindowBase.h"

class UIMapWindow :	public WindowBase
{
protected:
	void updateContents();
public:
	UIMapWindow();
	UIMapWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	~UIMapWindow();
};

