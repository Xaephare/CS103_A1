//Louis Ulysse Grace - Section B - Question 6

#include <iostream>
#include <vector>
using namespace std;


	struct Info {
		struct date {
			int dd = 0, mm = 0, yyyy = 0;
			//scanf("%d/%d/%d", &dd, &mm, &yyyy);
		} date;

	int meal = 0;
	int transport = 0;
	int entertainment = 0;
	int other = 0;
	};

vector <Info> allExpenses;




void addExpense() {
	
	bool adding = true;
	Info newExpense;

	while (adding) {
		cout << "Enter date of expense separated by \"/\": ";
		scanf_s("%d/%d/%d", &newExpense.date.dd, &newExpense.date.mm, &newExpense.date.yyyy);
		cout << "Amount spent on meals: ";
		cin >> newExpense.meal;
		cout << "Amount spent on transport: ";
		cin >> newExpense.transport;
		cout << "Amount spent on entertainment: ";
		cin >> newExpense.entertainment;
		cout << "Amount spent on other categories: ";
		cin >> newExpense.other;
		//cout << newExpense.date.dd << "/" << newExpense.date.mm << "/" << newExpense.date.yyyy;
		adding = false;
		allExpenses.push_back(newExpense);
	}
}

bool anotherExpense() {

	char choice = ' ';

	cout << "\nDo you want to add another expense? (y/n): ";
	cin >> choice;
	switch (choice) {
	case 'y': return true;
		break;
	case 'n': return false;
		break;
	default: return false;
		break;
	}
}

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

//void dailyReport() {}

//void weeklyRepot() {}



int main() {

	

	
	int choice;
	bool another = true;
	start:
	
	choice = mainMenu();

	switch (choice) {
	case 1: while (another) {
		addExpense();
		another = anotherExpense();
		}
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