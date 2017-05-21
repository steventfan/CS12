#include <iostream>
#include <string>
#include "Warrior.h"
#include "Character.h"

using namespace std;

Warrior::Warrior(const string &nm, double hp, double atk, const string &ally) : Character(WARRIOR, nm, hp, atk), allegiance(ally) {}

void Warrior::attack(Character &opponent) {
    if ( !(opponent.isAlive() ) ) {
        return;
    }
    
    if (opponent.getType() == WARRIOR) {
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if (allegiance == opp.allegiance) {
            cout << "Warrior " << name << " does not attack Warrior " << opponent.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
            
            return;
        }
    }
    
    double damage = attackStrength * (health / MAX_HEALTH);
    
    opponent.setHealth(opponent.getHealth() - damage);
    
    cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
    if (opponent.isAlive() ) {
        cout << opponent.getName() << " takes " << damage << " damage." << endl;
    }
    else {
        cout << opponent.getName() << " is dead!" << endl;
    }
    
    return;
}