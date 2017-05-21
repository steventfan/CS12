#include <iostream>

using namespace std;

/* Returns true if a solution was found and false if there is no solution.
   x and y will contain a solution if a solution was found. 
   This function will NOT output anything.
*/
bool diophantine(int a, int b, int c, int &x, int &y);

int gcd(int num1, int num2, int i);

int main() {

    int a, b, c, x = 0, y = 0;

    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;
    cout << endl;
    cout << "Result: ";
    
    if (diophantine(a, b, c, x, y)) {
        cout << x << " " << y << endl;
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}

bool diophantine(int a, int b, int c, int &x, int &y) {
    int tempa = a, tempb = b, tempc = c;
    if (a < 0) {
        tempa = -a;
    }
    if (b < 0) {
        tempb = -b;
    }
    if (c < 0) {
        tempc = -c;
    }
    int varSize = 0;
    if (tempa <= tempb) {
        varSize = tempa;
    }
    else {
        varSize = tempb;
    }
    if (tempc % gcd(a, b, varSize) != 0) {
        return false;
    }
    
    if (a % b == 0) {
        x = 0;
        y = c / b;
        return true;
    }
    
    int u = 0, v = 0;
    if (!diophantine(b, a % b, c, u, v) ) {
        return false;
    }
    x = v;
    y = u - ( (a / b) * v);
    return true;
}

int gcd(int num1, int num2, int i) {
    if (num1 % i == 0 && num2 % i == 0) {
        return i;
    }
    --i;
    
    return gcd(num1, num2, i);
}