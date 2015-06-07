#ifndef _PIECE_H_
#define _PIECE_H_

#include "glm_usings.h"
#include "BufferData.h"

enum Team
{
	Black,
	White
};

namespace Actors
{
	class Piece
	{
	public:
		Piece();
		~Piece();

		void Update(float a_dt);
		void Draw();

	public:
		vec3 m_position;
		vec4 m_color;

		vec2 m_boardPos;	//tile on top of

		bool m_isKing;	//whether piece is a king
	};
}


#endif // !_PIECE_H_
