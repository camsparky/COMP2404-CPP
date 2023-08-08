#include<iostream>

using namespace std;

void power(int a, int b, int& c){
    c=1;
    for(int x=0; x<b; x++){
        c = c*a;
    }
}