#ifndef _GAME_H_
#define _GAME_H_

#include "glm_usings.h"

struct GLFWwindow;

namespace Games
{

	class Game
	{
	public:
		Game();
		~Game();

		virtual bool Startup();
		virtual void Shutdown();

		virtual bool Update(float a_dt);
		virtual void Draw() = 0;


	public:
		GLFWwindow* m_window;

	protected:
		char* m_title;
		unsigned int m_screenWidth;
		unsigned int m_screenHeight;

	};

}

#endif // !_GAME_H_
