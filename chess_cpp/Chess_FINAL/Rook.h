/**
* @file     Rook.h
* @author   이영한
* @date     21/05
* @brief    룩(Piece)
*/
#pragma once

#include "Piece.h"

class Rook : public Piece
{
public:
    Rook(int player);
    bool Move(int x0, int y0, int x1, int y1);
};
