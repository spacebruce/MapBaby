#include "UIMapWindow.h"

UIMapWindow::UIMapWindow() : WindowBase()
{
}

UIMapWindow::UIMapWindow(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor) : WindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

UIMapWindow::~UIMapWindow()
{
}

void UIMapWindow::update()
{
	ImGui::Begin("Stats", &visible);
	Map * map = mapManager->getCurrentMap();
	if (map == nullptr)
	{
		ImGui::Text("no map open");
	}
	else
	{
		ImGui::Text("test (%i)", map->getID());
		ImGui::Separator();
		ImGui::Text("Size : %i x %i", map->getWidth(), map->getHeight());
	}
	ImGui::End();
}