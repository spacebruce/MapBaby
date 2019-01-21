#pragma once
#include <string>
#include "Include/Imgui/imgui.h"

#include "UIWindowBase.h"

class UIPopupBase : public UIWindowBase
{
protected:
	char * identifier;
	bool popOpen = false;

	virtual void reset() {};
public:
	UIPopupBase(char * name, MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	UIPopupBase(char * name);
	UIPopupBase();
	virtual ~UIPopupBase();

	void open();
	void update();
};