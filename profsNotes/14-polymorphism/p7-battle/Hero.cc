
#include "Hero.h"
#include <time.h>
#include <cstdlib>

Hero::Hero(): Character(3, 'H', 20){

}



void Hero::update(){
    //dances
    position = rand()%5;
    //cout<<"Hero position "<<position<<endl;
    int direction = rand()%2;
    if (direction == 0){
        swing.right = position;
        swing.left = position -2;
        swing.damage = 5;
    }else{
        swing.left = position;
        swing.right = position +2;
        swing.damage = 5;
    }
}
		


void Hero::print() const{
     cout<<" Hero: "<<health;
     if (swing.left < position){
         cout<<" Swings left! ";
     }else{
         cout<<" Swings right!";
     }
}

void Hero::collide(){
    health -= 3;
}
