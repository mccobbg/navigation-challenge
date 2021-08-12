#ifndef _NAVIGATE_H
#define _NAVIGATE_H
#include "position.h"

class Navigate
{
public:
    Navigate() {}
    void move(const string& move);
    void printPosition() const;
    void printManhattanDistance() const;
private:
    Position position;
};

#endif // _NAVIGATE_H

