#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"

using namespace std;

/* Sorts the contents of v into suit order,
   i.e., all clubs first (in numerically ascending order),
   then all diamonds (in ascending order),
   then all hearts (in ascending order),
   and finally all spades (in ascending order).
   Calls mergeSort recursive function to actually sort the vector.
*/
void sortBySuit(vector<Card> &v);

/* Uses the recursive merge sort algorithm to sort the contents
   of the vector from begin to end in suit order.
   (see above SortBySuit function for definition of suit order)
   Uses merge helper function to merge the two sorted
   halves.
*/
void mergeSort(vector<Card> &v, unsigned begin, unsigned end);

/* Assumes all values from begin to mid are in suit order,
   (see above SortBySuit function for definition of suit order)
   and all values from mid + 1 to end are in suit order.
   Merges the two halves so that all values from begin to end
   are in suit order.
*/
void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end);

bool cardCompare(const Card &, const Card &);

void sortBySuit(vector<Card> &v) {
   if (v.size() != 0) {
      mergeSort(v, 0, v.size() - 1);
   }
   
   return;
}

void mergeSort(vector<Card> &v, unsigned begin, unsigned end) {
    if (begin == end || end < 0) {
        return;
    }
    
   unsigned midpoint = (begin + end) / 2;
   mergeSort(v, begin, midpoint);
   mergeSort(v, midpoint + 1, end);
 
   merge(v, begin, midpoint, end);
   
   
   return;
}

void merge(vector<Card> &v, unsigned begin, unsigned mid, unsigned end) {
   vector<Card> tempHand(end - begin + 1);
   unsigned left = begin, right = mid + 1;
   unsigned i = 0;
   
   while (left <= mid && right <= end) {
      if (cardCompare(v.at(left), v.at(right) ) ) {
         tempHand.at(i) = v.at(left);
         ++left;
      }
      else {
         tempHand.at(i) = v.at(right);
         ++right;
      }
      ++i;
   }
   
   while (left <= mid) {
      // if (v.size() == 0) {
      //    break;
      // }
      tempHand.at(i) = v.at(left);
      ++i;
      ++left;
   }
   
   while (right <= end) {
      // if (v.size() == 0) {
      //    break;
      // }
      tempHand.at(i) = v.at(right);
      ++i;
      ++right;
   }
   
   for (unsigned j = 0; j < tempHand.size(); ++j) {
      v.at(begin + j) = tempHand.at(j);
   }
   
   return;
}

void fillHand(vector<Card> &hand, Deck &d, unsigned handSize) {
   hand.resize(handSize);
   for (unsigned i = 0; i < hand.size(); ++i) {
      hand.at(i) = d.dealCard();
   }
}

bool cardCompare(const Card &left, const Card &right) {
   if (left.getSuit() == right.getSuit() ) {
      return left.getRank() < right.getRank();
   }
   
   return left.getSuit() < right.getSuit();
}

//This is the function you implemented for PROGRAM 3
ostream & operator<<(ostream &, const vector<Card> &);

int main() {
   vector<Card> hand;
   Deck deck;
   int handSize;
   int seed;
   cout << "Enter seed value: ";
   cin >> seed;
   cout << endl;
   cout << "Enter hand size: ";
   cin >> handSize;
   cout << endl;

   srand(seed);
   deck.shuffleDeck();
   fillHand(hand, deck, handSize);
   cout << hand << endl;
   sortBySuit(hand);
   cout << hand << endl;
   return 0;
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