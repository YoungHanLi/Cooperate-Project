/**
* @file		ChessGraphics.h
* @author	이영한, 김나영	
* @date		21/05/21
* @brief	체스판을 콘솔창에 출력
* @detail	pBoard : 체스판을 가르키는 포인터 ( 체스판의 특정 부분 )
*/

#pragma once
#include "Piece.h"
#include "ChessBoard.h"

class ChessGraphics
{
private:
	const ChessBoard* pBoard = 0;
public:
	ChessGraphics(const ChessBoard* pBoard);
	void PrintBoard(void) const;
	static char* PrintPiece(const Piece* pPiece);
};
