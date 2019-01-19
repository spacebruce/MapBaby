#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UIWindowBase.h"

#include "UICreateTilePopup.h"

class UITilePickerWindow : public UIWindowBase
{
protected:
	void updateContents();

	UICreateTilePopup createTilePopup;
public:
	UITilePickerWindow();
	UITilePickerWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	~UITilePickerWindow();
};

