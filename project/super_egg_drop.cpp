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


int kEggs, nFloors, floorF;
int attempt = 0;
bool floorFound = false;

vector<int> breakMemory;

bool fallWillBreak(int xFloor) {

    if (breakMemory[xFloor - 1] != 0) {
        return breakMemory[xFloor - 1] == -1;
    }

    attempt++;

    // will break
    if (xFloor > floorF) {

        // record floor break
        breakMemory[xFloor - 1] = -1;
        kEggs--;

        return true;
    }

    // record floor do not break
    breakMemory[xFloor - 1] = 1;

    return false;
}

bool findEggBreakFloor(int xFloor) {

    if (! fallWillBreak(xFloor)) { // did not break at x
        int xPlus = xFloor + 1;

        if (fallWillBreak(xPlus)) { // break at x plus
            floorFound = true;
        }

        return true; // egg X alive

    } else if (xFloor > 1 && ! fallWillBreak(xFloor - 1)) {  // break at x and did not break at x minus
        floorFound = true;
    }

    return false; // egg X broke
}

void eggDrop() {

    int min = 1, max = nFloors;
    int xFloor = min + ((max - min) / 2);

    bool eggXAlive = findEggBreakFloor(xFloor);

    while (! floorFound && kEggs > 1) {

        if (eggXAlive) {
            min = xFloor;
        } else {
            max = xFloor;
        }

        xFloor = min + ((max - min) / 2);
        eggXAlive = findEggBreakFloor(xFloor);
    }

    while (! floorFound) {
        findEggBreakFloor(min);
        min++;
    }
}

int main() {

    cout << "Enter the number of eggs:";
    cin >> kEggs;

    cout << "Enter the number of floors:";
    cin >> nFloors;


    cout << "Enter the break floor number:";
    cin >> floorF;

    breakMemory = vector<int>(nFloors, 0);

    eggDrop();

    cout << "Attempt is " << attempt;

    return 0;
}