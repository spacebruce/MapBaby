#include "UserInterface.h"


UserInterface::UserInterface()
{
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
	SDL_GL_SetSwapInterval(1); // Enable vsync

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

	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame(this->window);
	ImGui::NewFrame();



	ImGui::Render();
	glViewport(0, 0, static_cast<int>(this->io->DisplaySize.x), static_cast<int>(this->io->DisplaySize.y));
	glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(this->window);
}

void UserInterface::update()
{
	render();
}