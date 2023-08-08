#include "Battle.h"

void Gondor::fight(Character& fighter, Character& orc){
    cout << fighter.getName() << " Hits " << orc.getName() << " for " << fighter.strike()+1 << " Damage" <<endl;
    cout << orc.getName() << " Hits " << fighter.getName() << " for " << orc.strike()-1 << " Damage"<<endl;
    orc.takeDamage(fighter.strike()+1);
    fighter.takeDamage(orc.strike()-1);
}

void Mordor::fight(Character& fighter, Character& orc){
    cout << fighter.getName() << " Hits " << orc.getName() << " for " << fighter.strike()-1 << " Damage" <<endl;
    cout << orc.getName() << " Hits " << fighter.getName() << " for " << orc.strike()+1 << " Damage"<<endl;
    orc.takeDamage(fighter.strike()-1);
    fighter.takeDamage(orc.strike()+1);
}