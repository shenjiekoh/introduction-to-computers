//HW05_01
//許笙杰 E14075304 機械一乙
#include<iostream>
using namespace std;

int main() {
	double children = 2;								//Two children amoeba initially
	double adult = 0;									//No adult amoeba
	double temp;										//Change of the children amoeba per unit of time
	for (int time = 1; time <= 100; time++) {			//From t=1 to t=100
		temp = adult - children;
		adult += children;
		children += temp;
	}
	cout << "After 100 units of time," << endl			//Show result
		<< "Children amoeba = " << children << endl
		<< "Adult amoeba = " << adult << endl;
	system("pause");
	return 0;
}