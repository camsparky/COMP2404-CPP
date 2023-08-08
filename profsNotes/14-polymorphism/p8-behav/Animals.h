#ifndef ANIMALS_H
#define ANIMALS_H

#include <iostream>
#include <string>

using namespace std;

#include "DanceBehaviour.h"


class Animal
{
  public:
    Animal(string="");
    virtual void sing()  = 0;
    virtual void dance();
    void setDanceB(DanceBehaviour* db);
    
  protected:
    string name;
    DanceBehaviour* danceB;
};

class Bird : public Animal
{
  public:
    Bird(string="");
    virtual void sing();
};

class Chicken : public Bird
{
  public:
    Chicken(string="");
    virtual void sing();

};

class Cat : public Animal
{
  public:
    Cat(string="");
    virtual void sing();

  
};

class Pig : public Animal
{
  public:
    Pig(string="");
    virtual void sing();

};

#endif
