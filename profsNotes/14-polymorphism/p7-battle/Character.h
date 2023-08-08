
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "Swing.h"

using namespace std;

class Character {
		
	public:
		//constructor
		Character(int pos, char av, int h);

		int getPosition();
		virtual void update() = 0;
		//positive and negative distance
		const Swing& getSwing();
		void getHit(const Swing&);
		char getAvatar();
		int getHealth();
		bool isDead();	
	
		
		virtual void print() const = 0;
	
	protected:
		int position;
		char avatar;
		int health;
		Swing swing;
	
};
#endif