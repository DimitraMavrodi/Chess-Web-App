#include "King.hpp"
#include "Position.hpp"
#include "Board.hpp"

King::King(char name, char color, unsigned int value, int posX, int posY)
{
    this -> name = name;
    this -> color = color;
    this -> value = value;
    this -> posX = posX;
    this -> posY = posY;
}

King::King(King& king)
{
    this -> name = king.name;
    this -> color = king.color;
    this -> value = king.value;
    this -> posX = king.posX;
    this -> posY = king.posY;
}

list<Position> King::possiblePosToMove(Board *board)
{
    std::list<Position> possibleMoves;

    if((board -> checkInBounds(this -> getPosX() - 1, this -> getPosY())) && ((board -> IsPosEmpty(this -> getPosX() - 1, this -> getPosY())) || (board -> getBoardPos(this -> getPosX() - 1, this -> getPosY()) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - 1, this -> getPosY()));
    }

    if((board -> checkInBounds(this -> getPosX() - 1, this -> getPosY() - 1)) && ((board -> IsPosEmpty(this -> getPosX() - 1, this -> getPosY() - 1)) || (board -> getBoardPos(this -> getPosX() - 1, this -> getPosY() - 1) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - 1, this -> getPosY() - 1));
    }

    if((board -> checkInBounds(this -> getPosX() - 1, this -> getPosY() + 1)) && ((board -> IsPosEmpty(this -> getPosX() - 1, this -> getPosY() + 1)) || (board -> getBoardPos(this -> getPosX() - 1, this -> getPosY() + 1) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - 1, this -> getPosY() + 1));
    }

    if((board -> checkInBounds(this -> getPosX(), this -> getPosY() + 1)) && ((board -> IsPosEmpty(this -> getPosX(), this -> getPosY() + 1)) || (board -> getBoardPos(this -> getPosX(), this -> getPosY() + 1) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX(), this -> getPosY() + 1));
    }

    if((board -> checkInBounds(this -> getPosX() + 1, this -> getPosY() + 1)) && ((board -> IsPosEmpty(this -> getPosX() + 1, this -> getPosY() + 1)) || (board -> getBoardPos(this -> getPosX() + 1, this -> getPosY() + 1) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + 1, this -> getPosY() + 1));
    }

    if((board -> checkInBounds(this -> getPosX() + 1, this -> getPosY())) && ((board -> IsPosEmpty(this -> getPosX() + 1, this -> getPosY())) || (board -> getBoardPos(this -> getPosX() + 1, this -> getPosY()) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + 1, this -> getPosY()));
    }

    if((board -> checkInBounds(this -> getPosX() + 1, this -> getPosY() - 1)) && ((board -> IsPosEmpty(this -> getPosX() + 1, this -> getPosY() - 1)) || (board -> getBoardPos(this -> getPosX() + 1, this -> getPosY() - 1) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + 1, this -> getPosY() - 1));
    }

    if((board -> checkInBounds(this -> getPosX(), this -> getPosY() - 1)) && ((board -> IsPosEmpty(this -> getPosX(), this -> getPosY() - 1)) || (board -> getBoardPos(this -> getPosX(), this -> getPosY() - 1) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX(), this -> getPosY() - 1));
    }

    avoidKingNextKing(board, possibleMoves);
    //removeCheckMoves(board, possibleMoves);

    return(possibleMoves);
}

