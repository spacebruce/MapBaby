#include "MapEditor.h"
#include "UserInterface.h"

int main(int argCount, char * args[])
{
	MapEditor mapEditor;
	UserInterface ui(mapEditor);

	ui.start();

	while (!ui.finished)
	{
		ui.update();
	}

	ui.end();
	return 0;
}