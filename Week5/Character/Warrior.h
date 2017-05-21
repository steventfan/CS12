#ifndef WARRIOR_H
#define WARRIOR_H

#include <string>
#include "Character.h"

using namespace std;

class Warrior : public Character {
    public:
        Warrior(const string &, double, double, const string &);
        void attack(Character &);
    private:
        string allegiance;
};

#endif