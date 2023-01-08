// HW08
// 許笙杰 E14075304 機械一乙
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// Length function
float length(float* vec) {
	float result = 0.0;
	for (int i = 0; i < 3; i++)
		result += pow(vec[i], 2);
	return sqrt(result);
}

// Normalise function
void normalise(float* vec, float& vec_length) {
	for (int i = 0; i < 3; i++)
		vec[i] /= vec_length;
}

// Addition function
float* addition(const float* vec1, const float* vec2) {
	return new float[3]{ vec1[0] + vec2[0],vec1[1] + vec2[1],vec1[2] + vec2[2] };
}

// Subtraction function
float* subtraction(const float* vec1, const float* vec2) {
	return new float[3]{ vec1[0] - vec2[0],vec1[1] - vec2[1],vec1[2] - vec2[2] };
}

// Dot function
float dot(const float* vec1, const float* vec2) {
	return vec1[0] * vec2[0] + vec1[1] * vec2[1] + vec1[2] * vec2[2];
}

// Cross function
float* cross(const float* vec1, const float* vec2) {
	return new float[3]{ vec1[1] * vec2[2] - vec1[2] * vec2[1],vec1[2] * vec2[0] - vec1[0] * vec2[2],vec1[0] * vec2[1] - vec1[1] * vec2[0] };
}

int main() {
	float* vector1 = new float[3];			// DMA for two vectors
	float* vector2 = new float[3];
	float* result = new float[3];			// DMA for result
	const float lower = 5.0;
	const float upper = 15.0;
	
	srand(time(NULL));						// Set random seed
	cout << fixed << setprecision(5);
	cout << "Vector 1:" << endl << "< ";	// Show vector1
	for (int i = 0; i < 3; i++) {
		vector1[i] = rand()*(upper - lower) / RAND_MAX + lower;
		cout << setw(8) << vector1[i] << (i == 2 ? " >" : ",");
	}
	cout << endl << endl;

	cout << "Vector 2:" << endl << "< ";	//Show vector2
	for (int i = 0; i < 3; i++) {
		vector2[i] = rand()*(upper - lower) / RAND_MAX + lower;
		cout << setw(8) << vector2[i] << (i == 2 ? " >" : ",");
	}
	cout << endl << endl;

	float length1 = length(vector1);		// Call length function
	float length2 = length(vector2);
	cout << "Length of Vector 1:" << endl << length(vector1) << endl << endl;		// Show length of two vectors
	cout << "Length of Vector 2:" << endl << length(vector2) << endl << endl;

	// Call normalise function and show unit vector of vector1 and vector2
	normalise(vector1, length1);
	cout << "Noramlised Vector 1:" << endl << "< ";
	for (int i = 0; i < 3; i++)
		cout << setw(8) << vector1[i] << (i == 2 ? " >" : ",");
	cout << endl << endl;

	normalise(vector2, length2);
	cout << "Noramlised Vector 2:" << endl << "< ";
	for (int i = 0; i < 3; i++)
		cout << setw(8) << vector2[i] << (i == 2 ? " >" : ",");
	cout << endl << endl;

	result = addition(vector1, vector2);	// Call addition function
	cout << "Addition:" << endl << "< ";
	for (int i = 0; i < 3; i++)				// Show vector1 + vector2
		cout << setw(8) << result[i] << (i == 2 ? " >" : ",");
	cout << endl << endl;

	result = subtraction(vector1, vector2);	// Call subtraction function
	cout << "Subtraction:" << endl << "< ";
	for (int i = 0; i < 3; i++)				// Show vector1 - vector2
		cout << setw(8) << result[i] << (i == 2 ? " >" : ",");
	cout << endl << endl;

	cout << "Dot product:" << endl << dot(vector1, vector2) << endl << endl;	// Call dot function and show result

	result = cross(vector1, vector2);		// Call cross function
	cout << "Cross product:" << endl << "< ";
	for (int i = 0; i < 3; i++)				// Show vector1 x vector2
		cout << setw(8) << result[i] << (i == 2 ? " >" : ",");
	cout << endl << endl;

	// Delete DMA
	delete[] vector1;
	delete[] vector2;
	delete[] result;
	system("pause");
	return 0;
}