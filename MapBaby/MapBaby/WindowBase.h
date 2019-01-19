#pragma once

#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"

class WindowBase
{
protected:
	MapManager* mapManager;
	PaletteManager* paletteManager;
	TileManager* tileManager;
	MapEditor* mapEditor;

	virtual void updateContents() = 0;

	//helper functions
	void selectMap(int index);
public:
	bool visible = true;
	WindowBase() = default;
	WindowBase(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	virtual ~WindowBase();

	virtual void update();
};