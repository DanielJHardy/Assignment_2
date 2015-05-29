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



}
void Checkers::Draw()
{

}
