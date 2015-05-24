#include "Game.h"

#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"

#include <cstdio>

using Games::Game;

Game::Game()
{
	//default values
	m_title = "DEFAULT TITLE";
	m_screenWidth = 1280;
	m_screenHeight = 720;
}

Game::~Game(){}

bool Game::Startup()
{
	//load GLFW
	if (glfwInit() == 0)
		return false;

	//create a window
	m_window = glfwCreateWindow(m_screenWidth, m_screenHeight, m_title, nullptr, nullptr);

	//check for window creation failure
	if (m_window == nullptr)
		return false;

	//set the window to the current
	glfwMakeContextCurrent(m_window);

	//load OpenGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED)
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return false;
	}

	int major_version = ogl_GetMajorVersion();
	int minor_version = ogl_GetMinorVersion();

	printf("Successfully loaded OpenGL version %i.%i\n", major_version, minor_version);

	return true;
}

void Game::Shutdown()
{
	glfwDestroyWindow(this->m_window);
	glfwTerminate();
}

bool Game::Update(float a_dt)
{
	//If the player clicks the x to close (or the likes)
	if (glfwWindowShouldClose(this->m_window))
		return false;

	return true; // should continue to update
}

