// HW07
// 許笙杰 機械111乙班 E14075304
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	const double lower = 40.5;
	const double upper = 100.0;
	int student = 0, test = 0, id = 0;

	cout << "Please enter the number of students: ";
	cin >> student;
	cout << "Please enter the number of tests: ";
	cin >> test;

	double **presult = new double*[student];		// Dynamic memory for result of every student
	double *paverage = new double[student];			// Dynamic memory to store students' average
	int *pid = new int[student];					// Dynamic memory to store students' ID

	for (int i = 0; i < student; i++)				// Dynamic memory to store the results of each student
		presult[i] = new double[test];

	// First row of results
	cout << setw(4) << "ID";

	for (int i = 1; i <= test; i++)
		cout << setw(6) << "test" << i;
	cout << endl;

	srand(time(0));		// Set random seed

	// Generate random results and output them
	for (int i = 0; i < student; i++) {
		cout << setw(4) << i + 1;
		for (int j = 0; j < test; j++) {
			presult[i][j] = rand()*(upper - lower) / RAND_MAX + lower;
			cout << setw(7) << fixed << setprecision(1) << presult[i][j];
		}
		cout << endl;
	}
	cout << endl;

	// First row of averages
	cout << "Students' average result:" << endl;
	cout << setw(4) << "ID" << setw(7) << "avg" << endl;

	// Calculate averages and output them
	for (int i = 0; i < student; i++) {
		paverage[i] = 0;
		cout << setw(4) << i + 1;
		for (int j = 0; j < test; j++) 
			paverage[i] += presult[i][j];
		paverage[i] /= test;
		cout << setw(7) << fixed << setprecision(1) << paverage[i] << endl;
	}

	// Separating line
	for (int i = 0; i <= test; i++)
		cout << "-------";
	cout << endl;

	// Enter ID to check results
	do {
		cout << "Check for your results, please enter your ID: ";
		cin >> id;

		if (id <= 0 || id > student || cin.fail())		//Invalid input
			break;

		for (int i = 1; i <= test; i++)
			cout << setw(6) << "test" << i;
		cout << setw(7) << "avg" << endl;
		for (int i = 0; i < test; i++) {
			cout << setw(7) << presult[id - 1][i];
		}
		cout << setw(7) << paverage[id - 1] << endl;
		cout << endl;
	} while (id <= student);

	// Clear dynamic memory
	for (int i = 0; i < student; i++)
		delete presult[i];
	delete[] presult;
	delete[] paverage;
	delete[] pid;
	
	system("pause");
	return 0;
}