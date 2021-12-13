/**
* @file		ChessGraphics.cpp
* @author	이영한,김나영
* @date		21/05/21
*/
#include <iostream>
#include <Windows.h>
#include "Piece.h"
#include "ChessBoard.h" 
#include "ChessGraphics.h"

ChessGraphics::ChessGraphics(const ChessBoard* pBoard)
	: pBoard(pBoard)
{}

/**
* @brief	체스판 틀(구조) 출력
* @detail	콘솔창에 다음과 같이 출력
*		8
*		7
*		6
*		5
*		4
*		3
*		2
*		1
*		 A B C D E F G H
*/
void ChessGraphics::PrintBoard(void) const
{
	const char indexBottom[] = "ABCDEFGH";
	const Piece* pPiece = 0;

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			/* 1. 체스판 테두리(체스판 최우측) 생성*/
			if (j == 9 && i != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				std::cout << "  ";
			}
			/* 2. 체스판 테두리(체스판 최상단) 생성*/
			if (i == 0)
			{
				if (j == 0 || j == 9)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					std::cout << "  ";
				}
				else if (j <= 8)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					std::cout << "   ";
				}
				continue;
			}
			/* 3. 체스판 테두리(체스판 최하단)에 ABCDEFGH 인덱스 출력 */
			if (i == 9)
			{
				if (j == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE );
					std::cout << "  ";
				}
				else if(j <= 8)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE );
					std::cout <<" "<<indexBottom[j - 1] <<" ";
				}
				continue;
			}
			/* 4. 체스판 테두리(체스판 최좌측)에 (1234567) 인덱스 출력 */
			if (j == 0 && i != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				std::cout <<" "<< 9 - i;
			}

			/* 5. 체스판에서 말,빈칸 출력 */
			else if( j != 9 )
			{
				pPiece = pBoard->GetPiece(j-1, i-1);
				/* 색깔정하기 */
				if (pPiece && pPiece->player == Piece::Black)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY|BACKGROUND_INTENSITY| BACKGROUND_RED| BACKGROUND_BLUE| BACKGROUND_GREEN);
				else
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY| BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
				/* 말출력(함수호출) */
				std::cout << PrintPiece(pPiece);
			}
		}
		std::cout << std::endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	return;
}

/**
* @brief	체스판 위에 놓아질 말 출력
* @detail	각 말의 종류에 따라 적절한 문자열로 출력, 말이 아닌 경우 빈칸 출력
* @param	pPiece : 문자형태로 출력하고자 하는 특정 말
*/
char* ChessGraphics::PrintPiece(const Piece* pPiece)
{
	if (pPiece == 0)
		return (char*)"   ";
	else
	{
		switch (pPiece->pieceType)
		{
		case Piece::King:
			return (char*)"[K]";
		case Piece::Queen:
			return (char*)"[Q]";
		case Piece::Bishop:
			return (char*)"[B]";
		case Piece::Knight:
			return (char*)"[N]";
		case Piece::Rook:
			return (char*)"[R]";
		case Piece::Pawn:
			return (char*)"[P]";
		default:
			return 0;
		}
	}
	return 0;
}
