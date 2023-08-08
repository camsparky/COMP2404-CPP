#include <iostream>
using namespace std;
#include <string>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(const string& n="") : name(n) { }
    void sing() { cout<< "-- animal "<<name<<" sings!"<<endl; }

  protected:
    string name;
};

class Cat: public Animal{
  public:
    Cat(const string& name=""):Animal(name){}
    void sing() { cout<< "-- cat "<<name<<" meows!"<<endl; }
};

class Bird : public Animal
{
  public:
    Bird(const string& n="") : Animal(n) { }
    void sing() { cout<< "-- Bird "<<name<<" tweets!"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(const string& n="") : Bird(n) { }
    void sing() { cout<< "-- Chicken "<<name<<" clucks!"<<endl; }
};



int main()
{
  Animal  gertrude("Gertrude");
  Bird    birtrude("Birtrude");
  Chicken redHen("Little Red Hen");
  Cat     lady("Dragon Lady");

  Animal*  ap;
  Bird*    bp;
  Chicken* cp;

  cout << endl << "base ptr points to base object" << endl;
  ap = &gertrude;
  
  ap->sing();

  cout << "derived ptr points to derived object" << endl;
  bp = &birtrude;
  cp = &redHen;
 
  bp->sing();
  cp->sing();

  cout << endl << "base ptr points to derived object" << endl;
  ap = &lady;
  bp = &redHen;

  ap->sing();
  bp->sing();

  Animal& ar = redHen;
  ar.sing();

  //cp = &birtrude;



  //cout << endl << "base ptr points to derived object" << endl;
  
 


  return 0;
}

