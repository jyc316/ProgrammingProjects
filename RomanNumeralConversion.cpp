/*
Write a program that converts a number entered in Roman numerals to a decimal.
Use Character Arrays
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <assert.h>
#define SIZE 6
using namespace std;

class RomanNumeral {
private:

	char NumeralArray[SIZE];
	int NumeralSum;

public:

	RomanNumeral();
	void DisplayArray();
	void FillArray();
	void FindNumeralSum();
	void DisplaySum();

};
	
// Default Constructor
RomanNumeral::RomanNumeral() {

	NumeralSum = 0;
	static const char TemporaryArray[] = "EMPTY";
	assert(strlen(TemporaryArray) < sizeof(NumeralArray));
	strcpy_s(NumeralArray, TemporaryArray);

}

int main(void) {

	// Declare Class Variable
	RomanNumeral NumeralObject;
	
	// Invoke Display Array Functiom
	cout << "Array Before User Input: ";
	NumeralObject.DisplayArray();
	cout << endl;

	// Invoke Fill Array Function
	NumeralObject.FillArray();

	// Invoke Display Array Function
	cout << "Array After User Input: ";
	NumeralObject.DisplayArray();
	cout << endl;

	// Invoke FindNumeralSum Function
	NumeralObject.FindNumeralSum();

	// Invoke Display Sum Function
	NumeralObject.DisplaySum();

	system("pause");
	return 0;
}

void RomanNumeral::DisplayArray() {

	for (int count = 0; count < SIZE; count++) {
		
		cout << NumeralArray[count] << " ";

	}

}

void RomanNumeral::FillArray() {

	for (int count = 0; count < SIZE - 1; count++) {

		cout << "Enter a Character for Array Element #" << count + 1 << ": ";
		cin >> NumeralArray[count];

		// Check If Input Is A Lower Case Letter
		if(islower(NumeralArray[count])) 

			NumeralArray[count] = toupper(NumeralArray[count]);

	}
}

void RomanNumeral::FindNumeralSum() {

	for (int count = 0; count < SIZE; count++) {

		switch (NumeralArray[count]) {

		case 'M': NumeralSum += 1000;
			break;

		case 'D': NumeralSum += 500;
			break;

		case 'C': NumeralSum += 100;
			break;

		case 'L': NumeralSum += 50;
			break;

		case 'X': NumeralSum += 10;
			break;

		case 'V': NumeralSum += 5;
			break;

		case 'I': NumeralSum += 1;
			break;

		default: continue;

		}
	}

}

void RomanNumeral::DisplaySum() {

	cout << "\n\nThe Sum of the Roman Numerals is " << NumeralSum << endl << endl;
}
