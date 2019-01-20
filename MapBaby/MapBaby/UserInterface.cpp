#include "UserInterface.h"


UserInterface::UserInterface(MapManager& mapManager, TileManager& tileManager, PaletteManager& paletteManager, MapEditor& mapEditor)
{
	this->mapManager = &mapManager;
	this->tileManager = &tileManager;
	this->mapEditor = &mapEditor;
	this->paletteManager = &paletteManager;

	//Windows
	paletteWindow = UIPaletteWindow(&mapManager, &paletteManager, &tileManager, &mapEditor);
	mapWindow = UIMapWindow(&mapManager, &paletteManager, &tileManager, &mapEditor);
	viewWindow = UIViewWindow(&mapManager, &paletteManager, &tileManager, &mapEditor);
	tilePickerWindow = UITilePickerWindow(&mapManager, &paletteManager, &tileManager, &mapEditor);
	fileTabWindow = UIFileTabWindow(&mapManager, &paletteManager, &tileManager, &mapEditor);

	//Popups
	newFilePopup = UINewFileDialogue(&mapManager, &paletteManager, &tileManager, &mapEditor);
	aboutPopup = UIAboutPopup();

	// Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		printf("Error: %s\n", SDL_GetError());
		finished = true;
		return;
	}

	// Setup window
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	//SDL_DisplayMode current;
	//SDL_GetCurrentDisplayMode(0, &current);
	this->window = SDL_CreateWindow("MapBaby", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	this->gl_context = SDL_GL_CreateContext(this->window);
	//SDL_GL_SetSwapInterval(1); // Enable vsync

	// Setup Imgui
	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForOpenGL(this->window, this->gl_context);
	ImGui_ImplOpenGL2_Init();

	this->io = &ImGui::GetIO();
}

UserInterface::~UserInterface()
{
	SDL_GL_DeleteContext(this->gl_context);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}


void UserInterface::render()
{
	ImGui::Render();
	const int DisplayWidth = static_cast<int>(this->io->DisplaySize.x);
	const int DisplayHeight = static_cast<int>(this->io->DisplaySize.y);
	glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	mapEditor->render(DisplayWidth, DisplayHeight);

	glViewport(0, 0, DisplayWidth, DisplayHeight);
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(this->window);
}

void UserInterface::update()
{
	bool sendClick = false;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		switch(event.type)
		{
		case SDL_QUIT:
			finished = true;
			return;
		break;
		case SDL_MOUSEBUTTONDOWN:
			sendClick = true;
		break;
		}
	}

	bool updateMouse = (!this->io->WantCaptureMouse);
	mapEditor->update(this->io->DisplaySize.x, this->io->DisplaySize.y, updateMouse);

	if (updateMouse)
	{
		if (sendClick)
		{
			mapEditor->click();
		}
	}

	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame(this->window);
	ImGui::NewFrame();

	updateWindows();

	render();
}

void UserInterface::selectMap(int index)
{
	mapManager->setCurrent(index);
	mapEditor->changeMap(mapManager->getMap(index));
}

void UserInterface::updateWindows()
{
	//Menu bar
	if (ImGui::BeginMainMenuBar())
	{
		//Files
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("New map"))
			{
				newFilePopup.open();
			}
			if (ImGui::MenuItem("Load map")) {};
			if (ImGui::MenuItem("Save map")) {};
			ImGui::Separator();
			if (ImGui::MenuItem("Quit"))
			{
				finished = true;
			}
			ImGui::EndMenu();
		}
		//Tabs
		if (ImGui::BeginMenu("Tabs", (mapManager->getCount() != 0)))
		{
			for (auto i = 0; i < mapManager->getCount(); ++i)
			{
				if (ImGui::MenuItem("test", nullptr, mapManager->isCurrent(i)))
				{
					selectMap(i);
				}
			}
			ImGui::EndMenu();
		}
		//Windows
		if (ImGui::BeginMenu("Windows"))
		{
			if (ImGui::MenuItem("Tabs", nullptr, fileTabWindow.visible))	{ fileTabWindow.visible = !fileTabWindow.visible;	}
			if (ImGui::MenuItem("Tiles", nullptr, tilePickerWindow.visible)) { tilePickerWindow.visible = !tilePickerWindow.visible; }
			if (ImGui::MenuItem("Palette", nullptr, paletteWindow.visible)) { paletteWindow.visible = !paletteWindow.visible; }
			if (ImGui::MenuItem("Map Stats", nullptr, mapWindow.visible))	{	mapWindow.visible = !mapWindow.visible;	}
			if (ImGui::MenuItem("View", nullptr, viewWindow.visible)) { viewWindow.visible = !viewWindow.visible; }
			ImGui::EndMenu();
		}
		//Help
		if (ImGui::BeginMenu("Help"))
		{
			if (ImGui::MenuItem("About"))
			{
				aboutPopup.open();
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	//Windows
	fileTabWindow.update();
	viewWindow.update();
	mapWindow.update();
	tilePickerWindow.update();
	paletteWindow.update();

	//Popups
	newFilePopup.update();
	aboutPopup.update();
}