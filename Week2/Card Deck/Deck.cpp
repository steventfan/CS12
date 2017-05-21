#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Deck::Deck() {
    for (unsigned i = 13; i > 0; --i) {
        Card myDeck('s', i);
        theDeck.push_back(myDeck);
    }
    for (unsigned i = 13; i > 0; --i) {
        Card myDeck('h', i);
        theDeck.push_back(myDeck);
    }
    for (unsigned i = 13; i > 0; --i) {
        Card myDeck('d', i);
        theDeck.push_back(myDeck);
    }
    for (unsigned i = 13; i > 0; --i) {
        Card myDeck('c', i);
        theDeck.push_back(myDeck);
    }
}

Card Deck::dealCard() {
    dealtCards.push_back(theDeck.back() );
    theDeck.pop_back();
    
    return dealtCards.back();
}

void Deck::shuffleDeck() {
    for (unsigned i = 0; i < dealtCards.size(); ++i) {
        theDeck.push_back(dealtCards.at(i) );
    }
    random_shuffle(theDeck.begin(), theDeck.end() );
    
    return;
}

unsigned Deck::deckSize() const {
    return theDeck.size();
}