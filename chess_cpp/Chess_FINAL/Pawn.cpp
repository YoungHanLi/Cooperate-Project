/**
* @file     Pawn.cpp
* @author   이영한
* @date     21/05
*/
#include "Pawn.h"

Pawn::Pawn(int player)
:Piece(Piece::Pawn,player)
{}

/**
* @brief    Move function
* @detail   폰의 이동방식 정의
*           세부 조건은 각 line 참고
* @param    x0, y0 : 기존 말의 위치 
*           x1, y1 : 이동할 말의 위치
*/

bool Pawn::Move(int x0, int y0, int x1, int y1)
{
    if(firstMove==true) // 첫 이동(1칸 or 2칸 이동 가능)
    {
        if(player==Piece::Black&&x0==x1) // Black player 일직선 이동
        {
            if(y0<y1&&y0+2>=y1)
            {
                firstMove=false;
                return Piece::Move(x0,y0,x1,y1);
            }
        }
        else if(player==Piece::White&&x0==x1) // White player 일직선 이동
        {
            if(y0>y1&&y0-2<=y1)
            {
                firstMove=false;
                return Piece::Move(x0,y0,x1,y1);
            }
        }
    }
    else // 첫 이동 이후(1칸만 이동 가능)
    {
        if(player==Piece::Black&&x0==x1) // Black player 일직선 이동
        {
            if(y0+1==y1)
                return Piece::Move(x0,y0,x1,y1);
        }
        else if(player==Piece::White&&x0==x1) // White player 일직선 이동
        {
            if(y0-1==y1)
                return Piece::Move(x0,y0,x1,y1);
        }
        else if(player==Black&&x0!=x1) // Black player 대각선 공격
        {
            if((y0+1==y1)&&(x0+1==x1||x0-1==x1))
                return Piece::Move(x0,y0,x1,y1);
        }
        else if(player==White&&x0!=x1) // White player 대각선 공격
        {
            if((y0-1==y1)&&(x0+1==x1||x0-1==x1))
                return Piece::Move(x0,y0,x1,y1);
        }
    }
    return false;
}
