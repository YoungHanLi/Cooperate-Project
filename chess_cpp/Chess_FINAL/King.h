/**
* @file     King.h
* @author   장하림
* @date     21/05
* @brief    킹(King)
*/
#pragma once
#include "Piece.h"

class King : public Piece
{
private:
 	bool first = true;
public:
	King(int player);
	bool Move(int x0, int y0, int x1, int y1);
	
	friend class ChessBoard;
};
