//HW05_02
//許笙杰 E14075304 機械一乙
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
	double theta1, theta2, theta3;														//Assume three random points on the unit circle (in polar coordinates)
	double percentage;																	//Ratio of triangles that contain the center
	int count = 0;																		//Number of triangles that contain the center
	const double upper_bound = 180;														//Upper bound of angle
	const double lower_bound = -180;													//Lower bound of angle
	const double pi = 3.14159265;
	srand(time(0));																		//Set random seed
	
	for (int i = 1; i <= 100000; i++) {													//Repeat actions below for 100000 times
		theta1 = rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound;			//Generate three coordinates (polar coordinates with r=1)
		theta2 = rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound;
		theta3 = rand()*(upper_bound - lower_bound) / RAND_MAX + lower_bound;

		if (theta1 < theta2)															//Let theta1 < theta2 (simplify 2 cases into 1 case)
		{
			if (theta1 >= 0 && theta2 >= 0) {											//Condition 1: Both positive
				if (theta3 <= theta2 - 180 && theta3 >= theta1 - 180)
					count++;
			}
			else if (theta1 < 0 && theta2 < 0) {										//Condition 2: Both negative
				if (theta3 <= theta2 + 180 && theta3 >= theta1 + 180)
					count++;
			}
			else {																		//Condition 3: Different sign
				if (theta3 >= theta1 + 180 && theta3 <= theta2 - 180)
					count++;
			}
		}

		if (theta3 < theta2)															//Let theta3 < theta2 (simplify 2 cases into 1 case)
		{
			if (theta3 >= 0 && theta2 >= 0) {											//Similar as above
				if (theta1 <= theta2 - 180 && theta1 >= theta3 - 180)
					count++;
			}
			else if (theta3 < 0 && theta2 < 0) {										
				if (theta1 <= theta2 + 180 && theta1 >= theta3 + 180)
					count++;
			}
			else {																		
				if (theta1 >= theta3 + 180 && theta1 <= theta2 - 180)
					count++;
			}
		}

		if (theta3 < theta1)															//Let theta3 < theta1 (simplify 2 cases into 1 case)
		{
			if (theta3 >= 0 && theta1 >= 0) {											//Simlar as above
				if (theta2 <= theta1 - 180 && theta2 >= theta3 - 180)		
					count++;
			}
			else if (theta3 < 0 && theta1 < 0) {										
				if (theta2 <= theta1 + 180 && theta2 >= theta3 + 180)
					count++;
			}
			else {																		
				if (theta2 >= theta3 + 180 && theta2 <= theta1 - 180)
					count++;
			}
		}
	}
	count *= 2;																			//Consider another case
	cout << "Number of triangles that contains center of circle = " << count << endl;	//Show result and percentage in two decimals
	cout << "Percentage = " << setprecision(4) << count / 1000.  << " %" << endl;
	system("pause");
	return 0;
}