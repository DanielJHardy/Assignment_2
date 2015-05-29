#ifndef _CHECKERS_H_
#define _CHECKERS_H_

#include <vector>

#include "Game.h"


namespace Games
{
	class Checkers : public Game
	{
	public:
		Checkers();
		~Checkers();

		virtual bool Startup();
		virtual void Shutdown();

		virtual bool Update(float a_dt);
		virtual void Draw();

	private:

		//board

		//vector of black pieces
		//vector of white pieces

	};

}

#endif // !_CHECKERS_H_
