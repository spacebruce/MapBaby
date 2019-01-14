#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "UserInterface.h"

int main(int argCount, char * args[])
{
	MapManager mapManager;
	TileManager tileManager;
	
	MapEditor mapEditor(tileManager);
	UserInterface ui(mapManager, tileManager, mapEditor);

	ui.start();

	while (!ui.finished)
	{
		ui.update();
	}

	ui.end();
	return 0;
}