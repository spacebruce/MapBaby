#include "UIMapWindow.h"

UIMapWindow::UIMapWindow() : UIWindowBase()
{
}

UIMapWindow::UIMapWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : UIWindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

UIMapWindow::~UIMapWindow()
{
}

void UIMapWindow::updateContents()
{
	ImGui::Begin("Stats", &visible);
	Map * map = mapManager->getCurrentMap();
	if (map == nullptr)
	{
		ImGui::Text("no map open");
	}
	else
	{
		ImGui::Text("%s (%i)", map->name.c_str(), map->getID());
		ImGui::Separator();
		ImGui::Text("Size : %i x %i", map->getWidth(), map->getHeight());
	}
	ImGui::End();
}