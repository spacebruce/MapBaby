#pragma once
#include <string>
#include "Include/Imgui/imgui.h"

#include "WindowBase.h"

class UIPopupBase : public WindowBase
{
protected:
	std::string identifier = "";
	bool popOpen = false;
public:
	UIPopupBase(std::string name, MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	UIPopupBase();
	virtual ~UIPopupBase();

	void open();
	void update();
};