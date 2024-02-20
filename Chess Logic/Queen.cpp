#include "Queen.hpp"
#include "Position.hpp"
#include "Board.hpp"

Queen::Queen(char name, char color, unsigned int value, int posX, int posY)
{
    this -> name = name;
    this -> color = color;
    this -> value = value;
    this -> posX = posX;
    this -> posY = posY;
}

Queen::Queen(Queen& queen)
{
    this -> name = queen.name;
    this -> color = queen.color;
    this -> value = queen.value;
    this -> posX = queen.posX;
    this -> posY = queen.posY;
}

list<Position> Queen::possiblePosToMove(Board *board) 
{
    std::list<Position> possibleMoves;
    int i = 1;

    // Moving down
    while((board -> checkInBounds(this -> getPosX() + i, this -> getPosY())) && ((board -> IsPosEmpty(this -> getPosX() + i, this -> getPosY())) || (board -> getBoardPos(this -> getPosX() + i, this -> getPosY()) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + i, this -> getPosY()));

        if((!board -> IsPosEmpty(this -> getPosX() + i, this -> getPosY())) && (board -> getBoardPos(this -> getPosX() + i, this -> getPosY()) -> getColor() != this -> getColor()))
        {
            break;
        }
        
        i++;
    }

    i = 1;

    //Moving up
    while((board -> checkInBounds(this -> getPosX() - i, this -> getPosY())) && ((board -> IsPosEmpty(this -> getPosX() - i, this -> getPosY())) || (board -> getBoardPos(this -> getPosX() - i, this -> getPosY()) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - i, this -> getPosY()));

        if((!board -> IsPosEmpty(this -> getPosX() - i, this -> getPosY())) && (board -> getBoardPos(this -> getPosX() - i, this -> getPosY()) -> getColor() != this -> getColor()))
        {
            break;
        }
        
        i++;
    }

    i = 1;

    //Moving right
    while((board -> checkInBounds(this -> getPosX(), this -> getPosY() + i)) && ((board -> IsPosEmpty(this -> getPosX(), this -> getPosY() + i)) || (board -> getBoardPos(this -> getPosX(), this -> getPosY() + i) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX(), this -> getPosY() + i));

        if((!board -> IsPosEmpty(this -> getPosX(), this -> getPosY() + i)) && (board -> getBoardPos(this -> getPosX(), this -> getPosY() + i) -> getColor() != this -> getColor()))
        {
            break;
        }
        
        i++;
    }

    i = 1;

    //Moving left
    while((board -> checkInBounds(this -> getPosX(), this -> getPosY() - i)) && ((board -> IsPosEmpty(this -> getPosX(), this -> getPosY() - i)) || (board -> getBoardPos(this -> getPosX(), this -> getPosY() - i) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX(), this -> getPosY() - i));

        if((!board -> IsPosEmpty(this -> getPosX(), this -> getPosY() - i)) && (board -> getBoardPos(this -> getPosX(), this -> getPosY() - i) -> getColor() != this -> getColor()))
        {
            break;
        }
        
        i++;
    }

    i = 1;

    // Moving north-east
    while((board -> checkInBounds(this -> getPosX() - i, this -> getPosY() + i)) && ((board -> IsPosEmpty(this -> getPosX() - i, this -> getPosY() + i)) || (board -> getBoardPos(this -> getPosX() - i, this -> getPosY() + i) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - i, this -> getPosY() + i));

        if((!board -> IsPosEmpty(this -> getPosX() - i, this -> getPosY() + i)) && (board -> getBoardPos(this -> getPosX() - i, this -> getPosY() + i) -> getColor() != this -> getColor()))
        {
            break;
        }

        i++;
    }

    i = 1;

    // Moving south-east
    while((board -> checkInBounds(this -> getPosX() + i, this -> getPosY() + i)) && ((board -> IsPosEmpty(this -> getPosX() + i, this -> getPosY() + i)) || (board -> getBoardPos(this -> getPosX() + i, this -> getPosY() + i) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + i, this -> getPosY() + i));

        if((!board -> IsPosEmpty(this -> getPosX() + i, this -> getPosY() + i)) && (board -> getBoardPos(this -> getPosX() + i, this -> getPosY() + i) -> getColor() != this -> getColor()))
        {
            break;
        }

        i++;
    }

    i = 1;

    // Moving south-west
    while((board -> checkInBounds(this -> getPosX() + i, this -> getPosY() - i)) && ((board -> IsPosEmpty(this -> getPosX() + i, this -> getPosY() - i)) || (board -> getBoardPos(this -> getPosX() + i, this -> getPosY() - i) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + i, this -> getPosY() - i));

        if((!board -> IsPosEmpty(this -> getPosX() + i, this -> getPosY() - i)) && (board -> getBoardPos(this -> getPosX() + i, this -> getPosY() - i) -> getColor() != this -> getColor()))
        {
            break;
        }

        i++;
    }

    i = 1;

    // Moving north-west
    while((board -> checkInBounds(this -> getPosX() - i, this -> getPosY() - i)) && ((board -> IsPosEmpty(this -> getPosX() - i, this -> getPosY() - i)) || (board -> getBoardPos(this -> getPosX() - i, this -> getPosY() - i) -> getColor() != this -> getColor())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - i, this -> getPosY() - i));

        if((!board -> IsPosEmpty(this -> getPosX() - i, this -> getPosY() - i)) && (board -> getBoardPos(this -> getPosX() - i, this -> getPosY() - i) -> getColor() != this -> getColor()))
        {
            break;
        }

        i++;
    }

    return(possibleMoves);
}