#include <iostream>
#include "IntList.h"

using namespace std;

IntList::IntList() {
    head = 0;
}

void IntList::push_front(int value) {
    IntNode *pushFront = new IntNode(value);
    if (head == 0) {
        head = pushFront;
    }
    else {
        pushFront->next = head;
        head = pushFront;
    }
    
    return;
}

ostream & operator<<(ostream &out, const IntList &list) {
    if (list.head != 0) {
        out << (list.head->data) << (list.head->next);
    }
    
    return out;
}

bool IntList::exists(int value) const {
    return exists(head, value);
}

bool IntList::exists(IntNode *dataAt, int value) const {
    if (dataAt != 0) {
        if (dataAt->data == value) {
            return true;
        }
        return exists(dataAt->next, value);
    }
    
    return false;
}

ostream & operator<<(ostream &out, IntNode *node) {
    if (node != 0) {
        out << ' ' << node->data << node->next;
    }
    
    return out;
}