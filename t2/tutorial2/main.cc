using namespace std;
#include "Character.h"
#include "Battle.h"
#include <string>
#include <iostream>

int main()
{
    //Initializing fighter
    string tempString;
    int maxH, dmg;
    cout << "Enter a Name for the Fighter: ";
    cin >> tempString;
    cout << "Enter The Max Health for the Fighter: ";
    cin >> maxH;
    cout << "Enter the Damage for the Fighter: ";
    cin >> dmg;

    Character fighterMain(tempString, maxH, dmg);

    //Initializing ork
    cout << "Enter a Name for the Orc: ";
    cin >> tempString;
    cout << "Enter The Max Health for the Orc: ";
    cin >> maxH;
    cout << "Enter the Damage for the Orc: ";
    cin >> dmg;

    Character orcMain(tempString, maxH, dmg);

    //Fight simulation
    fighterMain.print();
    orcMain.print();

    Gondor::fight(fighterMain,orcMain);

    fighterMain.print();
    orcMain.print();

    Mordor::fight(fighterMain,orcMain);
    fighterMain.print();
    orcMain.print();
    return 0;
}