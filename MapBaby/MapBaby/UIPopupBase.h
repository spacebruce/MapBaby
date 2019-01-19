#pragma once
#include <string>
#include "Include/Imgui/imgui.h"

#include "WindowBase.h"

class UIPopupBase : public WindowBase
{
protected:
	char * identifier;
	bool popOpen = false;
public:
	UIPopupBase(char * name, MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	UIPopupBase();
	virtual ~UIPopupBase();

	void open();
	void update();
};