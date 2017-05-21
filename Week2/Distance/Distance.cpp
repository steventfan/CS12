#include "Distance.h"

Distance::Distance() {
    feet = 0;
    inches = 0.0;
}

Distance::Distance(unsigned ft, double in) {
    feet = ft;
    inches = in;
    init();
}

Distance::Distance(double in) {
    feet = 0;
    inches = in;
    init();
}

unsigned Distance::getFeet() const {
    return feet;
}

double Distance::getInches() const {
    return inches;
}

double Distance::distanceInInches() const {
    return (feet * 12) + inches;
}

double Distance::distanceInFeet() const {
    return (inches / 12.0) + feet;
}

double Distance::distanceInMeters() const {
    return distanceInInches() * 0.0254;
}

const Distance Distance::operator+(const Distance &rhs) const {
    return Distance(feet + rhs.feet, inches + rhs.inches);
}

const Distance Distance::operator-(const Distance &rhs) const {
    return Distance(this->distanceInInches() - rhs.distanceInInches() );
}

ostream & operator<<(ostream &out, const Distance &rhs) {
    unsigned feetOutput = 0;
    double inchesOutput = 0.0;
    
    feetOutput = rhs.getFeet();
    inchesOutput = rhs.getInches();
    out << feetOutput << "' " << inchesOutput << "\"";
    
    return out;
}

void Distance::init() {
    if (inches < 0) {
        inches = -inches;
    }
    if (feet < 0) {
        feet = -feet;
    }
    while (inches >= 12) {
        inches = inches - 12;
        ++feet;
    }
    
    return;
}