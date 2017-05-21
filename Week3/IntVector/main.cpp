#include <iostream>
#include "IntVector.h"

using namespace std;

int main() {
    IntVector Test;
    cout << "TESTING VARIABLE Test" << endl;
    
    cout << "TESTING IntVector(), size(), capacity()" << endl;
    cout << "Expected: 0, 0" << endl;
    cout << "Actual: " << Test.size() << ", " << Test.capacity() << endl;
    
    cout << "TESTING empty()" << endl;
    cout << "Expected: true (1)" << endl;
    cout << "Actual: " << Test.empty() << endl;
    
    IntVector Test2(5, 9);
    cout << endl;
    cout << "TESTING VARIABLE Test2 using (5, 9)" << endl;
    
    cout << "TESTING IntVector(), size(), capacity()" << endl;
    cout << "Expected: 5, 5" << endl;
    cout << "Actual: " << Test2.size() << ", " << Test2.capacity() << endl;
    
    cout << "TESTING empty()" << endl;
    cout << "Expected: false (0)" << endl;
    cout << "Actual: " << Test2.empty() << endl;
    
    cout << "TESTING at() using index 0, 1, 2, 3, 4" << endl;
    cout << "Expected: 9, 9, 9, 9, 9" << endl;
    cout << "Actual: " << Test2.at(0) << ", " << Test2.at(1) << ", " << Test2.at(2) << ", " << Test2.at(3) << ", " << Test2.at(4) << endl;
    
    cout << "TESTING front()" << endl;
    cout << "Expected: 9" << endl;
    cout << "Actual: " << Test2.front() << endl;
    
    cout << "TESTING back()" << endl;
    cout << "Expected: 9" << endl;
    cout << "Actual: " << Test2.back() << endl;
    
    // cout << "TESTING at() out_of_range error using index 5" << endl;
    // cout << "IF PROGRAM ABORTS, TEST SUCCESSFUL" << endl;
    // cout << Test2.at(5) << " - Invalid Data" << endl;
    // cout << "Test Failed" << endl;
    
    cout << endl;
    cout << "Deconstructed Test and Test2" << endl;
    
    return 0;
}