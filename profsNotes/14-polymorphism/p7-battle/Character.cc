
#include "Character.h"

Character::Character(int pos, char av, int h): position(pos), avatar(av), health(h){
}

int Character::getPosition(){return position;}

const Swing& Character::getSwing(){return swing;}

void Character::getHit(const Swing& swing){
    if (position >= swing.left && position <= swing.right){
        //we've been hit
        health -= swing.damage;
    }
}


char Character::getAvatar(){return avatar;}

int Character::getHealth(){return health;}

bool Character::isDead(){return health <= 0;}