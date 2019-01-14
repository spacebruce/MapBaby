#pragma once
#include <stdio.h>
#include <SDL.h>
#include <SDL/SDL_opengl.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"

#include "TileManager.h"
#include "MapManager.h"
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
	TileManager * tileManager;
	MapManager * mapManager;

	void selectMap(int index);

	bool ShowTilePickWindow = true;
	bool ShowViewWindow = true;
	bool ShowTabsWindow = true;
	bool ShowMapStatsWindow = true;
public:
	UserInterface(MapManager & mapManager, TileManager & tileManager, MapEditor & mapEditor);
	~UserInterface();

	void start();
	void end();
	void update();


	bool finished = false;
};