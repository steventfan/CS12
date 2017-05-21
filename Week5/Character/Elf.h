#ifndef ELF_H
#define ELF_H

#include <string>
#include "Character.h"

using namespace std;

class Elf : public Character {
    public:
        Elf(const string &, double, double, const string &);
        void attack(Character &);
    private:
        string family;
};

#endif