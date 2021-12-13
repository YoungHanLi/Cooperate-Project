/**
* @file     Piece.h
* @author   이영한
* @date     21/05
* @brief    모든 말(Piece)의 기본 클래스
* @detail   pieceType : 말의 종류 [ Pawn=0, Rook=1, Knight=2, Bishop=3, Queen=4, King=5 ]
*           player    : 플레이어 구분 [ BlackPlayer=0, WhitePlayer=1 ]
*/
#pragma once
class ChessBoard;

class Piece
{
private:
    int pieceType;
    int player;
public:
    const int& nowpieceType = pieceType;
    const int& nowplayer=player;
public:
    enum
    {
        Pawn=0,
        Rook=1,
        Knight=2,
        Bishop=3,
        Queen=4,
        King=5
    };
    enum
    {
        Black=0,
        White=1
    };
public:
    Piece(int pieceType, int player);
    Piece(const Piece& piece);
    virtual bool Move(int x0, int y0, int x1, int y1);

    friend class Pawn;
    friend class ChessGraphics;
};
