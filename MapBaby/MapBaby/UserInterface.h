#pragma once
#include <stdio.h>
#include <SDL.h>
#include <SDL/SDL_opengl.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"

#include "MapEditor.h"

class UserInterface
{
private:
	SDL_Window* window;
	SDL_GLContext gl_context;
	ImGuiIO* io;

	void render();
	void updateWindows();

	MapEditor* mapEditor;
public:
	UserInterface(MapEditor & mapEditor);
	~UserInterface();

	void start();
	void end();
	void update();

	bool finished = false;
};