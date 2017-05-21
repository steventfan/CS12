#include <iostream>

using namespace std;

const int ARRAY_MAX = 10;

double mean(const double array[], int arraySize);

void remove(double array[], int arraySize, int index);

void display(const double array[], int arraySize);

int main() {
    double mainArray[ARRAY_MAX];
    int indexRemove;
    int editSize;
    
    cout << "Enter " << ARRAY_MAX << " values:" << endl;
    for (int i = 0; i < ARRAY_MAX; ++i) {
        cin >> mainArray[i];
    }
    cout << endl;
    
    cout << "Mean: " << mean(mainArray, ARRAY_MAX) << endl << endl;
    
    cout << "Enter index of value to be removed: ";
    cin >> indexRemove;
    cout << endl;
    
    cout << "Before removing value: ";
    display(mainArray, ARRAY_MAX);
    cout << endl;
    
    remove(mainArray, ARRAY_MAX, indexRemove);
    editSize = ARRAY_MAX - 1;
    cout << "After removing value: ";
    display(mainArray, editSize);
    cout << endl;
    
    return 0;
}

double mean(const double array[], int arraySize) {
    double sumVal = 0;
    
    for (int i = 0; i < arraySize; ++i) {
        sumVal = sumVal + array[i];
    }
    
    return sumVal / arraySize;
}

void remove(double array[], int arraySize, int index) {
    for (int i = index; i <= arraySize - 1; ++i) {
        if (i == arraySize - 1) {
            return;
        }
        array[i] = array[i + 1];
    }
    
    return;
}

void display (const double array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        cout << array[i];
        if (i != arraySize - 1) {
            cout << ", ";
        }
    }
    
    return;
}