#include <limits.h>
#include <thread>
#include <chrono>
#include "AI.hpp"
#include "Board.hpp"
#include "Position.hpp"

const static int C1 = 12; // for material value
const static int C2 = 1; // for mobility value
const static int C3 = 3; // for pawn rank value
const static int STALEMATE = 0;
const static int DRAW = 0;
const static int CHECK = 2; // check is multiplicand
const static int CHECKMATE = (CHECK * ((C1*103) + (C2*215) + (C3*48))) + 1;
const static int BUFFER_SIZE = 3;

AI::AI(int depth, Board* board)
{
    this -> depth = depth;
    this -> board = board;
}

int AI::getDepth()
{
    return(this -> depth);
}
    
void AI::setDepth(int depth)
{
    this -> depth = depth;
}

void AI::removeCheckMoves(Board* board, list<Position> &possibleMoves)
{
    int i = -1;
    list<Position>::iterator it;
    list<Position> keepPossibleMoves;
    char anotherColor = board -> getPlayerColor();  //Player's Color
    Board* boardCopy;

    for(it = possibleMoves.begin(); it != possibleMoves.end(); ++it)
    {
        i++;
        boardCopy = new Board(*board);
        boardCopy -> MovePawns(*it);

        if(!boardCopy -> locateCheck(anotherColor))
        {
            keepPossibleMoves.push_back(*it);
        }
        
        delete boardCopy;
    }

    possibleMoves = keepPossibleMoves;

    keepPossibleMoves.clear();
}

Position AI::negamaxBegin(int alpha, int beta)
{
    char AIColor = (this -> board -> getPlayerColor() == 'w') ? 'b' : 'w';
    list<Position> possibleMoves = this -> board -> getAllMoves(AIColor);
    list<Position> bestMoves;
    list<Position>::iterator it1, it2;
    int BestValue = INT_MIN;
    this -> removeCheckMoves(this -> board, possibleMoves);
    bool includeInBuffer = false;
    Board *boardCopy;
    Position TheBestMove;

    for(it1 = possibleMoves.begin(); it1 != possibleMoves.end(); ++it1)
    {
        includeInBuffer = false;

        for(it2 = this -> buffer.begin(); it2 != this -> buffer.end(); ++it2)
        {
            if(it1 -> isEqual(*it2))
            {
                includeInBuffer = true;
                break;
            }
        }

        if(includeInBuffer == true)
        {
            continue;
        }

        boardCopy = new Board(*this -> board);
        boardCopy -> MovePawns(*it1);

        int v = -negamax(boardCopy, -beta, -alpha, getDepth() - 1, this -> board -> getPlayerColor());

        delete(boardCopy);

        if(v == BestValue || possibleMoves.size() <= BUFFER_SIZE) 
        {
			bestMoves.push_back(*it1);
        }
        else if (v > BestValue) 
        {
			BestValue = v;
			bestMoves.clear();
			bestMoves.push_back(*it1);
		}

		if (BestValue > alpha) 
        { 
            alpha = BestValue;	
        }

		if (alpha >= beta)
        { 
            break;
        }
    }

    if(bestMoves.size() == 0)
    {
        return(TheBestMove);
    }

    it1 = bestMoves.begin();
    std::advance(it1, rand() % bestMoves.size());

    TheBestMove = *it1;
    buffer.push_back(TheBestMove);

    if (buffer.size() > BUFFER_SIZE) 
    {
		buffer.erase(buffer.begin());
	}

    return(TheBestMove);
}

int AI::negamax(Board* board, int alpha, int beta, int depth, char color)
{
    char opponentColor = (color == 'w') ? 'b' : 'w';
    int offset = (opponentColor == board -> getPlayerColor()) ? 1 : -1;
    list<Position> possibleMoves;
    list<Position>::iterator it;
    Board* copyBoard;
    int v;

    if(depth == 0) { return(offset * evalBoard(board)); } 

    if(board -> locateCheckmate(opponentColor)) { return(-CHECKMATE); }

    if(board -> locateStalemate(color)) { return(STALEMATE); }
    
    if(board -> locateDraw()) { return(DRAW); }

    if(board -> locateCheck(opponentColor)) { return ((CHECK * offset) * evalBoard(board)); }

    int value = INT_MIN;
    possibleMoves = board -> getAllMoves(opponentColor);

    for(it = possibleMoves.begin(); it != possibleMoves.end(); ++it)
    {
        copyBoard = new Board(*board);
        copyBoard -> MovePawns(*it);

        v = -negamax(copyBoard, -beta, -alpha, depth - 1, opponentColor);

        delete(copyBoard);

        value = std::max(value, v);
		alpha = std::max(alpha, value);
		if (alpha >= beta) { break; } 
    }

    possibleMoves.clear();
    return value;
}

int AI::evalBoard(Board* board)
{
    int value = 0, p = 0, m = 0, s = 0;
    char AIColor = (board -> getPlayerColor() == 'w') ? 'b' : 'w';

    p = board -> getAllPawnsValues(AIColor);
    m = board -> getAllMobilityValues(AIColor);
    s = board -> getAllSoldiersValue(AIColor);

    value = (C1 * p) + (C2 * m) + (C3 * s);

    return(value);
}