#include "Checkers.h"

#include <GLFW/glfw3.h>

int main()
{
	Games::Checkers game;			//game instance

	//set window properties
	game.m_title = "Checkers";
	game.m_screenWidth = 1280;
	game.m_screenHeight = 720;
	
	//Start game
	if (game.Startup() == false)
		return -1;
	
	float deltaTime;				//Time between update calls
	bool shouldContinue = true;		//should the game continue to run?
	
	//setup delta time calculations
	glfwSetTime(0.0);
	
	//update and draw game while shouldn't quit
	while (shouldContinue)
	{
		//calculate delta time
		deltaTime = (float)glfwGetTime();
		glfwSetTime(0.0);
	
		//Update 
		shouldContinue = game.Update(deltaTime);
	
		//draw
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		game.Draw();

		glfwSwapBuffers(game.m_window);
		glfwPollEvents();
	}
}