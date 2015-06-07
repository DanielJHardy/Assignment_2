#include "Board.h"
using Actors::Board;

#include "Gizmos.h"

const vec4 black = vec4(0.2f, 0.2f, 0.2f,1.0f);
const vec4 white = vec4(0.8f, 0.8f, 0.8f, 1.0f);

Board::Board()
{
	//default values
	m_tile_width = 300;

	m_X_spaces = 8;
	m_Y_spaces = 8;

	m_white_pieces = std::vector<Piece>();
	m_black_pieces = std::vector<Piece>();

}

Board::~Board()
{

}

void Board::Init()
{
	//create pieces
	Piece temp = Piece();

	unsigned int num_pieces_per_side = unsigned int(m_X_spaces * 1.5f);

	//black
	//set properties that are the same for all pieces
	temp.m_isKing = false;
	temp.m_color = black + vec4(0.1f, 0.1f, 0.1f,0);

	for (unsigned int i = 0; i < num_pieces_per_side*2; i += 2)
	{
		//set properties that change per piece
		temp.m_boardPos.y = float(i / m_X_spaces);
		temp.m_boardPos.x = float(i % m_X_spaces);

		//alternate starting tile to stay diagonal
		if (int(temp.m_boardPos.y) % 2 != 0)
			temp.m_boardPos.x += 1;

		temp.m_position.x = temp.m_boardPos.x;
		temp.m_position.z = temp.m_boardPos.y;

		//push
		m_black_pieces.push_back(temp);
	}

	//white
	//side specific properties
	temp.m_color = white - vec4(0.1f, 0.1f, 0.1f, 0);

	for (unsigned int i = 0; i < num_pieces_per_side * 2; i += 2)
	{
		//per piece properties
		temp.m_boardPos.y = (m_Y_spaces-1) - float(i / m_X_spaces);
		temp.m_boardPos.x = (m_X_spaces-1) - float(i % m_X_spaces);

		//alternate starting tile to stay diagonal
		if (int(temp.m_boardPos.y) % 2 == 0)
			temp.m_boardPos.x -= 1;

		temp.m_position.x = temp.m_boardPos.x;
		temp.m_position.z = temp.m_boardPos.y;

		//push
		m_white_pieces.push_back(temp);
	}
}

void Board::Update(float a_dt)
{
	//update pieces

	//black pieces
	for (unsigned int i = 0; i < m_black_pieces.size(); i++)
	{
		m_black_pieces[i].Update(a_dt);
	}

	//white pieces
	for (unsigned int i = 0; i < m_white_pieces.size(); i++)
	{
		m_white_pieces[i].Update(a_dt);
	}
}

void Board::Draw()
{
	//draw board
	vec4 tileColor = black;
	unsigned int bob = 0;

	for (unsigned int y = 0; y < m_Y_spaces; y++)
	{
		for (unsigned int x = 0; x < m_X_spaces; x++)
		{
			bob++;
			Gizmos::addAABBFilled(vec3(x , -0.2f, y ), vec3(0.5f,0.2f, 0.5f), tileColor);

			//toggle color
			if (tileColor == black) tileColor = white; else tileColor = black;
		}
		//toggle color
		if (tileColor == black) tileColor = white; else tileColor = black;
	}


	//draw pieces
	
	//black pieces
	for (unsigned int i = 0; i < m_black_pieces.size(); i++)
	{
		m_black_pieces[i].Draw();
	}

	//white pieces
	for (unsigned int i = 0; i < m_white_pieces.size(); i++)
	{
		m_white_pieces[i].Draw();
	}
}