#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <iostream>
#include "IntList.h"

using namespace std;

class SortedSet : public IntList {
    public:
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();
        bool in(int) const;
        SortedSet & operator|(const SortedSet &) const;
        SortedSet & operator&(const SortedSet &) const;
        void add(int data);
        void push_front(int);
        void push_back(int);
        void insert_ordered(int);
        SortedSet & operator|=(const SortedSet &);
        SortedSet & operator&=(const SortedSet &);
};

#endif