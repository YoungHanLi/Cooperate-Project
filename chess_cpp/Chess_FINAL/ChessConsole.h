/**
* @file		ChessConsole.h
* @author	장하림, 김윤재, 이영한
* @date		21/05/21
* @brief	프로그램을 유기적으로 연결하여 체스게임을 진행
* @detail	SYSTEM : 킹이 사망했는지 판단
*/
#pragma once

#include "ChessBoard.h"
#include "Piece.h"
#include "ChessGraphics.h"

class ChessConsole
{
private:
	bool SYSTEM = true;
	ChessBoard board;
	ChessGraphics graphics;
	int player = Piece::Black;
public:
	ChessConsole(ChessConsole& program);
	void Executecommand(void);
	ChessConsole(void);
	int Run(void);
	void Quit(void);
};
