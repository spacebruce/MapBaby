#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UIWindowBase.h"

#include "UINewFileDialogue.h"

class UIFileTabWindow :	public UIWindowBase
{
protected:
	void updateContents();
	UINewFileDialogue newFilePopup;
public:
	UIFileTabWindow();
	UIFileTabWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor);
	~UIFileTabWindow();
};

