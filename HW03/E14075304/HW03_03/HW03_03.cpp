//HW03_03
//許笙杰 機械111乙班 E14075304

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float myPI; 

int main()
{
	{
		myPI = 25.0 / 8;
		cout << "1.  25/8\t="
			<< right << setw(10) 
			<< fixed << setprecision(5) 
			<< myPI << endl;
	}
	{
		myPI = pow(16.0 / 9, 2); 
		cout << "2.  (16/9)^2\t="
			<< setw(10)
			<< fixed << setprecision(5)
			<< myPI << endl;
	}
	{
		myPI = 355.0 / 113;
		cout << "3.  355/133\t="
			<< setw(10)
			<< fixed << setprecision(5)
			<< myPI << endl;
	}
	system("pause");
	return 0;
}