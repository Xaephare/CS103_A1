//Louis Ulysse Grace - Section A - Question 3



/*
Q3.Write a program to add two 3x3 matrices called A and B and store the resultant
into matrix C.Multiply the resultant matrix C by 3 and display the result.Assign the
values to the A and B matrixes during the declaration.Display the output structure.

A and B arrays take user
inputs as per the
scenario.

Added A and B stored
into C matrix and
displayed C matrix

Multiplied C matrix by 3
and displayed.

The results have been
displayed fully.
*/
#include <iostream>
#include <string>
using namespace std;

void arrInput(string arrId, int array[3][3]) {

	int counter = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int x;
			cout << "Enter value for array " << arrId << ", section " << counter << ": ";
			cin >> x;
			array[i][j] = x;
			counter++;
		}
	}

}

void arrOutput(string arrId, int array[3][3]) {

	cout << "\nArray " << arrId << ": ";
	for (int i = 0; i < 3; i++) {
		cout << "\n{";
		for (int j = 0; j < 3; j++) {
			cout << array[i][j];
			if (j < 2) { cout << ", "; }
		}
		cout << "}";
	}

}

int main() {

	int A[3][3];
	int B[3][3];
	int C[3][3];


	arrInput("A", A);
	cout << "--------------------------------------" << endl;
	arrInput("B", B);
	cout << "--------------------------------------" << endl;

	
	arrOutput("A", A);
	arrOutput("B", B);

	return 0;
}