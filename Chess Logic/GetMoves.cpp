#include <iostream>
#include <limits.h>
#include <fstream>
#include "Board.hpp"
#include "King.hpp"
#include "AI.hpp"

// This is the opponent's color
bool locateCheck(Board* board, char color)
{
    list<Position> opponentMoves = board -> getAllMoves(color);
    char colorOpponent, nameOpponent;
    list<Position>::iterator it;

    for(it = opponentMoves.begin(); it != opponentMoves.end(); ++it)
    {
        if(board -> getBoardPos(it -> getOutX(), it -> getOutY()) != NULL)
        {
            colorOpponent = board -> getBoardPos(it -> getOutX(), it -> getOutY()) -> getColor();
            nameOpponent = board -> getBoardPos(it -> getOutX(), it -> getOutY()) -> getName();

            if((colorOpponent != color) && ((nameOpponent == 'K') || (nameOpponent == 'k')))
            {
                return(true);
            }
        }
        else
        {
            continue;
        }
    }

    return(false);
}

bool locateCheckmate(Board* board, char color)
{
    char AnotherColor = (color == 'w') ? 'b' : 'w';

    list<Position> allMyMoves = board -> getAllMoves(color);
    list<Position>::iterator it;
    Board* boardCopy;
    
    if(locateCheck(board, AnotherColor) == true)
    {
        for(it = allMyMoves.begin(); it != allMyMoves.end(); ++it)
        {
            boardCopy = new Board(*board);
            boardCopy -> MovePawns(*it);

            if(locateCheck(boardCopy, AnotherColor) == false)
            {
                delete boardCopy;
                return(false);
            }

            delete boardCopy;
        }

        return(true);
    }

    return(false);
}

void removeCheckMoves(Board* board, list<Position> &possibleMoves, char color)
{
    int i = -1;
    list<Position>::iterator it;
    list<Position> keepPossibleMoves;
    char OpponentColor = (color == 'w') ? 'b' : 'w';
    Board* boardCopy;

    for(it = possibleMoves.begin(); it != possibleMoves.end(); ++it)
    {
        i++;
        boardCopy = new Board(*board);
        boardCopy -> MovePawns(*it);

        if(!locateCheck(boardCopy, OpponentColor))
        {
            keepPossibleMoves.push_back(*it);
        }
        
        delete boardCopy;
    }

    possibleMoves = keepPossibleMoves;

    keepPossibleMoves.clear();
}

int main() 
{
    Board* board = new Board("position.txt");
    int xPos, yPos;
    Position pos;
    list<Position> positions, pawnPositions;
    list<Position>::iterator it;
    fstream file;

    file.open("selectPawns.txt", ios::in);

    if(!file)
    {
        std::cout << "No such file";
    }

    file >> xPos;
    file >> yPos;

    file.close();

    positions = board -> getAllMoves(board -> getPlayerColor());

    removeCheckMoves(board, positions, board -> getPlayerColor());

    if(positions.size() == 0)
    {
        file.open("selectPawns.txt", std::ofstream::out | std::ofstream::trunc);

        if(locateCheckmate(board, board -> getPlayerColor()) == true)
        {
            file << "Checkmate" << endl;
        }
        else
        {
            file << "NoMoves" << endl;
        }

        file.close();
        delete board;
        return(0);
    }

    for(it = positions.begin(); it != positions.end(); ++it)
    {
        pos = *it;

        if((pos.getInX() == xPos) && (pos.getInY() == yPos))
        {
            pawnPositions.push_back(*it);
        }
    }

    positions = pawnPositions;

    file.open("selectPawns.txt", std::ofstream::out | std::ofstream::trunc);

    for(it = positions.begin(); it != positions.end(); ++it)
    {
        pos = *it;

        file << pos.getOutX();
        file << " ";
        file << pos.getOutY() << endl;
    }

    file.close();
    delete board;
}