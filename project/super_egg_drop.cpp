/***
 *
    β  Super Egg Drop IntroductionοΌ

    You are given π identical eggs and you have access to a building with π floors labeled from 1 to π.
    You know that there exists a floor π where 0 <= π <= π such that any egg dropped at a floor higher than π will break,
    and any egg dropped at or below floor π will not break. Each move, you may take an unbroken egg and drop it from any
    floor π₯ (where 1 <= π₯ <= π). If the egg breaks, you can no longer use it. However, if the egg does not break,
    you may reuse it in future moves. Return the minimum number of moves that you need to determine with certainty
    what the value of π is.

**/

#include <iostream>
#include <vector>

using namespace std;

#define EGG_BROKE (-1)
#define EGG_ALIVE 1
#define EGG_UNKNOWN 0

int kEggs, nFloors, floorF;
int attempt = 0;
bool floorFound = false;

vector<int> breakMemory;

bool attemptDrop(int xFloor) {

    // record egg drop attempt
    attempt++;

    // if egg break at floor x
    return xFloor > floorF;
}

bool fallAndBreak(int xFloor) {

    int xFloorIndex = xFloor - 1;

    // if egg drop at floor x in memory
    if (breakMemory[xFloorIndex] != EGG_UNKNOWN) {
        return breakMemory[xFloorIndex] == EGG_BROKE;
    }

    // if egg break at floor x
    if (attemptDrop(xFloor)) {

        // remember that egg break at floor x
        breakMemory[xFloorIndex] = EGG_BROKE;
        kEggs--;

        return true;
    }

    // remember that egg do not break at floor x
    breakMemory[xFloorIndex] = EGG_ALIVE;

    return false;
}

bool findEggBreakFloor(int xFloor) {

    if (! fallAndBreak(xFloor)) { // did not break at x
        int xPlus = xFloor + 1;

        if (fallAndBreak(xPlus)) { // break at floor next to x
            floorFound = true;
        }

        return true; // egg X alive
    }

    // floor below and break at x and did not break at floor below x
    else if (xFloor > 1 && ! fallAndBreak(xFloor - 1)) {
        floorFound = true;
    }

    return false; // egg X broke
}

void eggDrop() {

    breakMemory = vector<int>(nFloors, EGG_UNKNOWN);

    bool eggAlive = true;

    int min = 1, max = nFloors, xFloor = 1;

    while (! floorFound && kEggs > 3) {

        if (eggAlive) {
            min = xFloor;
        } else {
            max = xFloor;
        }

        xFloor = min + ((max - min) / 2);
        eggAlive = findEggBreakFloor(xFloor);
    }

    while (! floorFound) {
        findEggBreakFloor(min);
        min++;
    }
}

void getIntegerInput(int& input, const string& message) {

    bool valid = false;

    do {
        cout << message << flush;
        cin >> input;

        if (cin.good()) {
            valid = true;
        } else {
            cin.clear();
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);
}

int main() {

    getIntegerInput(kEggs, "Enter the number of eggs:");

    getIntegerInput(nFloors, "Enter the number of floors:");

    getIntegerInput(floorF, "Enter the break floor number:");

    eggDrop();

    cout << "Attempt: " << attempt;

    return 0;
}