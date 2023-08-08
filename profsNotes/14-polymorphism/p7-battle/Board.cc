
#include "Board.h"

Board::Board(){
    reset();
}

void Board::reset(){
    for (int i = 0; i < 5; ++i){
        positions[i] = ' ';
    }
}

void Board::setCharacter(char avatar, int pos){
    positions[pos] = avatar;
}


void Board::print(){
    for (int i = 0; i < 5; ++i){
        cout<< positions[i];
    }
}