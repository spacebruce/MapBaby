#include "WindowBase.h"

WindowBase::WindowBase(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor)
	: mapManager(mapManager), paletteManager(paletteManager), tileManager(tileManager), mapEditor(mapEditor)
{}

WindowBase::~WindowBase()
{
}

void WindowBase::selectMap(int index)
{
	mapManager->setCurrent(index);
	mapEditor->changeMap(mapManager->getMap(index));
}

void WindowBase::update()
{
	if(visible)
		this->updateContents();
}