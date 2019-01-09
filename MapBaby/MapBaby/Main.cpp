
#include <stdio.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"

#include <SDL.h>
#include <SDL/SDL_opengl.h>

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