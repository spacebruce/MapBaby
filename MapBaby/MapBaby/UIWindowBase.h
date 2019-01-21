#pragma once

#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"

class UIWindowBase
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
	UIWindowBase() = default;
	UIWindowBase(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	virtual ~UIWindowBase();

	virtual void update();
};