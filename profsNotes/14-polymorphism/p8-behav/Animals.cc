#include <iostream>
using namespace std;
#include <string>

#include "Animals.h"

Animal::Animal(string n) : name(n) 
{ 
  danceB = NULL;
}

void Animal::dance(){
  cout << "-- " << name;
  danceB->dance();
  cout << "!" << endl;
}

void Animal::setDanceB(DanceBehaviour* b)
{
  delete danceB;
  danceB = b;
}


Bird::Bird(string n) : Animal(n)     {
  danceB = new Fly; 
}
Chicken::Chicken(string n) : Bird(n) { 
  danceB = new DoChickenDance;
}
Cat::Cat(string n) : Animal(n)       { 
  danceB = new  Pounce;
}
Pig::Pig(string n) : Animal(n)       { 
  danceB = new Roll;
}

void Bird::sing()    { cout << "--bird " << name << " says tweet-tweet!" << endl; }
void Chicken::sing() { cout << "--chicken " << name << " says cluck-cluck!" << endl; }
void Cat::sing()     { cout << "--cat " << name << " says meow!" << endl; }
void Pig::sing()     { cout << "--pig " << name << " says oink!" << endl; }



