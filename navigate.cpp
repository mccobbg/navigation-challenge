#include <fstream>
#include "navigate.h"

void Navigate::move(const string& move) {
    int length = move.length();
    if (length > 1) {
        char action = move.front();
        int distance = stoi(move.substr(1, length-1));
        cout << "Move action: " << action << ", distance: " << distance << endl;

        switch (action) {
            case 'F': // move forward direction currently facing
                position.moveForward(distance);
                break;
            case 'L':
                position.turnLeft(distance);
                return;
            case 'R':
                position.turnRight(distance);
                return;
            case 'N':
            case 'S':
                position.moveLongitude(action, distance);
                break;
            case 'E': 
            case 'W':
                position.moveLatitude(action, distance);
                break;
            default: {
                // Error
            }
        }
    }
}

void Navigate::printPosition() const {
    Direction latitude = position.getLatitude();
    Direction longitude = position.getLongitude();
    string latitudeDirection = "east";
    if (latitude.direction == 'W') {
        latitudeDirection = "west";
    }
    string longitudeDirection = "north";
    if (longitude.direction == 'S') {
        longitudeDirection = "south";
    }
    char facing = position.getFacing();
    string facingDirection = "north";
    switch (facing) {
        case 'E':
            facingDirection = "east";
            break;
        case 'S':
            facingDirection = "south";
            break;
        case 'W':
            facingDirection = "west";
            break;
        default: {}
    }
    cout << "Facing: " << facingDirection << ", Position: ";
    cout << latitudeDirection << ' ' << latitude.distance << ", ";
    cout << longitudeDirection << ' ' << longitude.distance << endl;
}

void Navigate::printManhattanDistance() const {
    Direction latitude = position.getLatitude();
    Direction longitude = position.getLongitude();
    cout << "Manhattan distance: " << latitude.distance + longitude.distance << endl;
}

int main(int argc, char** argv) {

    if (argc == 1) {
        cerr << "Missing file name" << endl;
        cerr << "Syntax:" << endl;
        cerr << "./navigate <path of file containing navigation instructions>" << endl;
        return EXIT_FAILURE;
    }

    if (argc > 1) {
        string filename(argv[1]);
        Navigate nav;

        string line;
        ifstream input_file(filename);
        if (!input_file.is_open()) {
            cerr << "Could not open  file '" << filename << "'" << endl;
            return EXIT_FAILURE;
        }

        while (getline(input_file, line)) {
            nav.printPosition();
            nav.move(line);
        }
        nav.printPosition();
        input_file.close();

        nav.printManhattanDistance();
    }
    return EXIT_SUCCESS;
}