#pragma once
#include "Include/Imgui/imgui.h"
#include "Include/Imgui/imgui_stdlib.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UIWindowBase.h"

class UIPaletteWindow :	public UIWindowBase
{
protected:
	void updateContents();
public:
	~UIPaletteWindow(); 
	UIPaletteWindow::UIPaletteWindow();
	UIPaletteWindow::UIPaletteWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
};