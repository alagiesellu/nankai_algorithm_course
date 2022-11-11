/***
 *
    ■ Super Egg Drop Introduction：

    You are given 𝑘 identical eggs and you have access to a building with 𝑛 floors labeled from 1 to 𝑛.
    You know that there exists a floor 𝑓 where 0 <= 𝑓 <= 𝑛 such that any egg dropped at a floor higher than 𝑓 will break,
    and any egg dropped at or below floor 𝑓 will not break. Each move, you may take an unbroken egg and drop it from any
    floor 𝑥 (where 1 <= 𝑥 <= 𝑛). If the egg breaks, you can no longer use it. However, if the egg does not break,
    you may reuse it in future moves. Return the minimum number of moves that you need to determine with certainty
    what the value of 𝑓 is.

**/

#include <iostream>
#include <vector>

using namespace std;

#define EGG_BROKE -1
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

    int min = 1, max = nFloors;
    int xFloor = min + ((max - min) / 2);

    bool eggAlive = findEggBreakFloor(xFloor);

    while (! floorFound && kEggs > 1) {

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

int getIntInput(string message) {

    int input;
    bool valid= false;

    do
    {
        cout << message << flush;
        cin >> input;
        if (cin.good()) {
            valid = true;
        } else {
            cin.clear();
            cout << "Invalid input; please re-enter." << endl;
        }
    } while (!valid);

    return input;
}

int main() {

    kEggs = getIntInput("Enter the number of eggs:");

    nFloors = getIntInput("Enter the number of floors:");

    floorF = getIntInput("Enter the break floor number:");

    breakMemory = vector<int>(nFloors, EGG_UNKNOWN);

    eggDrop();

    cout << "Attempt: " << attempt;

    return 0;
}