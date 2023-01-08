//HW02_02
//機械111乙班 許笙杰 E14075304

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0)); //產生隨機亂數

	const double upper_bound = 90.0; //亂數上界
	const double lower_bound = -10.0; //亂數下界

	cout << setw(7) << "No.1" //顯示No.1至No.7
		 << setw(7) << "No.2"
		 << setw(7) << "No.3"
		 << setw(7) << "No.4"
		 << setw(7) << "No.5"
		 << setw(7) << "No.6"
		 << setw(7) << "No.7" 
		 << endl;
	cout << setw(7) << setprecision(3) << rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound //顯示7個不同的亂數
		 << setw(7) << setprecision(3) << rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound
		 << setw(7) << setprecision(3) << rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound
		 << setw(7) << setprecision(3) << rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound
		 << setw(7) << setprecision(3) << rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound
		 << setw(7) << setprecision(3) << rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound
		 << setw(7) << setprecision(3) << rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound
		 << endl;
	system("pause");
	return 0;
}