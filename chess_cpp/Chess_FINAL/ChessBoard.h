/**
* @file     ChessBoard.h
* @author   김윤재, 이영한
* @date     21/05/22
* @brief    체스판
* @detail   Piece* pBoard[8][8] : 체스판, 말의 주소값 저장
*/
#pragma once

#include "Piece.h"

class ChessBoard
{
private:
    Piece* pBoard[8][8];
public:
    ChessBoard(bool boolStd = true);
    ~ChessBoard(void);
    Piece* GetPiece(int x, int y);
    const Piece* GetPiece(int x, int y) const;
    bool MoveTo(int x0, int y0, int x1, int y1);
};