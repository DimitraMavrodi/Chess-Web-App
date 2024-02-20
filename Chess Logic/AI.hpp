#include "Board.hpp"
#include "Position.hpp"

#ifndef _AI_HPP_
#define _AI_HPP_

class AI
{
    private:
        int depth;
        list<Position> buffer;
        Board* board;
    public:
        AI(int depth, Board* board);
        int getDepth();
        void setDepth(int depth);
        int negamax(Board* board, int alpha, int beta, int depth, char color);
        Position negamaxBegin(int alpha, int beta);
        int evalBoard(Board* board);
        void removeCheckMoves(Board* board, list<Position> &possibleMoves);
};

#endif