#include "Piece.h"
using Actors::Piece;

#include "Gizmos.h"

Piece::Piece()
{
	//will get set on init
	//set to weird values to make it clear if they havent been setup properly
	m_isKing = true;
	m_position = vec3(0);
	m_boardPos = vec2(0);
	m_color = vec4(1, 0, 0, 1);
}

Piece::~Piece()
{

}


void Piece::Update(float a_dt)
{
	
}

void Piece::Draw()
{
	if (m_isKing)
	{
		Gizmos::addCylinderFilled(m_position, 0.3f, 0.2f, 10, m_color);
	}
	else
	{
		Gizmos::addCylinderFilled(m_position, 0.3f, 0.1f, 10, m_color);
	}
	
}