void King::avoidKingNextKing(Board *board, list<Position> &possibleMoves)
{
    std::list<Position>::iterator it;
    std::list<Position> keepMoves;
    int i = -1;

    for(it = possibleMoves.begin(); it != possibleMoves.end(); ++it)
    {
        i = i + 1;

        if(!((board -> checkInBounds(it -> getOutX() - 1, it -> getOutY())) && (!(board -> IsPosEmpty(it -> getOutX() - 1, it -> getOutY()))) && (board -> getBoardPos(it -> getOutX() - 1, it -> getOutY()) -> getColor() != this -> getColor()) && (board -> getBoardPos(it -> getOutX() - 1, it -> getOutY()) -> getName() == this -> getName())))
        {
            keepMoves.push_back(*it);
            continue;
        }

        if(!((board -> checkInBounds(it -> getOutX() - 1, it -> getOutY() - 1)) && (!(board -> IsPosEmpty(it -> getOutX() - 1, it -> getOutY() - 1))) && (board -> getBoardPos(it -> getOutX() - 1, it -> getOutY() - 1) -> getColor() != this -> getColor()) && (board -> getBoardPos(it -> getOutX() - 1, it -> getOutY() - 1) -> getName() == this -> getName())))
        {
            keepMoves.push_back(*it);
            continue;
        }

        if(!((board -> checkInBounds(it -> getOutX() - 1, it -> getOutY() + 1)) && (!(board -> IsPosEmpty(it -> getOutX() - 1, it -> getOutY() + 1))) && (board -> getBoardPos(it -> getOutX() - 1, it -> getOutY() + 1) -> getColor() != this -> getColor()) && (board -> getBoardPos(it -> getOutX() - 1, it -> getOutY() + 1) -> getName() == this -> getName())))
        {
            keepMoves.push_back(*it);
            continue;
        }

        if(!((board -> checkInBounds(it -> getOutX(), it -> getOutY() + 1)) && (!(board -> IsPosEmpty(it -> getOutX(), it -> getOutY() + 1))) && (board -> getBoardPos(it -> getOutX(), it -> getOutY() + 1) -> getColor() != this -> getColor()) && (board -> getBoardPos(it -> getOutX(), it -> getOutY() + 1) -> getName() == this -> getName())))
        {
            keepMoves.push_back(*it);
            continue;
        }

        if(!((board -> checkInBounds(it -> getOutX() + 1, it -> getOutY() + 1)) && (!(board -> IsPosEmpty(it -> getOutX() + 1, it -> getOutY() + 1))) && (board -> getBoardPos(it -> getOutX() + 1, it -> getOutY() + 1) -> getColor() != this -> getColor()) && (board -> getBoardPos(it -> getOutX() + 1, it -> getOutY() + 1) -> getName() == this -> getName())))
        {   
            keepMoves.push_back(*it);
            continue;
        }

        if(!((board -> checkInBounds(it -> getOutX() + 1, it -> getOutY())) && (!(board -> IsPosEmpty(it -> getOutX() + 1, it -> getOutY()))) && (board -> getBoardPos(it -> getOutX() + 1, it -> getOutY())-> getColor() != this -> getColor()) && (board -> getBoardPos(it -> getOutX() + 1, it -> getOutY()) -> getName() == this -> getName())))
        {
            keepMoves.push_back(*it);
            continue;
        }

        if(!((board -> checkInBounds(it -> getOutX() + 1, it -> getOutY() - 1)) && (!(board -> IsPosEmpty(it -> getOutX() + 1, it -> getOutY() - 1))) && (board -> getBoardPos(it -> getOutX() + 1, it -> getOutY() - 1) -> getColor() != this -> getColor()) && (board -> getBoardPos(it -> getOutX() + 1, it -> getOutY() - 1) -> getName() == this -> getName())))
        {
            keepMoves.push_back(*it);
            continue;
        }

        if(!((board -> checkInBounds(it -> getOutX(), it -> getOutY() - 1)) && (!(board -> IsPosEmpty(it -> getOutX(), it -> getOutY() - 1))) && (board -> getBoardPos(it -> getOutX(), it -> getOutY() - 1) -> getColor() != this -> getColor()) && (board -> getBoardPos(it -> getOutX(), it -> getOutY() - 1) -> getName() == this -> getName())))
        {
            keepMoves.push_back(*it);
            continue;
        }
    }

    possibleMoves = keepMoves;

    keepMoves.clear();
}

void King::removeCheckMoves(Board *board, list<Position> &possibleMoves)
{
    int i = -1;
    list<Position>::iterator it;
    list<Position> keepPossibleMoves;
    char anotherColor = (this -> getColor() == 'w') ? 'b' : 'w';
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