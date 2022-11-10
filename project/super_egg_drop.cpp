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

using namespace std;


int kEggs, nFloors, floorF;
int attempt = 0;
int *breakMemory;

int eggDrop() {

    if (floorF == 1)
        return 1;

    return 0;
}

bool fallWillBreak(int xFloor) {

    if (breakMemory[xFloor] != 0) {
        return breakMemory[xFloor] == -1;
    }

    attempt++;

    // will break
    if (xFloor > floorF) {

        // record floor break
        breakMemory[xFloor] = -1;
        kEggs--;

        return true;
    }

    // record floor do not break
    breakMemory[xFloor] = 1;

    return false;
}

int findEggBreakFloor(int xFloor) {

    if (! fallWillBreak(xFloor)) {
        int x = xFloor + 1;

        if (fallWillBreak(x))
            return x;
    }

    return -1;
}

int main() {

    cout << "Enter the number of eggs = ";
    cin >> kEggs;

    cout << "Enter the number of floors = ";
    cin >> nFloors;


    cout << "Enter the floor number = ";
    cin >> floorF;


    breakMemory = new int[nFloors];

    int min = eggDrop();

    cout << min;

    return 0;
}