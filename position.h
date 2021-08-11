#ifndef _POSITION_H
#define _POSITION_H
#include <iostream>

using namespace std;

const string directions = "NESW";

struct Direction {
    char compassPoint;
    int distance;
};

class Position {
    public:
        Position(): latitude({'E', 0}),
                    longitude({'N', 0}),
                    facing('E') {}
        Direction getLatitude();
        Direction getLongitude();
        char getFacing();
        void turnRight(int degrees);
        void turnLeft(int degrees);
        void moveForward(int distance);
        void moveLatitude(char compassPoint, int distance);
        void moveLongitude(char compassPoint, int distance);
    private:
        Direction latitude;
        Direction longitude;
        char facing;
};

#endif // _POSITION_H