#include "Checkers.h"
using Games::Checkers;

#include "gl_core_4_4.h"
#include "glm_usings.h"
#include <GLFW/glfw3.h>

#include "Gizmos.h"

Checkers::Checkers()
{

}
Checkers::~Checkers()
{

}

bool Checkers::Startup()
{
	//call base's Startup
	if (Game::Startup() == false)
		return false;

	//set gamestate
	m_gameState = GameStates::PLAYING;

	//set background color
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	//setup camera
	m_cam = FlyCamera(glm::radians(60.0f));
	m_cam.setLookAt(vec3(5, 5, 5), vec3(0, 0, 0), vec3(0, 1, 0));

	//init board
	m_board.Init();

	//init gizmos
	Gizmos::create();

	return true;
}
void Checkers::Shutdown()
{
	//call base's Shutdown
	Game::Shutdown();

	//shutdown Gizmos
	Gizmos::destroy();
}

bool Checkers::Update(float a_dt)
{
	//call base's update
	if (Game::Update(a_dt) == false)
		return false;

	//clear gizmos
	Gizmos::clear();

	Gizmos::addTransform(mat4(1));

	//update camera
	m_cam.Update(a_dt);

	//update based on gamestate
	switch (m_gameState)
	{
	case MENU:
		return menu_Update(a_dt);
		break;
	case LOBBY:
		return lobby_Update(a_dt);
		break;
	case PLAYING:
		return playing_Update(a_dt);
		break;
	case END:
		return end_Update(a_dt);
		break;
	default:
		printf("wtf, this gamestate doesn't exist");
		break;
	}

	return false;

}
void Checkers::Draw()
{

	//render based on gamestate
	switch (m_gameState)
	{
	case MENU:
		menu_Draw();
		break;
	case LOBBY:
		lobby_Draw();
		break;
	case PLAYING:
		playing_Draw();
		break;
	case END:
		end_Draw();
		break;
	default:
		printf("gamestate to render doesnt exist");
		break;
	}

	//draw Gizmos
	Gizmos::draw(m_cam.getProjectionView());
}


//			game states

bool Checkers::menu_Update(float a_dt)
{
	return true;
}

bool Checkers::lobby_Update(float a_dt)
{
	return true;
}

bool Checkers::playing_Update(float a_dt)
{
	m_board.Update(a_dt);

	return true;
}

bool Checkers::end_Update(float a_dt)
{
	return true;
}

void Checkers::menu_Draw()
{
	
}

void Checkers::lobby_Draw()
{

}

void Checkers::playing_Draw()
{
	m_board.Draw();
}

void Checkers::end_Draw()
{

}
