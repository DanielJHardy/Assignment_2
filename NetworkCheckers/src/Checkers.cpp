#include "Checkers.h"

using Games::Checkers;

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

}
void Checkers::Shutdown()
{
	//call base's Shutdown
	Game::Shutdown();
}

bool Checkers::Update(float a_dt)
{
	//call base's update
	if (Game::Update(a_dt) == false)
		return false;

	//update based on gamestate
	switch (m_gameState)
	{
	case MENU:
		menu_Update(a_dt);
		break;
	case LOBBY:
		lobby_Update(a_dt);
		break;
	case PLAYING:
		playing_Update(a_dt);
		break;
	case END:
		end_Update(a_dt);
		break;
	default:
		printf("wtf, this gamestate doesnt exist");
		break;
	}

}
void Checkers::Draw()
{

}


//			game states

bool Checkers::menu_Update(float a_dt)
{

}

bool Checkers::lobby_Update(float a_dt)
{

}

bool Checkers::playing_Update(float a_dt)
{

}

bool Checkers::end_Update(float a_dt)
{

}

void Checkers::menu_Draw()
{

}

void Checkers::lobby_Draw()
{

}

void Checkers::playing_Draw()
{

}

void Checkers::end_Draw()
{

}
