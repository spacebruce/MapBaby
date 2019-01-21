#pragma once
#include "UIPopupBase.h"

#include "TileType.h"

class UICreateTilePopup : public UIPopupBase
{
protected:
	void updateContents();
	void reset();
private:
	int Number;
	int Width;
	int Height;
	bool LockSize;

	void setTexturePattern();	//specify later
	TileType tilePreview;
public:
	UICreateTilePopup();
	UICreateTilePopup(MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor);
	~UICreateTilePopup();
};