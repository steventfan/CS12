#include <iostream>
#include <string>
#include "Elf.h"
#include "Character.h"

using namespace std;

Elf::Elf(const string &nm, double hp, double atk, const string &fam) : Character(ELF, nm, hp, atk), family(fam) {}

void Elf::attack(Character &opponent) {
    if (!(opponent.isAlive() ) ) {
        return;
    }
    
    if (opponent.getType() == ELF) {
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if (family == opp.family) {
            cout << "Elf " << name << " does not attack Elf " << opponent.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
            
            return;
        }
    }
    
    double damage = attackStrength * (health / MAX_HEALTH);
    
    opponent.setHealth(opponent.getHealth() - damage);
    
    cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
    if (opponent.isAlive() ) {
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else {
        cout << opponent.getName() << " is dead!" << endl;
    }
    
    return;
}