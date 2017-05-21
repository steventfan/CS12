#include <iostream>
#include <stdexcept>
#include "IntVector.h"

using namespace std;

IntVector::IntVector() : sz(0), cap(0), data(0) {}

IntVector::IntVector(unsigned size, int value) : sz(size), cap(size), data(new int[size]) {
    for (unsigned i = 0; i < size; i++) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
    cout << "DECONSTRUCTING" << endl;
    delete [] data;
}

unsigned IntVector::size() const {
    return sz;
}

unsigned IntVector::capacity() const {
    return cap;
}

bool IntVector::empty() const {
    return sz == 0;
}

const int & IntVector::at(unsigned index) const {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

int & IntVector::at(unsigned index) {
    if (index >= sz) {
        throw out_of_range("IntVector::at_range_check");
    }
    else {
        return data[index];
    }
}

void IntVector::insert(unsigned index, int value) {
    if (index >= sz + 1) {
        throw out_of_range("IntVector::insert_range_check");
    }
    if (sz + 1 > cap && cap == 0) {
        expand(1);
    }
    else if (sz + 1 > cap) {
        expand();
    }
    ++sz;
    for (unsigned i = sz - 1; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    
    return;
}

void IntVector::erase(unsigned index) {
    if (index >= sz) {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i < sz - 1; i++) {
        data[i] = data[i + 1];
    }
    --sz;
    
    return;
}

const int & IntVector::front() const {
    return data[0];
}

int & IntVector::front() {
    return data[0];
}

const int & IntVector::back() const {
    return data[sz - 1];
}

int & IntVector::back() {
    return data[sz - 1];
}

void IntVector::assign(unsigned n, int value) {
    if (cap < n) {
        expand();
        if (cap < n) {
            expand(n - cap);
        }
    }
    sz = n;
    for (unsigned i = 0; i < sz; i++) {
        data[i] = value;
    }
    
    return;
}

void IntVector::push_back(int value) {
    if (sz + 1 > cap) {
        if (cap == 0) {
            expand(1);
        }
        else {
            expand();
        }
    }
    ++sz;
    data[sz - 1] = value;
    
    return;
}

void IntVector::pop_back() {
    --sz;
    
    return;
}

void IntVector::clear() {
    sz = 0;
}

void IntVector::resize(unsigned size, int value) {
    if (size > cap) {
        expand();
        if (size > cap) {
            expand(size - cap);
        }
    }
    if (sz > size) {
        sz = size;
    }
    else if (sz < size) {
        for (unsigned i = sz; i < size; i++) {
            data[i] = value;
        }
        sz = size;
    }
    
    return;
}

void IntVector::reserve(unsigned n) {
    if (cap < n) {
        expand();
        if (cap < n) {
            expand(n - cap);
        }
    }
    
    return;
}

void IntVector::expand() {
    int *tempData = 0;
    
    tempData = data;
    cap = 2 * cap;
    data = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        data[i] = tempData[i];
    }
    delete[] tempData;
    
    return;
}

void IntVector::expand(unsigned amount) {
    int *tempData = 0;
    
    tempData = data;
    cap = cap + amount;
    data = new int[cap];
    for (unsigned i = 0; i < sz; i++) {
        data[i] = tempData[i];
    }
    delete[] tempData;
    
    return;
}