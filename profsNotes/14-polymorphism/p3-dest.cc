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

  protected:
    string name;
};

class Bird : public Animal
{
  public:
    Bird(string n="") : Animal(n) { }
    ~Bird() { cout << "-- bird " << name << " is destroyed!" << endl; }
    virtual void sing() { cout<< "-- bird "<<name<<" say tweet-tweet!"<<endl; }
};

class Chicken : public Bird
{
  public:
    Chicken(string n="") : Bird(n) { }
    ~Chicken() { cout << "-- chicken " << name << " is destroyed!" << endl; }
    virtual void sing() { cout<< "-- chicken "<<name<<" say cluck-cluck!"<<endl; }
};

class Cat : public Animal
{
  public:
    Cat(string n="") : Animal(n) { }
    ~Cat() { cout << "-- cat " << name << " is destroyed!" << endl; }
    virtual void sing() { cout<< "-- cat "<<name<<" say meow!"<<endl; }
};


int main()
{
  Animal*  gertrude = new Animal("Gertrude");
  Bird*    birtrude = new Bird("Birtrude");
  Chicken* redHen   = new Chicken("Little Red Hen");
  Cat*     lady     = new Cat("Dragon Lady");

  vector<Animal*> barnyard;

  barnyard.push_back(gertrude);
  barnyard.push_back(birtrude);
  barnyard.push_back(redHen);
  barnyard.push_back(lady);

  cout << endl << "Barnyard harmony..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->sing();


  cout << endl << "Barnyard slaughter..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    delete barnyard[i];

  return 0;
}

