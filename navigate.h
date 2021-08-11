#ifndef _NAVIGATE_H
#define _NAVIGATE_H
#include "position.h"

class Navigate
{
public:
    Navigate() {
        this->position = new Position();
    }
    void move(string move);
    void printPosition();
    void printManhattanDistance();
private:
    Position* position;
};

#endif // _NAVIGATE_H

