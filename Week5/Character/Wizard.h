#ifndef WIZARD_H
#define WIZARD_H

#include <string>
#include "Character.h"

using namespace std;

class Wizard : public Character {
    public:
        Wizard(const string &, double, double, const int &);
        void attack(Character &);
    private:
        int rank;
};

#endif