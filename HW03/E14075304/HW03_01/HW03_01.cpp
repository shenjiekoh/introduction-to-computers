//HW03_01
//許笙杰 機械111乙班 E14075304

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int num1, num2, and, or, xor;
	int min = 65;
	int max = 125;

	srand((unsigned int)time(0));
	num1 = (max - min) * rand() / RAND_MAX + min; 
	num2 = (max - min) * rand() / RAND_MAX + min;
	and = num1 & num2; 
	or = num1 | num2;
	xor = num1 ^ num2;

	cout << "Number 1 = " << num1 << "\t" << static_cast<char>(num1) << endl; 
	cout << "Number 2 = " << num2 << "\t" << static_cast<char>(num2) << endl;
	cout << num1 << " AND " << num2 << " = " << and << "\t" << static_cast<char>(and) << endl;
	cout << num1 << " OR " << num2 << " = " << or << "\t" << static_cast<char>(or) << endl;
	cout << num1 << " XOR " << num2 << " = " << xor << "\t" << static_cast<char>(xor) << endl;
	system("pause");
	return 0;
}