#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UIWindowBase.h"

#include "UICreateTilePopup.h"
#include "UIImportTilePopup.h"

class UITilePickerWindow : public UIWindowBase
{
protected:
	void updateContents();

	UICreateTilePopup createTilePopup;
	UIImportTilePopup importTilePopup;

	bool ViewGrid = false;
public:
	UITilePickerWindow();
	UITilePickerWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	~UITilePickerWindow();
};

