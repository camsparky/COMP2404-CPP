
#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <string>
#include "Hero.h"
#include "Orc.h"
#include "Board.h"

using namespace std;

class Battle {
		
	public:
		//constructor
		Battle();
		bool isOver();
		void update();	
	private:
		Board board;
		Hero hero;
		Orc orc;	
		Character* chars[2];
		int round;
};
#endif