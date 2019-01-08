#include <stdio.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"

#include <SDL.h>
#include <SDL/SDL_opengl.h>

int main(int argCount, char * args[])
{
	SDL_Window * window = SDL_CreateWindow("SDL!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400, SDL_WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI);
	// Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("Error: %s\n", SDL_GetError());
		return -1;
	}

	SDL_Delay(1000);

	SDL_DestroyWindow(window);
	return 0;
}