#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

enum CharType {WARRIOR, ELF, WIZARD};

const double MAX_HEALTH = 100.0;

class Character {
 protected:
    CharType type;
    string name;
    double health;
    double attackStrength;

 public:
     Character(CharType, const string &, double, double);
     CharType getType() const;
     const string & getName() const;
     /* Returns the whole number of the health value (static_cast to int). */
     int getHealth() const;
     void setHealth(double);
     /* Returns true if getHealth() returns an integer greater than 0, otherwise false */
     bool isAlive() const;
     virtual void attack(Character &) = 0;
 };

#endif