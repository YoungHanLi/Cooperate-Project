/**
* @file     Knight.h
* @author   장하림
* @date     21/05
* @brief    나이트(Knight)
*/
#pragma once
#include "Piece.h"

class Knight :public Piece
{
public:
	Knight(int player);
	bool Move(int x0, int y0, int x1, int y1);
};
