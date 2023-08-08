#include <iostream>
using namespace std;
#include <string>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(string n="") : name(n) { }
    Animal(Animal& an):name(an.name){cout<<"--Animal copy ctor"<<endl;}
    virtual void sing() { cout<< "-- animal "<<name<<" sings!"<<endl; }

  public:
    string name;
};

class Bird : public Animal
{
  public:
    Bird(string n="") : Animal(n) { }
    virtual void sing() { cout<< "-- bird "<<name<<" say tweet-tweet!"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(string n="") : Bird(n) { }
    virtual void sing() { cout<< "-- chicken "<<name<<" say cluck-cluck!"<<endl; }
    
};

void makeSing(Animal a);
//void makeSing(Chicken& c);
void makeSing(Animal* a);
//void makeSing(Chicken* c);


int main()
{
 
  Chicken redHen("Little Red Hen");
  
  Animal*  ap1 = &redHen;
  Chicken* cp = &redHen;

  Animal& ar1 = redHen;
  Chicken& cr1 = redHen;

  cout << "Chicken using Animal pointer"<<endl;
  //makeSing(ap1);
  ap1->sing();
  cout << "Chicken using Animal reference"<<endl;
  //makeSing(ar1);
  ar1.sing();
  cout << "Chicken using Chicken pointer"<<endl;
  //makeSing(cp);
  cp->sing();
  cout << "Chicken using Chicken reference"<<endl;
  makeSing(cr1);
  //cr1.sing();

  
  return 0;
}

void makeSing(Animal a){
  cout<<"Animal reference sing"<<endl;
  a.sing();
}
void makeSing(Chicken& c){
  cout<<"Chicken reference sing"<<endl;
  c.sing();
}
void makeSing(Animal* a){
  cout<<"Animal pointer sing"<<endl;
  a->sing();
}
void makeSing(Chicken* c){
  cout<<"Chicken pointer sing"<<endl;
  c->sing();
}