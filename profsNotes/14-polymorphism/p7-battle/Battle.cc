
#include "Battle.h"

Battle::Battle():round(0){
    chars[0]= &hero;
    chars[1] = &orc;
}

bool Battle::isOver(){
    return (hero.isDead() || orc.isDead());
}

void Battle::update(){


    for (int i = 0; i < 2; ++i){
        chars[i]->update();
    }

    board.reset();

    if (hero.getPosition() == orc.getPosition()){
        //they've collided
        board.setCharacter('X', hero.getPosition());
        hero.collide();
    }else{
       for (int i = 0; i < 2; ++i){
            board.setCharacter(chars[i]->getAvatar(), chars[i]->getPosition());
        }
    }

    //hero is faster and swings first
    orc.getHit(hero.getSwing());

    if (!orc.isDead()){
        hero.getHit(orc.getSwing());
    }

    cout<<"Round: "<<(++round)<<"      ||";
    board.print();
    cout<<" || ";
    for (int i = 0; i < 2; ++i){
           chars[i]->print();
    }
    cout<<endl;
}
