#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UIWindowBase.h"


class UIViewWindow : public UIWindowBase
{
protected:
	void updateContents();
public:
	UIViewWindow();
	UIViewWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	~UIViewWindow();
};

