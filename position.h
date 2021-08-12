#ifndef _POSITION_H
#define _POSITION_H
#include <iostream>

using namespace std;

const string directions = "NESW";

struct Direction {
    char direction;
    int distance;
};

class Position {
    public:
        Position(): latitude({'E', 0}),
                    longitude({'N', 0}),
                    facing('E') {}
        Direction& getLatitude();
        Direction& getLongitude();
        char& getFacing();
        void turnRight(const int &degrees);
        void turnLeft(const int &degrees);
        void moveForward(const int &distance);
        void moveLatitude(const char &direction, const int &distance);
        void moveLongitude(const char &direction, const int &distance);
    private:
        Direction latitude;
        Direction longitude;
        char facing;
};

#endif // _POSITION_H