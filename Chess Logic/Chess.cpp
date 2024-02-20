#include <iostream>
#include <limits.h>
#include <fstream>
#include "Board.hpp"
#include "AI.hpp"

int main() 
{
    Board* board = new Board("position.txt");
    AI* Ai = new AI(4, board);
    Position pos;
    list<Position> po;
    list<Position>::iterator it;
    fstream file;
    char AnotherColor = (board -> getPlayerColor() == 'w') ? 'b' : 'w';

    file.open("position.txt", std::ofstream::out | std::ofstream::trunc);

    if((board->locateCheckmate(board->getPlayerColor())))
    {
        file << "Checkmate" << endl;

        file.close();
        delete board;
        delete Ai;
        return(0);
    }

    po = board -> getAllMoves(AnotherColor);
    Ai -> removeCheckMoves(board, po);

    if(po.size() == 0)
    {
        file << "NoMoves" << endl;

        file.close();
        delete board;
        delete Ai;
        return(0);
    }

    pos = Ai -> negamaxBegin(INT_MIN, INT_MAX);

    if(!file)
    {
        std::cout << "No such file";
    }

    file << pos.getInX();
    file << " ";
    file << pos.getInY();
    file << " ";
    file << pos.getOutX();
    file << " ";
    file << pos.getOutY() << endl;

    file.close();
    delete board;
    delete Ai;
}