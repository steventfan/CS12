#include <string>
#include "Character.h"

using namespace std;

Character::Character(CharType type, const string &name, double health, double attackStrength) : type(type), name(name), health(health), attackStrength(attackStrength) {}

CharType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return static_cast<int>(health);
}

void Character::setHealth(double h) {
    health = h;
    
    return;
}

bool Character::isAlive() const {
    return getHealth() > 0;
}