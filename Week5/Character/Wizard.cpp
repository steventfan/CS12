#include <iostream>
#include <string>
#include "Wizard.h"
#include "Character.h"

using namespace std;

Wizard::Wizard(const string &nm, double hp, double atk, const int &rk) : Character(WIZARD, nm, hp, atk), rank(rk) {}

void Wizard::attack(Character &opponent) {
    if ( !(opponent.isAlive() ) ) {
        return;
    }
    
    double damage;
    
    if (opponent.getType() == WIZARD) {
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        
        damage = attackStrength * (static_cast<double>(rank) / static_cast<double>(opp.rank) );
    }
    else {
        damage = attackStrength;
    }
    
    opponent.setHealth(opponent.getHealth() - damage);
    
    cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
    if (opponent.isAlive() ) {
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else {
        cout << opponent.getName() << " is dead!" << endl;
    }
    
    return;
}