#include "Character.h"

Character::Character(const string& name, int maxHealth, int damage){
    this->damage = damage; //Initializing member variables
    this->currentHealth = maxHealth;
    this->maxHealth = maxHealth;
    this->name = name;
}

string Character::getName(){ return name; }
int Character::strike(){return damage;}

void Character::takeDamage(int damage){
    currentHealth = (currentHealth-damage)>=0 ? currentHealth-damage : 0; //If the players health drops below 0 set it back to 0.
}

void Character::print(){
    cout << name << "'s Health: " << currentHealth << endl;
}