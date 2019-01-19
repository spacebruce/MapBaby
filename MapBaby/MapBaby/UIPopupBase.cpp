#include "UIPopupBase.h"



UIPopupBase::UIPopupBase(std::string name, MapManager * mapManager, PaletteManager * paletteManager, TileManager * tileManager, MapEditor * mapEditor) : identifier(name), WindowBase(mapManager, paletteManager, tileManager, mapEditor)
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
		ImGui::OpenPopup(this->identifier.c_str());
		this->popOpen = false;
	}
	this->updateContents();
}