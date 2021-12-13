/**
* @file     Knight.h
* @author   장하림
* @date     21/05
* @brief    나이트(Knight)
*/

#include "Knight.h"

Knight::Knight(int player)
:Piece(Piece::Knight, player)
{}

/**
* @brief    Move
* @detail   Knight의 이동 함수
*           조건1[(x0 - x1) == 2 || (x0 - x1) == -2] : 좌우 1칸 이동 후 대각 1칸 이동
*           조건2[(x0 - x1) == 1 || (x0 - x1) == -1] : 상하 1칸 이동 후 대각 1칸 이동
* @param    x0, y0 : 기존 말의 위치
*           x1, y1 : 이동할 말의 위치
*/

bool Knight::Move(int x0, int y0, int x1, int y1)
{
	if ((x0 - x1) == 2 || (x0 - x1) == -2) {
		if ((y0 - y1) == 1 || (y0 - y1) == -1)	{
			return Piece::Move(x0, y0, x1, y1);
		}
	}
	else if ((x0 - x1) == 1 || (x0 - x1) == -1) {
		if ((y0 - y1) == 2 || (y0 - y1) == -2)	{	
			return Piece::Move(x0, y0, x1, y1);			
		}
	}
	return false;
}
