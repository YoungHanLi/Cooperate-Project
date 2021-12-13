/**
* @file     Queen.cpp
* @author   김나영
* @date     21/05
*/

#include "Queen.h"

/**
* @brief    Move
* @detail   Queen의 이동 함수
*			매크로 ABSOUL(X) : 절댓값으로 만들어 줌
*           조건1[x0==x1] : y축 방향(세로) 일직선 이동
*           조건2[y0==y1] : x축 방향(가로) 일직선 이동
*			조건3[ABSOUL(x0 - x1) == ABSOUL(y0 - y1)] : 대각선 이동
* @param    x0, y0 : 기존 말의 위치
*           x1, y1 : 이동할 말의 위치
*/

#define ABSOUL(X) ((X) < 0 ? -(X) : (X))

bool Queen::Move(int x0, int y0, int x1, int y1)
{
	if (x0 == x1)
		return Piece::Move(x0, y0, x1, y1);
	else if (y0 == y1)
		return Piece::Move(x0, y0, x1, y1);
	else if(ABSOUL(x0 - x1) == ABSOUL(y0 - y1))
		return Piece::Move(x0, y0, x1, y1);

	return false;
}

Queen::Queen(int player)
: Piece(Piece::Queen, player) 
{}
