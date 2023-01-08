//HW06_01
//許笙杰 機械一乙 E14075304
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
	const int lower = 48;		// Lower bound
	const int upper = 122;		// Upper bound
	int count1 = 0, count2 = 0, count3 = 0;						// Number of elements in the arrays
	double average1 = 0, average2 = 0, average3 = 0;			// Average of elements
	char character[60] = {};	// Random characters
	char uppercase[30] = {};	// Uppercase alphabets
	char lowercase[30] = {};	// Lowercase alphabets
	int digit[20] = {};			// Digits
	
	srand(time(0));				// Set random seed
	for (int i = 0; i < 60; i++)	// Generate 60 random characters and store them in character[]
	{
		character[i] = rand()*(upper - lower) / RAND_MAX + lower;
		if (character[i] >= 48 && character[i] <= 57)			// Classify the characters
			digit[count1++] = static_cast<int>(character[i]);
		else if (character[i] >= 65 && character[i] <= 90)
			uppercase[count2++] = character[i];
		else if (character[i] >= 97 && character[i] <= 122)
			lowercase[count3++] = character[i];
	}
	
	cout << "Digits:\t\t\t";
	for (int i = 0; i < count1; i++)		// Calculate the average
	{
		cout << setw(3) << static_cast<char>(digit[i]);
		average1 += (digit[i] - 48);
	}
	average1 /= count1;
	cout << endl;
	
	cout << "Uppercase alphabets:\t";
	for (int i = 0; i < count2; i++)		// Calculate the average
	{
		cout << setw(3) << uppercase[i];
		average2 += uppercase[i];
	}
	average2 /= count2;
	cout << endl;

	cout << "Lowercase alphabets:\t";
	for (int i = 0; i < count3; i++)		// Calculate the average
	{
		cout << setw(3) << lowercase[i];
		average3 += lowercase[i];
	}
	average3 /= count3;
	cout << endl;

	// Output all results
	cout << "There are " << count1 << " digits, and their average is " << fixed << setprecision(3) << average1 << "." << endl
		<< "There are " << count2 << " uppercase alphabets, and their average is " << static_cast<char>(round(average2)) << "." << endl
		<< "There are " << count3 << " lowercase alphabets, and their average is " << static_cast<char>(round(average3)) << "." << endl;

	system("pause");
	return 0;
}