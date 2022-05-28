//Louis Ulysse Grace - Section B - Question 6

#include <iostream>
#include <vector>
using namespace std;

struct Expenses {

	struct date {
		int dd = 0, mm = 0, yyyy = 0;
		//scanf("%d/%d/%d", &mm, &dd, &yyyy);
	} date;
	
	int transport = 0;
	int meal = 0;
	int entertainment = 0;
	int other = 0;
};

void addExpense() {
	vector <int> expenseOfDay;
}

//void dailyReport() {}

//void weeklyRepot() {}

int mainMenu() {

	int choice;

	cout << "--------------------------------------------------------------------------------------";
	cout << "\nPersonal expenses tracking system.";
	cout << "\n-------------------------";

	cout << "\n1 - Add new expense";
	cout << "\n2 - View daily expenses";
	cout << "\n3 - View weekly expenses";
	cout << "\n4 - Exit";
	cout << endl;

	start:
	cin >> choice;

	switch (choice) {
	case 1: return 1;
	case 2: return 2;
	case 3: return 3;
	case 4: return 4;
	default: cout << "Try again.";
		goto start;
		break;
	}
}

int main() {

	vector <int> expenseOfDay;

	start:
	int choice;

	
	choice = mainMenu();

	switch (choice) {
	case 1: cout << "adding expense";
		break;
	case 2: cout << "daily expenses";
		break;
	case 3: cout << "weekly expenses";
		break;
	case 4:  return 0;
	default: break;
 }

	goto start;

	cout << endl;
	system("pause");
	return 0;
}