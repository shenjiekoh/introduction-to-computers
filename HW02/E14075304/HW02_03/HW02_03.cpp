//HW02_03
//機械111乙班 許笙杰 E14075304

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double x,y,z;

	cout << "Please enter x-coordinate : "; //輸入x坐標
	cin >> x;
	cout << "Please enter y-coordinate : "; //輸入y坐標
	cin >> y;
	cout << "Please enter z-coordinate : "; //輸入z坐標
	cin >> z;

	double r = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); //計算至原點的距離

	cout << "The distance between (0,0,0) and ("<< x << "," << y << "," << z << ") is " << fixed << setprecision(3) << r << endl; //輸出結果至三位小數
	system("pause");
	return 0;
}