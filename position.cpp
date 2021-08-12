#include "position.h"

Direction Position::getLatitude() const {
    return latitude;
}

Direction Position::getLongitude() const {
    return longitude;
}

char Position::getFacing() const {
    return facing;
}

void Position::turnRight(const int &degrees) {
    size_t start = directions.find(getFacing());
    if (start != string::npos && degrees <= 360 && degrees % 90 == 0) {
        int turn = (start + degrees / 90) % 4;
        facing = directions[turn];
    }
    cout << "turn right new facing : " << facing << endl;
}

void Position::turnLeft(const int &degrees) {
    size_t start = directions.find(getFacing());
    if (start != string::npos && degrees <= 360 && degrees % 90 == 0) {
        int turn = (start - degrees / 90) % 4;
        if (turn < 0) {
            turn += 4;
        }
        facing = directions[turn];
    }
    cout << "turn left new facing : " << facing << endl;
}

void Position::moveForward(const int &distance) {
    if (facing == 'N' || facing == 'S') { // longitude
        if (longitude.direction == facing) {
            longitude.distance += distance;
        }
        else {
            longitude.distance -= distance;
            if (longitude.distance < 0) {
                longitude.distance = -longitude.distance;
                if (longitude.direction == 'N') {
                    longitude.direction = 'S';
                }
                else {
                    longitude.direction = 'N';
                }
            }
        }
    }
    else if (facing == 'E' || facing == 'W') { // latitude
        if (latitude.direction == facing) {
            latitude.distance += distance;
        }
        else {
            latitude.distance -= distance;
            if (latitude.distance < 0) {
                latitude.distance = -latitude.distance;
                if (latitude.direction == 'E') {
                    latitude.direction = 'W';
                }
                else {
                    latitude.direction = 'E';
                }
            }
        }
    }
}

void Position::moveLatitude(const char &direction, const int &distance) {
    if (direction == latitude.direction) {
        latitude.distance += distance;
    }
    else {
        latitude.distance -= distance;
        if (latitude.distance < 0) {
            latitude.distance = -latitude.distance;
            if (latitude.direction == 'E') {
                latitude.direction = 'W';
            }
            else {
                latitude.direction = 'E';
            }
        }
    }
}

void Position::moveLongitude(const char &direction, const int &distance) {
    if (direction == longitude.direction) {
        longitude.distance += distance;
    }
    else {
        longitude.distance -= distance;
        if (longitude.distance < 0) {
            longitude.distance = -longitude.distance;
            if (longitude.direction == 'N') {
                longitude.direction = 'S';
            }
            else {
                longitude.direction = 'N';
            }
        }
    }
}
