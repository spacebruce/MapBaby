#include "UIWindowBase.h"

UIWindowBase::UIWindowBase(MapManager *mapManager, PaletteManager *paletteManager, TileManager *tileManager, MapEditor *mapEditor)
	: mapManager(mapManager), paletteManager(paletteManager), tileManager(tileManager), mapEditor(mapEditor)
{}

UIWindowBase::~UIWindowBase()
{
}

void UIWindowBase::selectMap(int index)
{
	mapManager->setCurrent(index);
	mapEditor->changeMap(mapManager->getMap(index));
}

void UIWindowBase::update()
{
	if(visible)
		this->updateContents();
}