#pragma once
#include "Include/Imgui/imgui.h"
#include "Include/Imgui/imgui_stdlib.h"

#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UIPopupBase.h"

class UINewFileDialogue : public UIPopupBase
{
protected:
	void updateContents();
	void reset();
private:
	std::uint32_t width, height;
	std::string name;
public:
	UINewFileDialogue();
	UINewFileDialogue(MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor);
	~UINewFileDialogue();
};