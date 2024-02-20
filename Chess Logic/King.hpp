#include "Pawns.hpp"

#ifndef _KING_HPP_
#define _KING_HPP_

class King : public Pawns
{
    public:
        King(char name, char color, unsigned int value, int posX, int posY);
        King(King& king);
        list<Position> possiblePosToMove(Board *board);
        void avoidKingNextKing(Board *Board, list<Position> &possibleMoves);
        void removeCheckMoves(Board *board, list<Position> &possibleMoves);
};

#endif