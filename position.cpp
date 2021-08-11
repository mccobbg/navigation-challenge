#include "position.h"

Direction Position::getLatitude() {
    return this->latitude;
}

Direction Position::getLongitude() {
    return this->longitude;
}

char Position::getFacing() {
    return this->facing;
}

void Position::turnRight(int degrees) {
    size_t start = directions.find(this->getFacing());
    if (start != string::npos && degrees <= 360 && degrees % 90 == 0) {
        int turn = (start + degrees / 90) % 4;
        this->facing = directions[turn];
    }
    cout << "turn right new facing : " << this->facing << endl;
}

void Position::turnLeft(int degrees) {
    size_t start = directions.find(this->getFacing());
    if (start != string::npos && degrees <= 360 && degrees % 90 == 0) {
        int turn = (start - degrees / 90) % 4;
        if (turn < 0) {
            turn += 4;
        }
        this->facing = directions[turn];
    }
    cout << "turn left new facing : " << this->facing << endl;
}

void Position::moveForward(int distance) {
    if (this->facing == 'N' || this->facing == 'S') { // longitude
        if (this->longitude.compassPoint == facing) {
            this->longitude.distance += distance;
        }
        else {
            this->longitude.distance -= distance;
            if (this->longitude.distance < 0) {
                this->longitude.distance = -this->longitude.distance;
                if (this->longitude.compassPoint == 'N') {
                    this->longitude.compassPoint = 'S';
                }
                else {
                    this->longitude.compassPoint = 'N';
                }
            }
        }
    }
    else if (this->facing == 'E' || this->facing == 'W') { // latitude
        if (this->latitude.compassPoint == facing) {
            this->latitude.distance += distance;
        }
        else {
            this->latitude.distance -= distance;
            if (this->latitude.distance < 0) {
                this->latitude.distance = -this->latitude.distance;
                if (this->latitude.compassPoint == 'E') {
                    this->latitude.compassPoint = 'W';
                }
                else {
                    this->latitude.compassPoint = 'E';
                }
            }
        }
    }
}

void Position::moveLatitude(char compassPoint, int distance) {
    if (compassPoint == this->latitude.compassPoint)
    {
        this->latitude.distance += distance;
    }
    else {
        this->latitude.distance -= distance;
        if (this->latitude.distance < 0) {
            this->latitude.distance = -latitude.distance;
            if (this->latitude.compassPoint == 'E') {
                this->latitude.compassPoint = 'W';
            }
            else {
                this->latitude.compassPoint = 'E';
            }
        }
    }
}

void Position::moveLongitude(char compassPoint, int distance) {
    if (compassPoint == this->longitude.compassPoint)
    {
        this->longitude.distance += distance;
    }
    else {
        this->longitude.distance -= distance;
        if (this->longitude.distance < 0) {
            this->longitude.distance = -longitude.distance;
            if (this->longitude.compassPoint == 'N') {
                this->longitude.compassPoint = 'S';
            }
            else {
                this->longitude.compassPoint = 'N';
            }
        }
    }
}
