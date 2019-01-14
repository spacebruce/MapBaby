#include "MapEditor.h"
#include "MapManager.h"
#include "TileManager.h"
#include "UserInterface.h"

int main(int argCount, char * args[])
{
	MapEditor mapEditor;
	MapManager mapManager;
	TileManager tileManager;
	UserInterface ui(mapManager, tileManager, mapEditor);

	ui.start();

	while (!ui.finished)
	{
		ui.update();
	}

	ui.end();
	return 0;
}