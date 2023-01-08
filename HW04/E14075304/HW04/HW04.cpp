//HW04
//許笙杰 機械111乙班 E14075304

#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

int main() {
	unsigned int parking_time, shopping, member;
	int parking_fee, total, spend, grade, pay, change, discount = 0;
	double discount_rate;

	cout << "Please enter parking time (in minutes) : ";		//Ask users to enter their parking time
	cin >> parking_time;

	if (cin.fail())												//Error message
	{
		cout << "ERROR" << endl;
		system("pause");
		return 0;
	}

	if (parking_time < 20) 
	{									//Calculate parking fee based on parking time
		cout << "Free parking!" << endl;
		system("pause");
		return 0;
	}
	else if (parking_time >= 20 && parking_time <= 420)
		parking_fee = (parking_time / 20) * 15 + 15;
	else
		parking_fee = 300;

	cout << "Parking time : "									//Show parking time and parking fee
		<< parking_time / 60 << (parking_time / 60 == 1 ? " hour " : " hours ")
		<< parking_time % 60 << (parking_time % 60 == 1 ? " minute " : " minutes ")
		<< endl;
	cout << "Parking fee : $" << parking_fee << endl;
	cout << endl;

	cout << "Shopping here?" << endl
		<< "1 : YES" << endl
		<< "0 : NO " << endl;
	cin >> shopping;
	cout << endl;

	if (shopping > 1 || cin.fail())						//Error message
	{							
		cout << "ERROR" << endl;
		system("pause");
		return 0;
	}

	if (shopping == 1)									//Ask users to enter their spend if they go shopping
	{										
		cout << "How much do you spend?" << endl;
		cin >> spend;


		if (cin.fail())												//Invalid input,error
		{
			cout << "Please enter a NUMBER!" << endl;
			system("pause");
			return 0;
		}

		discount = spend / 500 * 20;								//Calculate the discount
		cout << "Discount : $" << discount;
		cout << endl << endl;
	}

	if (parking_fee - discount < 0)								//Free parking if parking fee has already discounted
	{							
		cout << "Free parking!" << endl;
		system("pause");
		return 0;
	}

	cout << "Member?" << endl									//Are they member?
		<< "1 : YES" << endl
		<< "0 : NO" << endl;
	cin >> member;
	cout << endl;

	if (member > 1 || cin.fail())				//Error message
	{								
		cout << "ERROR" << endl;
		system("pause");
		return 0;
	}

	if (member == 1)							//Select their member grade
	{											
		cout << "Grade of member?" << endl
			<< "1 : BRONZE" << endl
			<< "2 : SILVER" << endl
			<< "3 : GOLD" << endl;
		cin >> grade;
		cout << endl;

		switch (grade)							//Show grade information and decide discount rate
		{										
		case 1:
			cout << "Grade : Bronze" << endl;
			cout << "5% off";
			discount_rate = 0.95;
			break;
		case 2:
			cout << "Grade : Silver" << endl;
			cout << "15% off";
			discount_rate = 0.85;
			break;
		case 3:
			cout << "Grade : Gold" << endl;
			cout << "25% off";
			discount_rate = 0.75;
			break;
		}
	}
	else
		discount_rate = 1;
	cout << endl;

	total = round((parking_fee - discount) * discount_rate);		//Calculate total

	if (total < 0)											//Free if total is smaller than 0
	{												
		cout << "Free parking!" << endl;
		system("pause");
		return 0;
	}

	cout << "Total : $" << total << endl << endl;					//Show total and ask users to enter their payment
	cout << "Please enter amount you paid." << endl;
	cin >> pay;
	cout << endl;

	if (cin.fail())													//Invalid input, error
	{
		cout << "Please enter a NUMBER." << endl;
		system("pause");
		return 0;
	}

	change = pay - total;											//Calculate the change

	if (change < 0)													//Money is not enough
	{												
		cout << "Money is not enough." << endl;
		system("pause");
		return 0;
	}
	else															//Show changes
	{															
		cout << "CHANGE" << endl
			<< "$10 : " << change / 10 << endl;
		change %= 10;

		cout << "$5 : " << change / 5 << endl;
		change %= 5;

		cout << "$1 : " << change << endl;
	}
	system("pause");
	return 0;
}