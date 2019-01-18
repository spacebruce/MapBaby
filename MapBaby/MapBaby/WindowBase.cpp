#include "WindowBase.h"

WindowBase::WindowBase(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor)
	: mapManager(mapManager), paletteManager(paletteManager), tileManager(tileManager), mapEditor(mapEditor)
{}

WindowBase::~WindowBase()
{
}
