/**
* @file     Queen.h
* @author   김나영
* @date     21/05
* @brief    퀸(Queen)
*/
#pragma once

#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(int player);
	bool Move(int x0, int y0, int x1, int y1);
};
