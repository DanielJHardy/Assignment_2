#ifndef _CHECKERS_H_
#define _CHECKERS_H_

#include <vector>

#include "Game.h"

#include "Board.h"

enum GameStates
{
	MENU,
	LOBBY,
	PLAYING,
	END
};

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
		bool menu_Update(float a_dt);
		bool lobby_Update(float a_dt);
		bool playing_Update(float a_dt);
		bool end_Update(float a_dt);

		void menu_Draw();
		void lobby_Draw();
		void playing_Draw();
		void end_Draw();

	private:
		//board
		Actors::Board m_board;

		//game state
		GameStates m_gameState;

	};

}

#endif // !_CHECKERS_H_
