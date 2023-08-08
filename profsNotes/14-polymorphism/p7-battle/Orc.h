
#ifndef ORC_H
#define ORC_H

#include <iostream>
#include <string>
#include "Swing.h"
#include "Character.h"

using namespace std;

class Orc: public Character {
		
	public:
		//constructor
		Orc();
	
		virtual void update();
		
		virtual void print() const;
	
	private:
	
};
#endif