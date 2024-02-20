#include "Knight.hpp"
#include "Position.hpp"
#include "Board.hpp"

Knight::Knight(char name, char color, unsigned int value, int posX, int posY)
{
    this -> name = name;
    this -> color = color;
    this -> value = value;
    this -> posX = posX;
    this -> posY = posY;
}

Knight::Knight(Knight& knight)
{
    this -> name = knight.name;
    this -> color = knight.color;
    this -> value = knight.value;
    this -> posX = knight.posX;
    this -> posY = knight.posY;
}

list<Position> Knight::possiblePosToMove(Board *board)
{
    std::list<Position> possibleMoves;

    if((board -> checkInBounds(this -> getPosX() - 2, this -> getPosY() - 1)) && ((board -> IsPosEmpty(this -> getPosX() - 2, this -> getPosY() - 1)) || ((board -> getBoardPos(this -> getPosX() - 2, this -> getPosY() - 1) -> getColor() != this -> getColor()))))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - 2, this -> getPosY() - 1));
    }
    
    if((board -> checkInBounds(this -> getPosX() - 2, this -> getPosY() + 1)) && ((board -> IsPosEmpty(this -> getPosX() - 2, this -> getPosY() + 1)) || ((board -> getBoardPos(this -> getPosX() - 2, this -> getPosY() + 1) -> getColor() != this -> getColor()))))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - 2, this -> getPosY() + 1));
    }
    
    if((board -> checkInBounds(this -> getPosX() + 1, this -> getPosY() - 2)) && ((board -> IsPosEmpty(this -> getPosX() + 1, this -> getPosY() - 2)) || ((board -> getBoardPos(this -> getPosX() + 1, this -> getPosY() - 2) -> getColor() != this -> getColor()))))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + 1, this -> getPosY() - 2));
    }
    
    if((board -> checkInBounds(this -> getPosX() - 1, this -> getPosY() - 2)) && ((board -> IsPosEmpty(this -> getPosX() - 1, this -> getPosY() - 2)) || ((board -> getBoardPos(this -> getPosX() - 1, this -> getPosY() - 2) -> getColor() != this -> getColor()))))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - 1, this -> getPosY() - 2));
    }
    
    if((board -> checkInBounds(this -> getPosX() + 1, this -> getPosY() + 2)) && ((board -> IsPosEmpty(this -> getPosX() + 1, this -> getPosY() + 2)) || ((board -> getBoardPos(this -> getPosX() + 1, this -> getPosY() + 2) -> getColor() != this -> getColor()))))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + 1, this -> getPosY() + 2));
    }
    
    if((board -> checkInBounds(this -> getPosX() - 1, this -> getPosY() + 2)) && ((board -> IsPosEmpty(this -> getPosX() - 1, this -> getPosY() + 2)) || ((board -> getBoardPos(this -> getPosX() - 1, this -> getPosY() + 2) -> getColor() != this -> getColor()))))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() - 1, this -> getPosY() + 2));
    }
    
    if((board -> checkInBounds(this -> getPosX() + 2, this -> getPosY() + 1)) && ((board -> IsPosEmpty(this -> getPosX() + 2, this -> getPosY() + 1)) || ((board -> getBoardPos(this -> getPosX() + 2, this -> getPosY() + 1) -> getColor() != this -> getColor()))))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + 2, this -> getPosY() + 1));
    }
    
    if((board -> checkInBounds(this -> getPosX() + 2, this -> getPosY() - 1)) && ((board -> IsPosEmpty(this -> getPosX() + 2, this -> getPosY() - 1)) || ((board -> getBoardPos(this -> getPosX() + 2, this -> getPosY() - 1) -> getColor() != this -> getColor()))))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + 2, this -> getPosY() - 1));
    }

    return possibleMoves;
}