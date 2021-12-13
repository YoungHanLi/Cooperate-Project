/**
* @file     Pawn.h
* @author   이영한
* @date     21/05
* @brief    firstMove : 폰이 첫 이동인지 판단 (2칸 이동 가능)
*/
#pragma once
#include "Piece.h"

class Pawn : public Piece
{
private:
    bool firstMove=true;
public:
    Pawn(int player);
    bool Move(int x0, int y0, int x1, int y1);
    
    friend class ChessBoard;
};
