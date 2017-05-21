#include <iostream>
#include <string>

using namespace std;

void flipString(string &s);

int main() {
   string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString (string &s) {
    string tempString = " ";
    if (s.size() <= 1) {
        return;
    }
    else {
        tempString = s.substr(1, s.size() - 2);
        flipString(tempString);
        s = s.at(s.size() - 1) + tempString + s.at(0);
    }
    
    return;
}