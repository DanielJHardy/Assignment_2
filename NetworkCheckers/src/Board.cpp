#include "Board.h"

using Actors::Board;

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
	//load board mesh

	//create pieces
}

void Board::Update(float a_dt)
{
	//update pieces
}

void Board::Draw()
{
	//draw board

	//draw pieces
}