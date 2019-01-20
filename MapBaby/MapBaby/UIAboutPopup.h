#pragma once
#include "UIPopupBase.h"

class UIAboutPopup : public UIPopupBase
{
public:
	UIAboutPopup();
	//UIAboutPopup(MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor);
	~UIAboutPopup();

	void updateContents();
};

