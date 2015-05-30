#ifndef _BOARD_H_
#define _BOARD_H_

#include <vector>

#include "BufferData.h"
#include "Piece.h"

namespace Actors
{
	class Board
	{
	public:
		Board();
		~Board();

		void Init();
		void Update(float a_dt);
		void Draw();

	private:
		//model data
		Rendering::BufferData m_mesh;

		//board properties
		unsigned int m_X_spaces;
		unsigned int m_Y_spaces;

		float m_tile_width;	//distance between tiles

		//pieces
		std::vector<Piece> m_black_pieces;
		std::vector<Piece> m_white_pieces;


	};
}

#endif // !_BOARD__H
