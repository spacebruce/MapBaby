#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "WindowBase.h"

class UIPaletteWindow :	public WindowBase
{
public:
	~UIPaletteWindow(); 
	UIPaletteWindow::UIPaletteWindow(MapManager & mapManager, PaletteManager & paletteManager, TileManager & tileManager, MapEditor & mapEditor);

	void update();
};