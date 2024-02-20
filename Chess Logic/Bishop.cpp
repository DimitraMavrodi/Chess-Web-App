#include "Bishop.hpp"
#include "Position.hpp"
#include "Board.hpp"

Bishop::Bishop(char name, char color, unsigned int value, int posX, int posY)
{
    this -> name = name;
    this -> color = color;
    this -> value = value;
    this -> posX = posX;
    this -> posY = posY;
}

Bishop::Bishop(Bishop& bishop)
{
    this -> name = bishop.name;
    this -> color = bishop.color;
    this -> value = bishop.value;
    this -> posX = bishop.posX;
    this -> posY = bishop.posY;
}

list<Position> Bishop::possiblePosToMove(Board *board)
{
    std::list<Position> possibleMoves;
    int i = 1;

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
        // std::cout << "=======================  ";
        // std::cout << i;
        // std::cout << "\n";
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