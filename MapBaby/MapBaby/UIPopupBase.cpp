#include "UIPopupBase.h"

UIPopupBase::UIPopupBase(char * name, MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor) : identifier(name), UIWindowBase(mapManager, paletteManager, tileManager, mapEditor)
{
}

void UIPopupBase::open()
{
	this->popOpen = true;
}

UIPopupBase::UIPopupBase()
{
}


UIPopupBase::~UIPopupBase()
{
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