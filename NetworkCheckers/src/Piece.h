#ifndef _PIECE_H_
#define _PIECE_H_

#include "glm_usings.h"
#include "BufferData.h"


class Piece
{
public:
	Piece();
	~Piece();

	void Init();
	void Update(float a_dt);
	void Draw();

private:
	mat4 m_world;	//world transform
	bool m_isKing;	//whether piece is a king

	Rendering::BufferData m_mesh;
};


#endif // !_PIECE_H_
