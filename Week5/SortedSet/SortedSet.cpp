#include <iostream>
#include "SortedSet.h"
#include "IntList.h"

using namespace std;

SortedSet::SortedSet() {}

SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) {}

SortedSet::SortedSet(const IntList &cpy) : IntList(cpy) {
    selection_sort();
    remove_duplicates();
}

SortedSet::~SortedSet() {}

bool SortedSet::in(int data) const {
    if (!empty() ) {
        IntNode *dataAt = head;
        while (dataAt != 0) {
            if (dataAt->data == data) {
                return true;
            }
            dataAt = dataAt->next;
        }
    }
    
    return false;
}

SortedSet & SortedSet::operator|(const SortedSet &set) const {
    SortedSet *newSet = new SortedSet;
    if (this->empty() ) {
        if (set.empty() ) {
            return *newSet;
        }
        IntNode *dataAt = set.head;
        while (dataAt != 0) {
            newSet->add(dataAt->data);
            dataAt = dataAt->next;
        }
        
        return *newSet;
    }
    if (set.empty() ) {
        IntNode *dataAt = this->head;
        while (dataAt != 0) {
            newSet->add(dataAt->data);
            dataAt = dataAt->next;
        }
        
        return *newSet;
    }
    IntNode *dataAt1 = this->head;
    IntNode *dataAt2 = set.head;
    while (dataAt1 != 0) {
        newSet->add(dataAt1->data);
        dataAt1 = dataAt1->next;
    }
    while (dataAt2 != 0) {
        newSet->add(dataAt2->data);
        dataAt2 = dataAt2->next;
    }
    
    return *newSet;
}

SortedSet & SortedSet::operator&(const SortedSet &set) const {
    SortedSet *newSet = new SortedSet;
    if (this->empty() || set.empty() ) {
        return *newSet;
    }
    IntNode *dataAt = this->head;
    while (dataAt != 0) {
        if (set.in(dataAt->data) ) {
            newSet->add(dataAt->data);
        }
        dataAt = dataAt->next;
    }
    
    return *newSet;
}

void SortedSet::add(int data) {
    if (!in(data) ) {
        IntList::insert_ordered(data);
    }
    
    return;
}

void SortedSet::push_front(int data) {
    add(data);
    
    return;
}

void SortedSet::push_back(int data) {
    add(data);
    
    return;
}

void SortedSet::insert_ordered(int data) {
    add(data);
    
    return;
}

SortedSet & SortedSet::operator|=(const SortedSet &set) {
    SortedSet *newSet = new SortedSet;
    *newSet = *this | set;
    IntNode *dataAt = newSet->head;
    this->clear();
    while (dataAt != 0) {
        this->add(dataAt->data);
        dataAt = dataAt->next;
    }
    
    return *this;
}

SortedSet & SortedSet::operator&=(const SortedSet &set) {
    SortedSet *newSet = new SortedSet;
    *newSet = *this & set;
    IntNode *dataAt = newSet->head;
    this->clear();
    while (dataAt != 0) {
        this->add(dataAt->data);
        dataAt = dataAt->next;
    }
    
    return *this;
}