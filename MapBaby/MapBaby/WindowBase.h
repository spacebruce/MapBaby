#pragma once

#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"

class WindowBase
{
private:
	MapManager* mapManager;
	PaletteManager* paletteManager;
	TileManager* tileManager;
	MapEditor* mapEditor;
public:
	bool visible = true;
	WindowBase(MapManager &mapManager, PaletteManager &paletteManager, TileManager &tileManager, MapEditor &mapEditor);
	virtual ~WindowBase();
};