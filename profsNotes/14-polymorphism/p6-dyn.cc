#include <iostream>
using namespace std;
#include <string>
#include <vector>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(string n="") : name(n) { }
    virtual ~Animal() { cout << "-- animal " << name << " is destroyed!" << endl; }
    virtual void sing() { cout<< "-- animal "<<name<<" sings!"<<endl; }
    virtual void dance() = 0;

  protected:
    string name;
};

class Bird : public Animal
{
  public:
    Bird(string n="") : Animal(n) { }
    virtual ~Bird() { cout << "-- bird " << name << " is destroyed!" << endl; }
    virtual void sing() { cout<< "-- bird "<<name<<" say tweet-tweet!"<<endl; }
    virtual void dance() { cout<< "-- bird "<<name<<" flies"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(string n="") : Bird(n) { }
    virtual ~Chicken() { cout << "-- chicken " << name << " is destroyed!" << endl; }
    virtual void sing() { cout<< "-- chicken "<<name<<" say cluck-cluck!"<<endl; }
    virtual void dance() { cout<< "-- chicken "<<name<<" does the chicken dance" << endl; }
};

class Cat : public Animal
{
  public:
    Cat(string n="") : Animal(n) { }
    virtual ~Cat() { cout << "-- cat " << name << " is destroyed!" << endl; }
    virtual void sing() { cout<< "-- cat "<<name<<" say meow!"<<endl; }
    virtual void dance() { cout<< "-- cat "<<name<<" pounces" << endl; }
};

class Pig : public Animal
{
  public:
    Pig(string n="") : Animal(n) { }
    virtual ~Pig() { cout << "-- pig " << name << " is destroyed!" << endl; }
    virtual void sing() { cout<< "-- pig "<<name<<" say oink!"<<endl; }
    virtual void dance() { cout<< "-- pig "<<name<<" rolls in the mud"<<endl; }
};


int main()
{
//  Animal*  gertrude = new Animal("Gertrude");
  Bird*    birtrude = new Bird("Birtrude");
  Chicken* redHen   = new Chicken("Little Red Hen");
  Cat*     lady     = new Cat("Dragon Lady");
  Pig*     wilbur   = new Pig("Wilbur");

  vector<Animal*> barnyard;

//  barnyard.push_back(gertrude);
  barnyard.push_back(birtrude);
  barnyard.push_back(redHen);
  barnyard.push_back(lady);
  barnyard.push_back(wilbur);

  cout << endl << "Barnyard harmony..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->sing();

  cout << endl << "Barnyard dance..." << endl;
  for (int i=0; i<barnyard.size(); ++i) {
    barnyard[i]->dance();
    Cat* cat = dynamic_cast<Cat*>(barnyard[i]);
    if (cat != 0){
      cout<<" and falls over trying to jump!"<<endl;
      cout<<" and then sings"<<endl;
      cat ->sing();
    }
  }

  cout << endl << "Barnyard slaughter..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    delete barnyard[i];


  return 0;
}

