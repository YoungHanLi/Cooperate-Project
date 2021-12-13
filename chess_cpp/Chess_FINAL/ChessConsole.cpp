/**
* @file     ChessConsole.cpp
* @author   김윤재,장하림,이영한
* @date     21/05/22
*/
#include <iostream>
#include <string>
#include "ChessConsole.h"
#include "ChessBoard.h"
#include "Piece.h"
#include "ChessGraphics.h"
#include "Windows.h"

ChessConsole::ChessConsole(ChessConsole& program)
: graphics(&board)
{}

ChessConsole::ChessConsole(void)
: graphics(&board)
{}

/**
* @brief    Run function
* @detail   화면을 지우고 다시 체스판을 그린후 Executecomand()함수 호출 
*/
int ChessConsole::Run(void)
{
	while (SYSTEM)
	{
		std::system("cls");
		graphics.PrintBoard();
		Executecommand();
	}
	return 0;
}

void ChessConsole::Quit(void)
{
	if (player == Piece::Black)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "           " << "승리" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "\n\n\n\n\n\n\n\n\n" << std::endl;
}

void ChessConsole::Executecommand(void) {
	std::string command[2];

	int x[2] = { 0,0 };
	int y[2] = { 0,0 };

	if (player == Piece::Black)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY );
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY );

	std::cout << "____________________________"<<std::endl;
	if (player == Piece::Black)
		std::cout << "    현재 Blue차례입니다."<<std::endl;
	else
		std::cout << "    현재 Red차례입니다."<<std::endl;
	std::cout << "\n      선택 좌표 : ";
	std::cin >> command[0];
	std::cout << "      목표 좌표 : ";
	std::cin >> command[1];
	x[0] = command[0][0] - 'A';
	y[0] = 7 - (command[0][1] - '1');
	x[1] = command[1][0] - 'A';
	y[1] = 7 - (command[1][1] - '1');

	Piece* select = board.GetPiece(x[0], y[0]);
	Piece* target = board.GetPiece(x[1], y[1]);

	if (select != nullptr && select->nowplayer == player)
	{
		if (target != nullptr && target->nowpieceType == Piece::King)
		{
			if (select->Move(x[0], y[0], x[1], y[1]))
			{
				if (board.MoveTo(x[0], y[0], x[1], y[1]))
				{
					SYSTEM = false;
					std::system("cls");
					graphics.PrintBoard();
				}
			}
		}
		else if (target == nullptr && select->nowpieceType == Piece::Pawn)
		{
			if (x[0] == x[1])
			{
				if (select->Move(x[0], y[0], x[1], y[1]))
				{
					if (board.MoveTo(x[0], y[0], x[1], y[1]))
					{
						player = !player;
					}
				}
			}
		}
		else if (target != nullptr && target->nowplayer != player && select->nowpieceType == Piece::Pawn)
		{
			if (x[0] != x[1])
			{
				if (select->Move(x[0], y[0], x[1], y[1]))
				{
					if (board.MoveTo(x[0], y[0], x[1], y[1]))
					{
						player = !player;
					}
				}
			}
		}
		else if (target != nullptr && target->nowplayer != player && select->Move(x[0], y[0], x[1], y[1]) && select->nowpieceType != Piece::Pawn)
		{
			if (board.MoveTo(x[0], y[0], x[1], y[1]))
			{
				player = !player;
			}
		}
		else if (target == nullptr && select->Move(x[0], y[0], x[1], y[1]) && select->nowpieceType != Piece::Pawn)
		{
			if (board.MoveTo(x[0], y[0], x[1], y[1]))
			{
				player = !player;
			}
		}
	}
}
