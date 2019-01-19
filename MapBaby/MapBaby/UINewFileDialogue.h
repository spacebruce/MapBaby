#pragma once
#include "Include/Imgui/imgui.h"
#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UIPopupBase.h"

class UINewFileDialogue : public UIPopupBase
{
protected:
	void updateContents();
public:
	UINewFileDialogue();
	UINewFileDialogue(MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor);
	~UINewFileDialogue();
};