#ifndef CHARACTER_H //Header guard
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character {
		
	public:
        //Constructor
	Character(const string& name, int maxHealth, int damage);

        //Functions
        void takeDamage(int damage);
        int strike();
        void print();

        //getters
        string getName();
	
	private:
        //Variables
        string name;
        int maxHealth, currentHealth, damage;
};
#endif
