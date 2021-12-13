/**
* @file     King.h
* @author   장하림
* @date     21/05
* @brief    킹(King)
*/
#include "King.h"

King::King(int player)
:Piece(Piece::King, player)
{}

/**
* @brief    Move
* @detail   King의 이동 함수
*           조건1[x1 == x0 - 1 || x1 == x0 + 1 || x1 == x0] : 1칸 이동
*           조건2[1 == y0 - 1 || y1 == y0 + 1 || y1 == y] : 1칸 이동
* @param    x0, y0 : 기존 말의 위치
*           x1, y1 : 이동할 말의 위치
*/

bool King::Move(int x0, int y0, int x1, int y1)
{
	if (x1 == x0 - 1 || x1 == x0 + 1 || x1 == x0)
		if (y1 == y0 - 1 || y1 == y0 + 1 || y1 == y0)
			return Piece::Move(x0, y0, x1, y1);
	return false;
}
