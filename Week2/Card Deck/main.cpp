#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

/* Passes in a vector Cards and returns true if any 2 Cards have the same rank.
   Otherwise returns false.
*/
bool hasPair(const vector<Card> &);


/* Passes in a vector of Cards and outputs to the stream each Card
   separated by a comma and a space, 
   with no comma, space, or newline at the end.
*/
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
    string outputFile;
    string fileName;
    int numCards;
    int numSim;
    int pairTotal = 0;
    double percentChance;
    bool pendingRequest = true;
    bool pairDetect = false;
    Deck mainDeck;
    vector<Card> mainHand;
    ofstream outFS;
    
    srand(2222);
    
    while (pendingRequest) {
        cout << "Do you want to output all hands to a file?(Yes/No) ";
        cin >> outputFile;
        cout << endl;

        if (outputFile == "Yes") {
            cout << "Enter name of output file: ";
            cin >> fileName;
            cout << endl;
            pendingRequest = false;
        }
        else if (outputFile == "No") {
            pendingRequest = false;
        }
    }
    
    cout << "Enter number of cards per hand: ";
    cin >> numCards;
    cout << endl;
    
    cout << "Enter number of deals (simulations): ";
    cin >> numSim;
    cout << endl;
    
    if (outputFile == "Yes") {
        outFS.open(fileName.c_str() );
        if (!outFS.is_open() ) {
            cout << "Could not open file " << fileName << ". Aborting Program." << endl;
            
            return 1;
        }
    }

    for (int i = 1; i <= numSim; ++i) {
        mainDeck.shuffleDeck();
        for (int j = 1; j <= numCards; ++j) {
            mainHand.push_back(mainDeck.dealCard() );
        }
        if (hasPair(mainHand) ) {
            pairDetect = true;
            ++pairTotal;
        }
        if (outputFile == "Yes") {
            if (pairDetect == true) {
                outFS << "Found Pair!! ";
            }
            else {
                outFS << "             ";
            }
            outFS << mainHand << endl;
        }
    }
    if (outputFile == "Yes") {
        outFS.close();
    }
    percentChance = (static_cast<double>(pairTotal) / static_cast<double>(numCards) ) * static_cast<double>(numSim);
    
    cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << percentChance << "%" << endl;
    
    return 0;
}

bool hasPair(const vector<Card> &hand) {
    for (unsigned i = 0; i < hand.size() - 1; ++i) {
        for (unsigned j = i + 1; j < hand.size(); ++j) {
            if (hand.at(i).getRank() == hand.at(j).getRank() ) {
                return true;
            }
        }
    }
    
    return false;
}

ostream & operator<<(ostream &out, const vector<Card> &rhs) {
    for (unsigned i = 0; i < rhs.size(); ++i) {
        out << rhs.at(i);
        if (i != rhs.size() - 1) {
            out << ", ";
        }
    }
    
    return out;
}