#include <iostream>
#include <string>
#include "Battle.h"
#include <time.h>
#include <cstdlib>


using namespace std;



int main(){

    srand (time(NULL));

    Battle battle;

    while(!battle.isOver()){
        battle.update();
    }
    return 0;
}

