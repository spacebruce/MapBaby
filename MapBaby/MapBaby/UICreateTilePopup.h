#pragma once
#include "UIPopupBase.h"

class UICreateTilePopup : public UIPopupBase
{
protected:
	void updateContents();
	void reset();
public:
	UICreateTilePopup();
	UICreateTilePopup(MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor);
	~UICreateTilePopup();

};

