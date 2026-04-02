#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayRun(int values[], int size);
bool hasRun(int values[], int size);

bool hasRun(int values[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (values[i] == values[i + 1])
            return true;
    }
    return false;
}

void displayRun(int values[], int size) {
    bool inRun = false;

    for (int i = 0; i < size; i++) {

        // Start of a run
        if (!inRun && i < size - 1 && values[i] == values[i + 1]) {
            cout << "(";
            inRun = true;
        }

        cout << values[i];

        // End of a run
        if (inRun && (i == size - 1 || values[i] != values[i + 1])) {
            cout << ")";
            inRun = false;
        }

        cout << " ";
    }

    cout << endl;
}

int main() {
    const int SIZE = 20;
    int arr[SIZE];

    srand(time(0));

    bool foundRun = false;

    while (!foundRun) {

        // Generate rolls
        for (int i = 0; i < SIZE; i++) {
            arr[i] = rand() % 6 + 1;
        }

        // Check run
        if (hasRun(arr, SIZE)) {
            cout << "has run: ";
            displayRun(arr, SIZE);
            foundRun = true;
        }
        else {
            cout << "no run: ";
            displayRun(arr, SIZE);
        }
    }

    return 0;
}