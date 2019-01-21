#pragma once
#include "UIPopupBase.h"

class UIImportTilePopup :	public UIPopupBase
{
protected:
	void reset();
public:
	UIImportTilePopup();
	~UIImportTilePopup();

	void updateContents();
};