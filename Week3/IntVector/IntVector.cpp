#include <stdexcept>
#include "IntVector.h"

using namespace std;

IntVector::IntVector() : sz(0), cap(0), data(0) {}

IntVector::IntVector(unsigned size, int value) : sz(size), cap(size), data(new int[size]) {
    for (unsigned i = 0; i < size; ++i) {
        data[i] = value;
    }
}

IntVector::~IntVector() {
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

const int & IntVector::front() const {
    return data[0];
}

const int & IntVector::back() const {
    return data[sz - 1];
}