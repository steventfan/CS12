#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

void readData(const string& dataFile, vector<double>& flightPathAngle, vector<double>& coefficientOfLift);
double interpolation(double userAngle, const vector<double>& flightPathAngle, const vector<double>& coefficientOfLift);
bool isOrdered(const vector<double>& flightPathAngle);
void reorder(vector<double>& flightPathAngle, vector<double>& coefficientOfLift);

int main () {
    string dataFile;
    
    cout << "Enter name of input data file:" << endl;
    cin >> dataFile;
    cout << endl;

    vector<double> flightPathAngle;
    vector<double> coefficientOfLift;
    
    readData(dataFile, flightPathAngle, coefficientOfLift);
    
    reorder(flightPathAngle, coefficientOfLift);
    
    isOrdered(flightPathAngle);
    
    double inputAngle;
    
    cout << "Input a flight path angle:";
    cin >> inputAngle;
    cout << endl;
    
    cout << interpolation(inputAngle, flightPathAngle, coefficientOfLift) << endl;

    return 0;
}

void readData(const string& dataFile, vector<double>& flightPathAngle, vector<double>& coefficientOfLift) {
    ifstream inFS;
    
    inFS.open(dataFile.c_str() );
    if (!inFS.is_open() ) {
        cout << "Error opening " << dataFile << endl;
        
        exit(1);
    }
    
    double dataInput;
    
    inFS >> dataInput;
    do {
            flightPathAngle.push_back(dataInput);
            inFS >> dataInput;
            coefficientOfLift.push_back(dataInput);
            inFS >> dataInput;
    } while (!inFS.eof() );
    
    inFS.close();
    
    return;
}

void reorder(vector<double>& flightPathAngle, vector<double>& coefficientOfLift) {
    for (unsigned i = 0; (i + 1) < flightPathAngle.size(); ++i) {
        for (unsigned j = i; (j + 1) < flightPathAngle.size(); ++j) {
            if (flightPathAngle.at(i) > flightPathAngle.at(j + 1) ) {
                iter_swap(flightPathAngle.begin() + i, flightPathAngle.begin() + (j + 1) );
                iter_swap(coefficientOfLift.begin() + i, coefficientOfLift.begin() + (j + 1) );
            }
        }
    }
    
    return;
}

bool isOrdered(const vector<double>& flightPathAngle) {
    for (unsigned i = 0; (i + 1) < flightPathAngle.size(); ++i) {
        if ( !(flightPathAngle.at(i) <= flightPathAngle.at(i + 1) ) ) {
            return false;
        }
    }
    
    return true;
}

double interpolation(double userAngle, const vector<double>& flightPathAngle, const vector<double>& coefficientOfLift) {
    for (unsigned i = 0; i < flightPathAngle.size(); ++i) {
        if (flightPathAngle.at(i) == userAngle) {
            return coefficientOfLift.at(i);
        }
    }
    
    int j = -1;
    int k = flightPathAngle.size();
    
    if (userAngle < flightPathAngle.at(0) ) {
        j = 0;
        k = 1;
    }
    else if (userAngle > flightPathAngle.at(flightPathAngle.size() - 1) ) {
        k = flightPathAngle.size() - 1;
        j = k - 1;
    }
    else {
        for (unsigned i = 0; i < flightPathAngle.size(); ++i) {
            if (userAngle > flightPathAngle.at(i) ) {
                ++j;
            }
        }
        for (int i = (flightPathAngle.size() - 1); i >= 0; --i) {
            if (userAngle < flightPathAngle.at(i) ) {
                --k;
            }
        }
    }
    
    return (coefficientOfLift.at(j) + ( (userAngle - flightPathAngle.at(j) ) / (flightPathAngle.at(k) - flightPathAngle.at(j) ) ) * (coefficientOfLift.at(k) - coefficientOfLift.at(j) ) );
}