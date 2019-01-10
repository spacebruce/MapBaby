#include "MapEditor.h"
#include "MapManager.h"
#include "UserInterface.h"

int main(int argCount, char * args[])
{
	MapEditor mapEditor;
	MapManager mapManager;
	UserInterface ui(mapManager, mapEditor);

	ui.start();

	while (!ui.finished)
	{
		ui.update();
	}

	ui.end();
	return 0;
}