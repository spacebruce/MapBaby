#include <stdio.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"

#include <SDL.h>
#include <SDL/SDL_opengl.h>

int main(int argCount, char * args[])
{
	// Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("Error: %s\n", SDL_GetError());
		return -1;
	}
	// Setup window
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	SDL_Window* window = SDL_CreateWindow("MapBaby", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	SDL_Delay(1000);

	SDL_DestroyWindow(window);
	return 0;
}