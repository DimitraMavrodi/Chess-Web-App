#include <string>
#include "Pawns.hpp"
#include "Position.hpp"

#ifndef _BOARD_HPP_
#define _BOARD_HPP_

class Board
{
    private:
        Pawns ***board;
        int height;
        int width;
        char playerColor; // Color for player, ' ' for nothing, 'b' for black, 'w' for white
    public:
        Board(int height, int width, char playerColor);  // Empty board
        Board(Board& board);
        Board(std::string fileName);  // Input for a file
        ~Board();
        int getHeight();
        int getWidth();
        Pawns*** getBoard();
        void setBoard(Pawns*** board);
        Pawns* getBoardPos(int posX, int posY);
        void setBoardPos(int posX, int posY, Pawns* pawn);
        char getPlayerColor();
        void setPlayerColor(char playerColor);
        bool checkInBounds(int posX, int posY);
        bool IsPosEmpty(int PosX, int PosY);
        list<Position> getAllMoves(char color);
        list<Position> getAllMovesExceptKing(char color);
        int getAllPawnsValues(char color);
        int getAllMobilityValues(char color);
        int getAllSoldiersValue(char color);
        bool locateCheck(char color);
        bool locateStalemate(char color);
        bool locateCheckmate(char color);
        bool locateDraw();
        void MovePawns(Position Move);
};


#endif