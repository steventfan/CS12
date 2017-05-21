#include <iostream>

#include "IntList.h"

using namespace std;

IntList::IntList() : head(0), tail(0) {}
    
IntList::~IntList() {
    /*IntNode *tempHead = head;
    while (tempHead != 0) {
        head = head->next;
        delete tempHead;
        tempHead = head;
    }*/
    clear();
}

void IntList::display() const {
    IntNode *dataAt = head;
    
    while (dataAt != 0) {
        cout << dataAt->data;
        if (dataAt->next != 0) {
            cout << ' ';
        }
        dataAt = dataAt->next;
    }
    
    return;
}

void IntList::push_front(int value) {
    IntNode *tempHeads = new IntNode(value);
    if (head == 0) {
        tail = tempHeads;
    }
    tempHeads->next = head;
    head = tempHeads;
    
    return;
}

void IntList::pop_front() {
    if (!empty() ) {
        IntNode *tempHeader = head->next;
        delete head;
        head = tempHeader;
    }
    
    return;
}

bool IntList::empty() const {
    return head == 0;
}

IntList::IntList(const IntList &cpy) {
    head = 0;
    tail = 0;
    IntNode *copyVal = 0;
    
    copyVal = cpy.head;
    while (copyVal != 0) {
        push_back(copyVal->data);
        copyVal = copyVal->next;
    }
}

IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        this->clear();
        IntNode *copyVals = 0;
        copyVals = rhs.head;
        while (copyVals != 0) {
            this->push_back(copyVals->data);
            copyVals = copyVals->next;
        }
    }
    
    return *this;
}

void IntList::push_back(int value) {
    IntNode *tempoHead = new IntNode(value);
    if (empty() ) {
        head = tempoHead;
        tail = tempoHead;
    }
    else {
        tail->next = tempoHead;
        tail = tempoHead;
    }
}

void IntList::clear() {
    IntNode *dataAtx = head;
    
    while (dataAtx != 0) {
        head = head->next;
        delete dataAtx;
        dataAtx = head;
    }
    head = 0;
    tail = 0;
    // while (head != 0) {
    //     IntNode *dataAtx = head->next;
    //     delete head;
    //     head = dataAtx;
    // }
    // head = 0;
    // tail = 0;
}

void IntList::selection_sort() {
    IntNode *tempVals1 = head;
    IntNode *tempVals2 = head;
    int tempVal = 0;
    
    while (tempVals1 != 0) {
        tempVals2 = tempVals1->next;
        while (tempVals2 != 0) {
            if (tempVals1->data > tempVals2->data) {
                tempVal = tempVals1->data;
                tempVals1->data = tempVals2->data;
                tempVals2->data = tempVal;
            }
            tempVals2 = tempVals2->next;
        }
        tempVals1 = tempVals1->next;
    }
    
    return;
}

void IntList::insert_ordered(int value) {
    if (empty() || tail->data < value) {
        push_back(value);
    }
    else if (head->data >= value) {
        push_front(value);
    }
    else {
        IntNode *tempValu1 = head;
        IntNode *tempValu2 = head;
        IntNode *insertNode = new IntNode(value);
        bool foundData = false;
        while (tempValu1 != 0 && !foundData) {
            tempValu2 = tempValu1->next;
            if (tempValu2->data >= value) {
                tempValu1->next = insertNode;
                insertNode->next = tempValu2;
                foundData = true;
            }
            tempValu1 = tempValu1->next;
        }
    }
    
    return;
}

void IntList::remove_duplicates() {
    //if ( !(empty() || head == tail) ) {
        IntNode *tempVal1 = head;
        IntNode *tempVal2 = head;
        IntNode *tempVal3 = head;
        while (tempVal1 != 0) {
            tempVal3 = tempVal1;
            tempVal2 = tempVal1->next;
            while (tempVal2 != 0) {
                if (tempVal1->data == tempVal2->data) {
                    // tempVal3->next = tempVal2->next;
                    // delete tempVal2;
                    tempVal2 = tempVal3->next;
                    if (tempVal2 == 0) {
                        tail = tempVal3;
                    }
                    tempVal3->next = tempVal2->next;
                    delete tempVal2;
                    tempVal2 = 0;
                }
                else {
                    tempVal3 = tempVal3->next;
                    //tempVal2 = tempVal2->next;
                }
                tempVal2 = tempVal3->next;
            }
            tempVal1 = tempVal1->next;
        }
            
    //}
    
    return;
}

ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode *dataA = rhs.head;
    while (dataA != 0) {
        out << dataA->data;
        if (dataA->next != 0) {
            out << ' ';
        }
        dataA = dataA->next;
    }
    
    return out;
}