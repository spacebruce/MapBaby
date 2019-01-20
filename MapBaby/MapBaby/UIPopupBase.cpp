#include "UIPopupBase.h"

UIPopupBase::UIPopupBase(char * name, MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor) : identifier(name), UIWindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

UIPopupBase::UIPopupBase()
{
}

UIPopupBase::UIPopupBase(char * name) : identifier(name)
{
}

UIPopupBase::~UIPopupBase()
{
}

void UIPopupBase::open()
{
	this->popOpen = true;
}

void UIPopupBase::update()
{
	if (this->popOpen)
	{
		this->reset();
		ImGui::OpenPopup(identifier);
		this->popOpen = false;
	}
	this->updateContents();
}