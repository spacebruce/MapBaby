#pragma once
#include "UIPopupBase.h"

#include "UIImportTilePopup.h"
class UICreateTilePopup : public UIPopupBase
{
protected:
	void updateContents();
	void reset();
private:
	int Width;
	int Height;
	bool LockSize;

	UIImportTilePopup importTilePopup;
public:
	UICreateTilePopup();
	UICreateTilePopup(MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor);
	~UICreateTilePopup();

};