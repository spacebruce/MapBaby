#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "WindowBase.h"


class UIViewWindow : public WindowBase
{
protected:
	void updateContents();
public:
	UIViewWindow();
	UIViewWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	~UIViewWindow();
};

