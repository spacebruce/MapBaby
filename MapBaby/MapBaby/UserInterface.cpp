#include "UserInterface.h"


UserInterface::UserInterface(MapManager& mapManager, MapEditor& mapEditor)
{
	this->mapManager = &mapManager;
	this->mapEditor = &mapEditor;
}

UserInterface::~UserInterface()
{
}

void UserInterface::start()
{
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
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	this->window = SDL_CreateWindow("MapBaby", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	this->gl_context = SDL_GL_CreateContext(this->window);
	//SDL_GL_SetSwapInterval(1); // Enable vsync

	// Setup Imgui
	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForOpenGL(this->window, this->gl_context);
	ImGui_ImplOpenGL2_Init();

	this->io = &ImGui::GetIO();
}

void UserInterface::end()
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
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL2_ProcessEvent(&event);
		if (event.type == SDL_QUIT)
		{
			finished = true;
			return;
		}
	}

	mapEditor->update(this->io->DisplaySize.x, this->io->DisplaySize.y);

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
	//main bar
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("New map"))
			{
				mapManager->newMap();
				selectMap(mapManager->getCount() - 1);
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

		if (mapManager->getCount() > 0)
		{
			if (ImGui::BeginMenu("Tabs"))
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
		}

		if (ImGui::BeginMenu("Windows"))
		{
			if (ImGui::MenuItem("Tabs", nullptr, ShowTabsWindow))	{ ShowTabsWindow = !ShowTabsWindow;	}
			if (ImGui::MenuItem("Map Stats", nullptr, ShowMapStatsWindow))	{	ShowMapStatsWindow = !ShowMapStatsWindow;	}
			if (ImGui::MenuItem("View", nullptr, ShowViewWindow)) {	ShowViewWindow = !ShowViewWindow; }
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}

	//View window
	if (ShowViewWindow)
	{
		ImGui::Begin("View", &ShowViewWindow, ImGuiWindowFlags_AlwaysAutoResize);


		if (ImGui::CollapsingHeader("Debug"))
		{
			ImGui::Text("mouse x : %f", mapEditor->camera.getMouseX());
			ImGui::Text("mouse y : %f", mapEditor->camera.getMouseY());

			auto cameraBox = mapEditor->camera.getBox();
			ImGui::Text("cam l %f", cameraBox.left);
			ImGui::Text("cam r %f", cameraBox.right);
			ImGui::Text("cam t %f", cameraBox.top);
			ImGui::Text("cam b %f", cameraBox.bottom);
		}

		//Position
		if (ImGui::CollapsingHeader("Position"))
		{
			ImGui::DragInt("x", &(mapEditor->camera.x));
			ImGui::DragInt("y", &(mapEditor->camera.y));
		}

		//Zoom
		if (ImGui::CollapsingHeader("Zoom"))
		{
			ImGui::SliderFloat("###Zoom", &(mapEditor->camera.zoom), 1.0f, 1000.0f, "%.1f", 2.0f);
			ImGui::SameLine();
			if (ImGui::Button("-"))
			{
				mapEditor->camera.zoom -= 50.0f;
			}
			ImGui::SameLine();
			if (ImGui::Button("+"))
			{
				mapEditor->camera.zoom += 50.0f;
			}
			ImGui::SameLine();
			if (ImGui::Button("100%"))
			{
				mapEditor->camera.zoom = 100.0f;
			}
		}

		ImGui::End();
	}

	//File window
	if(ShowTabsWindow)
	{
		ImGui::Begin("Tabs", &ShowTabsWindow, ImGuiWindowFlags_AlwaysAutoResize);

		ImGui::Text("Current : %i", mapManager->getCurrent());

		if (ImGui::Button("-"))
		{
			mapManager->deselect();
			mapEditor->changeMap(nullptr);
		}
		ImGui::SameLine();

		for (auto i = 0; i < mapManager->getCount(); ++i)
		{
			ImGui::PushID(reinterpret_cast<int>(mapManager->getMap(i)));

			if (mapManager->isCurrent(i))
			{
				ImGui::Text("test");
			}
			else if (ImGui::Button("test"))
			{
				mapManager->setCurrent(i);
				mapEditor->changeMap(mapManager->getMap(i));
			}
			ImGui::SameLine(); 
			if (ImGui::Button("x"))
			{
				if (mapManager->getCurrent() == i)
				{
					mapEditor->changeMap(nullptr);
				}
				mapManager->closeMap(i);
			}
			ImGui::SameLine();

			ImGui::PopID();
		}
		if(ImGui::Button("+"))
		{
			mapManager->newMap(Map(0,0));
			selectMap(mapManager->getCount() - 1);
		}
		ImGui::End();
	}

	//Map stats
	if (ShowMapStatsWindow)
	{
		ImGui::Begin("Stats", &ShowMapStatsWindow);
		Map * map = mapManager->getCurrentMap();
		if (map == nullptr)
		{
			ImGui::Text("no map open");
		}
		else
		{
			
			ImGui::Text("test (%i)", map->getID());
			ImGui::Separator();
			ImGui::Text("Size : %i x %i", map->getWidth(), map->getHeight());
		}
		ImGui::End();
	}

	ImGui::Render();

}