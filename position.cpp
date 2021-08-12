#include "position.h"

Direction& Position::getLatitude() {
    return this->latitude;
}

Direction& Position::getLongitude() {
    return this->longitude;
}

char& Position::getFacing() {
    return this->facing;
}

void Position::turnRight(const int &degrees) {
    size_t start = directions.find(this->getFacing());
    if (start != string::npos && degrees <= 360 && degrees % 90 == 0) {
        int turn = (start + degrees / 90) % 4;
        this->facing = directions[turn];
    }
    cout << "turn right new facing : " << this->facing << endl;
}

void Position::turnLeft(const int &degrees) {
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

void Position::moveForward(const int &distance) {
    if (this->facing == 'N' || this->facing == 'S') { // longitude
        if (this->longitude.direction == facing) {
            this->longitude.distance += distance;
        }
        else {
            this->longitude.distance -= distance;
            if (this->longitude.distance < 0) {
                this->longitude.distance = -this->longitude.distance;
                if (this->longitude.direction == 'N') {
                    this->longitude.direction = 'S';
                }
                else {
                    this->longitude.direction = 'N';
                }
            }
        }
    }
    else if (this->facing == 'E' || this->facing == 'W') { // latitude
        if (this->latitude.direction == facing) {
            this->latitude.distance += distance;
        }
        else {
            this->latitude.distance -= distance;
            if (this->latitude.distance < 0) {
                this->latitude.distance = -this->latitude.distance;
                if (this->latitude.direction == 'E') {
                    this->latitude.direction = 'W';
                }
                else {
                    this->latitude.direction = 'E';
                }
            }
        }
    }
}

void Position::moveLatitude(const char &direction, const int &distance) {
    if (direction == this->latitude.direction)
    {
        this->latitude.distance += distance;
    }
    else {
        this->latitude.distance -= distance;
        if (this->latitude.distance < 0) {
            this->latitude.distance = -latitude.distance;
            if (this->latitude.direction == 'E') {
                this->latitude.direction = 'W';
            }
            else {
                this->latitude.direction = 'E';
            }
        }
    }
}

void Position::moveLongitude(const char &direction, const int &distance) {
    if (direction == this->longitude.direction)
    {
        this->longitude.distance += distance;
    }
    else {
        this->longitude.distance -= distance;
        if (this->longitude.distance < 0) {
            this->longitude.distance = -longitude.distance;
            if (this->longitude.direction == 'N') {
                this->longitude.direction = 'S';
            }
            else {
                this->longitude.direction = 'N';
            }
        }
    }
}
