/**
* @file     ChessBoard.cpp
* @author   김윤재, 이영한
* @date     21/05/22
*/
#include "ChessBoard.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"

/**
* @brief    ChessBoard function
* @detail   8X8배열을 생성한다,
*           -  -  -  -  -  -  -  -
*           -  -  -  -  -  -  -  -
*           -  -  -  -  -  -  -  -
*           -  -  -  -  -  -  -  -     
*           -  -  -  -  -  -  -  -
*           -  -  -  -  -  -  -  -
*           -  -  -  -  -  -  -  -
*           -  -  -  -  -  -  -  -
*
*           Player(Black)부터 King,Queen,Bishop,Knight,Rock,Pawn을 생성한다.
*           그다음 Player(White)의 King,Queen,Bishop,Knight,Rock,Pawn을 생성한다.
*           [R] [N] [B] [Q] [K] [B] [N] [R]
*           [P] [P] [P] [P] [P] [P] [P] [P]
*           
*              
*           
*           
*           [P] [P] [P] [P] [P] [P] [P] [P]
*           [R] [N] [B] [Q] [K] [B] [N] [R]
*/
ChessBoard::ChessBoard(bool boolStd)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pBoard[i][j] = 0;
        }
    }
    
    if(boolStd)
    {
        int Player = Piece::Black;
        int Position[2] = { 0, 1 };

        for (int i = 0; i < 2; i++)
        {
            pBoard[4][Position[0]] = new King(Player);
            pBoard[3][Position[0]] = new Queen(Player);
            pBoard[2][Position[0]] = new Bishop(Player);
            pBoard[5][Position[0]] = new Bishop(Player);
            pBoard[1][Position[0]] = new Knight(Player);
            pBoard[6][Position[0]] = new Knight(Player);
            pBoard[0][Position[0]] = new Rook(Player);
            pBoard[7][Position[0]] = new Rook(Player);
            
            for (int j = 0; j < 8; j++)
                pBoard[j][Position[1]] = new Pawn(Player);

            Position[0] = 7;
            Position[1] = 6;
            Player = Piece::White;
        }
    }
}

/**
* @brief    Get Piece function
* @detail   위치 정보를 입력받아 체스판 내부의 위치인지 확인 후 그 위치의 말 반환
* @param    x,y : 말의 위치
*/

Piece* ChessBoard::GetPiece(int x, int y)
{
    if (x >= 0 && x < 8 && y >= 0 && y < 8)
        return pBoard[x][y];
    return 0;
}

const Piece* ChessBoard::GetPiece(int x, int y) const {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return pBoard[x][y];
    }

    return 0;
}

/**
* @brief    MoveTo function
* @detail   말의 기존위치정보와 이동할위치정보를 받아 이동할 위치에 말이 있다면 소멸시키고 그 위치로 말 이동
* @param    x0, y0 : 기존 말의 위치 
*           x1, y1 : 이동할 위치
*/
bool ChessBoard::MoveTo(int x0, int y0, int x1, int y1)
{
    if (pBoard[x1][y1])
        delete pBoard[x1][y1]; // 목적지 위치에 있던 말 소멸
    pBoard[x1][y1] = pBoard[x0][y0];
    pBoard[x0][y0] = 0;
    return true;
}

/**
* @brief    ChessBoard 소멸자
* @detail   체스판 소멸
*/
ChessBoard::~ChessBoard(void)
{  
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (pBoard[i][j] != 0)
                delete pBoard[i][j];
        }
    }
}
