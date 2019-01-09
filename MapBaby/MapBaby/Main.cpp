#include "UserInterface.h"

int main(int argCount, char * args[])
{
	UserInterface ui;
	ui.start();

	while (!ui.finished)
	{
		ui.update();
	}

	ui.end();
	return 0;
}