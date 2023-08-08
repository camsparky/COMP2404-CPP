#include <iostream>
using namespace std;
#include <string>
#include <vector>

// VERY BAD PACKAGING

class Animal
{
  public:
    Animal(string n="") : name(n) { }
    Animal(const Animal& an):name(an.name){cout<<"--Animal copy ctor"<<endl;}
    virtual void sing() { cout<< "-- animal "<<name<<" sings!"<<endl; }

  protected:
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

class Cat : public Animal
{
  public:
    Cat(string n="") : Animal(n) { }
    virtual void sing() { cout<< "-- cat "<<name<<" say meow!"<<endl; }
};


int main()
{
  Animal  gertrudeObj("Gertrude");
  Bird    birtrudeObj("Birtrude");
  Chicken redHenObj("Little Red Hen");
  Cat     ladyObj("Dragon Lady");

  Animal*  gertrude = new Animal("Gertrude");
  Bird*    birtrude = new Bird("Birtrude");
  Chicken* redHen   = new Chicken("Little Red Hen");
  Cat*     lady     = new Cat("Dragon Lady");

  vector<Animal> barnyardObj;
  vector<Animal*> barnyard;

  // Animal ams[3];

  // ams[0] = birtrudeObj;

  // cout<<"Two birds singing!"<<endl;
  // birtrudeObj.sing();
  // ams[0].sing();



  barnyardObj.push_back(gertrudeObj);
  barnyardObj.push_back(birtrudeObj);
  barnyardObj.push_back(redHenObj);
  barnyardObj.push_back(ladyObj);

  barnyard.push_back(gertrude);
  barnyard.push_back(birtrude);
  barnyard.push_back(redHen);
  barnyard.push_back(lady);

  cout << endl << "Barnyard harmony using objects..." << endl;
  for (int i=0; i<barnyardObj.size(); ++i)
    barnyardObj[i].sing();

  cout << endl << "Barnyard harmony using pointers..." << endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->sing();

  cout<<"Girtrude 1 sings:"<<endl;
    gertrudeObj.sing();

  // Animal animal;
  // animal = redHenObj;

  

  // cout<<"Redhen copied into an animal using the assignment operator"<<endl;
  // animal.sing();

  //Chicken* chick;
  //chick = &animal;
  

  return 0;
}

