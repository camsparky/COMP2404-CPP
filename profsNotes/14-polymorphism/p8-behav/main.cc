#include <iostream>
using namespace std;
#include <string>
#include <vector>

#include "Animals.h"

int main()
{
  Bird*     birtrude = new Bird("Birtrude");
  Chicken*  redHen   = new Chicken("Little Red Hen");
  Cat*      lady     = new Cat("Dragon Lady");
  Pig*      wilbur   = new Pig("Wilbur");

  vector<Animal*> barnyard;

  barnyard.push_back(birtrude);
  barnyard.push_back(redHen);
  barnyard.push_back(lady);
  barnyard.push_back(wilbur);

  cout<<endl<<"Barnyard harmony:"<<endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->sing();

  cout<<endl<<"Barnyard dance:"<<endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->dance();

  // lady->spook(redHen);

  redHen->setDanceB(new CantDance);

  cout<<endl<<"Barnyard dance, after the break:"<<endl;
  for (int i=0; i<barnyard.size(); ++i)
    barnyard[i]->dance();


  return 0;
}

