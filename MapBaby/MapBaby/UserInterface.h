#pragma once
#include <stdio.h>
#include <string>
#include <SDL.h>
#include <SDL/SDL_opengl.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl2.h"

#include "TileManager.h"
#include "MapManager.h"
#include "PaletteManager.h"
#include "MapEditor.h"

#include "UIPaletteWindow.h"
#include "UIMapWindow.h"
#include "UIViewWindow.h"
#include "UITilePickerWindow.h"
#include "UIFileTabWindow.h"

class UserInterface
{
private:
	SDL_Window* window;
	SDL_GLContext gl_context;
	ImGuiIO* io;

	void render();
	void updateWindows();

	void selectMap(int index);

	MapManager* mapManager;
	PaletteManager* paletteManager;
	TileManager* tileManager;
	MapEditor* mapEditor;

	//Windows
	UIPaletteWindow paletteWindow;
	UIMapWindow mapWindow;
	UIViewWindow viewWindow;
	UITilePickerWindow tilePickerWindow;
	UIFileTabWindow fileTabWindow;

public:
	UserInterface(MapManager& mapManager, TileManager& tileManager, PaletteManager& paletteManager, MapEditor& mapEditor);
	~UserInterface();

	void update();

	bool finished = false;
};