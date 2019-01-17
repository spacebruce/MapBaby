#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "PaletteManager.h"
#include "UserInterface.h"

int main(int argCount, char * args[])
{
	MapManager mapManager;
	TileManager tileManager;
	PaletteManager paletteManager;
	
	MapEditor mapEditor(tileManager);
	UserInterface ui(mapManager, tileManager, paletteManager, mapEditor);

	ui.start();

	while (!ui.finished)
	{
		ui.update();
	}

	ui.end();
	return 0;
}