//HW02_01
//機械111乙班 許笙杰 E14075304

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int length; //邊長
	double volume; //體積
	double surface_area; //表面積
	srand(time(0)); //隨機產生亂數
	length = rand(); //產生隨機長度
	volume = sqrt(2)*pow(length, 3) / 12; //體積公式
	surface_area = sqrt(3)*pow(length, 2); //表面積公式

	cout << "Length=" << length << endl; //輸出長度、體積和表面積
	cout << "Volume=" << volume << endl;
	cout << "Surface area=" << surface_area << endl;
	system("pause");
	return 0;
}