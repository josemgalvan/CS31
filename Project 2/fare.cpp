#include <iostream>
#include <string>
using namespace std;
//This code will accuretely calcule the fare for any given indivudal an apply the correspsonding discount
// it is comprised mostly of if and else statements
int main()
{
	//pre defining variables
	double boundaries;
	double fare;
	int numBound;
	double totalfare;
	int age;
	string student;
	cout << "Age of the rider: ";
	cin >> age;
	//clearing so inputs dont get overrided
	cin.ignore(10000, '\n');
	cout << "Student? (y/n): ";
	cin >> student;
	//clearing again
	cin.ignore(10000, '\n');
	string Destination;
	cout << "Destination: ";
	getline(cin, Destination, '\n');
	cout << "Number of zone boundaries crossed: ";
	cin >> numBound;
	//base case for no discounts
	fare = 1.55;
	boundaries = 0.55 * numBound;
	totalfare = fare + (boundaries);
	//set to 2 places after decimal point
	cout.setf(ios::fixed);
	cout.precision(2);
	//error messages first that way it wont try computing for unlogical inputs
	if (age < 0)
	{
		cout << "---" << endl;
		cout << "The age must not be negative" << endl;
	}
	else if ((student != "y") && (student != "n"))
	{
		cout << "---" << endl;
		cout << "You must enter y or n" << endl;
	}
	else if (Destination == "")
	{
		cout << "---" << endl;
		cout << "You must enter a destination" << endl;

	}
	else if (numBound < 0)
	{
		cout << "---" << endl;
		cout << "The number of zone boundaries crossed must not be negative" << endl;
	}
	//start with elderly 
	else if (age >= 65 && numBound == 0)
	{
		fare = .45;
		boundaries = 0;
		totalfare = fare + (boundaries);

		cout << "---" << endl;
		cout << "The fare to " << Destination << " is $" << totalfare << endl;
	}
	else if ((age < 18 || student == "y") && numBound <= 1)
	{
		fare = 0.65;
		boundaries = 0;
		totalfare = fare + (boundaries);

		cout << "---" << endl << "The fare to " << Destination << " is $" << totalfare << endl;
		//cout << "The fare to " << Destination << "is $" << totalfare << endl;
	}
	else if (age >= 65 && numBound >= 1)
	{
		fare = .55;
		boundaries = .35 * numBound;
		totalfare = fare + (boundaries);
		cout << "---" << endl;
		cout << "The fare to " << Destination << " is $" << totalfare << endl;
	}
	else
	{
		fare = 1.45;
		boundaries = 0.55 * numBound;
		totalfare = fare + (boundaries);
		cout << "---" << endl;
		cout << "The fare to " << Destination << " is $" << totalfare << endl;
	}

}