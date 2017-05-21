#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

int main() {
    SortedSet variable;
    SortedSet variable2;
    
    variable.push_back(4);
    variable.push_front(3);
    variable.insert_ordered(6);
    variable2.push_back(3);
    variable2.push_front(9);
    variable2.insert_ordered(6);
    
    variable = variable | variable2;
    
    cout << "EXPECTING: 3 4 6 9" << endl;
    cout << "ACTUAL: " << variable << endl;
    
    SortedSet variable3;
    SortedSet variable4;
    
    variable3.push_back(4);
    variable3.push_front(3);
    variable3.insert_ordered(6);
    variable4.push_back(3);
    variable4.push_front(9);
    variable4.insert_ordered(6);
    
    variable = variable3 & variable4;
    
    cout << "EXPECTING: 3 6" << endl;
    cout << "ACTUAL: " << variable << endl;
    
    return 0;
}