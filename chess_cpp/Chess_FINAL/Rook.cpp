/**
* @file     Rook.cpp
* @author   이영한
* @date     21/05
*/

#include "Rook.h"

/**
* @brief    Move
* @detail   Rook의 이동 함수
*           조건1[x0==x1] : y축 방향(세로) 일직선 이동 
*           조건2[y0==y1] : x축 방향(가로) 일직선 이동
* @param    x0, y0 : 기존 말의 위치 
*           x1, y1 : 이동할 말의 위치
*/
Rook::Rook(int player)
:Piece(Piece::Rook,player)
{}

bool Rook::Move(int x0, int y0, int x1, int y1)
{
    if(x0==x1||y0==y1)
        return Piece::Move(x0,y0,x1,y1);
    return false;
}
