/**
* @file     Bishop.h
* @author   김나영
* @date     21/05
* @brief    비숍(Bishop)
*/

#include "Bishop.h"

/**
* @brief    Move
* @detail   Bishop의 이동 함수
*			매크로 ABSOUL(X) : 절댓값으로 만들어 줌
*           조건1[ABSOUL(x0 - x1) == ABSOUL(y0 - y1)] : 대각선 이동
* @param    x0, y0 : 기존 말의 위치
*           x1, y1 : 이동할 말의 위치
*/

#define ABSOUL(X) ((X) < 0 ? -(X) : (X))

bool Bishop::Move(int x0, int y0, int x1, int y1)
{
	if (ABSOUL(x0 - x1) == ABSOUL(y0 - y1))
		return Piece::Move(x0, y0, x1, y1);
	return false;
}

Bishop::Bishop(unsigned int player)
: Piece(Piece::Bishop, player)
{}
