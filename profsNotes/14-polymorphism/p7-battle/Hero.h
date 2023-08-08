
#ifndef HERO_H
#define HERO_H

#include <iostream>
#include <string>
#include "Character.h"
#include "Swing.h"


using namespace std;

class Hero: public Character {
		
	public:
		//constructor
		Hero();
		
		virtual void update();
		void print() const;
		void collide();
	
	private:
		

	
};
#endif