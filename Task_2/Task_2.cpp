//Louis Ulysse Grace - Section A - Question 2

#include <iostream>
using namespace std;


int sumOfArr(int array[], int arrSize) {
	int sum = 0;


	for (int i = 0; i < arrSize; i++) {
		if (array[i] > 0) {
		sum += array[i];
		}
	}

	return sum;
}

int main()
{
	int size;
	cout << "Set the size of the array: ";
	cin >> size;

	int* theList = new int[size];

	cout << "Enter values for the list: \n";

	for (int i = 0; i < size; i++) {
		cout << "Value " << i + 1 << ": ";
		cin >> theList[i];
	}

	int sum = sumOfArr(theList, size);
	cout << sum;

	delete [] theList;
	return 0;
}