#pragma once
#include <stdio.h>
#include <SDL.h>
#include <SDL/SDL_opengl.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"

class UserInterface
{
private:
	SDL_Window* window;
	SDL_GLContext gl_context;
	ImGuiIO* io;
public:
	UserInterface();
	~UserInterface();
	void start();
	void end();
	void render();

	bool finished = false;
};