#include <iostream>

#include "IntList.h"

using namespace std;

IntList::IntList() : head(0), tail(0) {}
    
IntList::~IntList() {
    while (!empty() ) {
        pop_front();
    }
}

void IntList::display() const {
    IntNode *dataAt;
    
    dataAt = head;
    while (dataAt != tail && head != 0) {
        cout << dataAt->data;
        if (dataAt->next != tail) {
            cout << ' ';
        }
        dataAt = dataAt->next;
    }
    
    return;
}

void IntList::push_front(int value) {
    IntNode *tempHead;
        
    tempHead = new IntNode(value);
    tempHead->next = head;
    head = tempHead;
    if (empty() ) {
        tail = tempHead;
    }
    
    return;
}

void IntList::pop_front() {
    if (!empty() ) {
        if (head == tail) {
            delete head;
            head = 0;
            tail = 0;
        }
        else {
            IntNode *tempHead;
            
            tempHead = head;
            head = head->next;
            delete tempHead;
        }
    }
    
    return;
}

bool IntList::empty() const {
    return head == 0;
}