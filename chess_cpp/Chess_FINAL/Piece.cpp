/**
* @file     Piece.cpp
* @author   이영한
* @date     21/05
*/
#include "Piece.h"

Piece::Piece(int pieceType, int player)
:pieceType(pieceType), player(player)
{}
    
Piece::Piece(const Piece &piece)
:pieceType(piece.nowpieceType), player(piece.nowplayer)
{}

/**
* @brief    Move function
* @detail   말의 위치정보(기존위치+이동할위치)를 입력받아 말의 이동이 문제가 없는지 판단
*           조건1[x0<0||x0>=8||y0<0||y0>=8] : 체스판을 벗어난 선택 금지
*           조건2[x1<0||x1>=8||y1<0||y1>=8] : 체스판을 벗어난 이동 금지
*           조건3[x0==x1&&y0==y1] : 제자리 이동 금지
* @param    x0, y0 : 기존 말의 위치 
*           x1, y1 : 이동할 말의 위치
*/

bool Piece::Move(int x0, int y0, int x1, int y1)
{
    if(!(x0<0||x0>=8||y0<0||y0>=8))
        if(!(x1<0||x1>=8||y1<0||y1>=8))
            if(!(x0==x1&&y0==y1))
                return true;
    return false;
}