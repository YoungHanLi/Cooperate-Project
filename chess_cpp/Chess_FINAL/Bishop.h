/**
* @file     Bishop.h
* @author   김나영
* @date     21/05
* @brief    비숍(Bishop)
*/
#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(unsigned int player);
	bool Move(int x0, int y0, int x1, int y1);
};
