
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Board {
		
	public:
		//constructor
		Board();
		void reset();
		void setCharacter(char c, int pos);
		void print();
	
	private:
		char positions[5];
	
};
#endif