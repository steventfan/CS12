#include "Card.h"
#include "Deck.h"
#include <iostream>

Card::Card() {
    suit = 'c';
    rank = 2;
}

Card::Card(char suitVar, int rankVar) {
    if (tolower(suitVar) == 'd') {
        suit = 'd';
    }
    else if (tolower(suitVar) == 'h') {
        suit = 'h';
    }
    else if (tolower(suitVar) == 's') {
        suit = 's';
    }
    else {
        suit = 'c';
    }
    if (rankVar >= 1 || rankVar <= 13) {
        rank = rankVar;
    }
    else {
        rank = 2;
    }
}

char Card::getSuit() const {
    return suit;
}

int Card::getRank() const {
    return rank;
}

ostream & operator<<(ostream &out, const Card &rhs) {
    string outputRank;
    string outputSuit;
    
    if (rhs.getRank() == 1) {
        outputRank = "Ace";
    }
    else if (rhs.getRank() == 3) {
        outputRank = "3";
    }
    else if (rhs.getRank() == 4) {
        outputRank = "4";
    }
    else if (rhs.getRank() == 5) {
        outputRank = "5";
    }
    else if (rhs.getRank() == 6) {
        outputRank = "6";
    }
    else if (rhs.getRank() == 7) {
        outputRank = "7";
    }
    else if (rhs.getRank() == 8) {
        outputRank = "8";
    }
    else if (rhs.getRank() == 9) {
        outputRank = "9";
    }
    else if (rhs.getRank() == 10) {
        outputRank = "10";
    }
    else if (rhs.getRank() == 11) {
        outputRank = "Jack";
    }
    else if (rhs.getRank() == 12) {
        outputRank = "Queen";
    }
    else if (rhs.getRank() == 13) {
        outputRank = "King";
    }
    else {
        outputRank = "2";
    }
    
    if (rhs.getSuit() == 'd') {
        outputSuit = "Diamonds";
    }
    else if (rhs.getSuit() == 'h') {
        outputSuit = "Hearts";
    }
    else if (rhs.getSuit() == 's') {
        outputSuit = "Spades";
    }
    else {
        outputSuit = "Clubs";
    }
    
    out << outputRank << " of " << outputSuit;
    
    return out;
}