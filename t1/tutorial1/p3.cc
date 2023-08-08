#include<iostream>

using namespace std;
void power(int a, int b, int& c);

int main(){
	int n1, n2, total;
	cout << "Please Enter Two Integers"<<endl;
	cin >> n1;
    cin >> n2;
    power(n1,n2,total);
	cout << n1 << " to the power of  "<<n2<<" is "<<total<<endl;
	return 0;
}
