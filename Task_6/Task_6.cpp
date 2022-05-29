//Louis Ulysse Grace - Section B - Question 6

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Declare struct containing all necessary information.
	struct Info {
	int date[3] = {0, 0, 0};
	float meal = 0;
	float transport = 0;
	float entertainment = 0;
	float other = 0;
	};

//Declare a vector that holds the struct(s).
vector <Info> allExpenses;
enum {day, month, year};

//Because why not, functions are fun. prints out the date of the date struct from the vector @ index#.
void printDate(int index) {
	cout << allExpenses[index].date[day] << "/" << allExpenses[index].date[month] << "/" << allExpenses[index].date[year];
}

//Function to sort vector order by date, makes things easier comprehend.
bool compareByDate(const Info &a, const Info &b) {
	if (a.date[year] < b.date[year]) return true;
	if (a.date[year] == b.date[year] && a.date[month] < b.date[month]) return true;
	if (a.date[year] == b.date[year] && a.date[month] == b.date[month] && a.date[day] < b.date[day]) return true;
	else return false;
}



void addExpense() {
	
	Info newExpense;

	cout << "Enter date of expense separated by \"/\" (eg. dd/mm/yyyy): ";
		
	//Format scan just for fun/better readability.
	scanf_s("%d/%d/%d", &newExpense.date[day], &newExpense.date[month], &newExpense.date[year]);

	//Check for real dates.
	while (newExpense.date[day] > 31 || newExpense.date[month] > 12 || newExpense.date[year] > 9999) {
		cout << "Enter a real date, try again: ";
		scanf_s("%d/%d/%d", &newExpense.date[day], &newExpense.date[month], &newExpense.date[year]);
		}

	//Amounts spent.
	cout << "Amount spent on meals: ";
	cin >> newExpense.meal;
	cout << "Amount spent on transport: ";
	cin >> newExpense.transport;
	cout << "Amount spent on entertainment: ";
	cin >> newExpense.entertainment;
	cout << "Amount spent in other categories: ";
	cin >> newExpense.other;
	//Add all the new structure values to the vector.
	allExpenses.push_back(newExpense);
}

//Function to make it easier to add multilpe expenses.
bool anotherExpense() {

	char choice = ' ';

	cout << "\nDo you want to add another expense? (y/n): ";
	start:
	cin >> choice;
	switch (choice) {
	case 'y': return true;
		break;
	case 'n': return false;
		break;
	default: cout << "Try again yes \"y\" or no \"n\": ";
		goto start;
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

void dailyReport() {

	sort(allExpenses.begin(), allExpenses.end(), compareByDate);

	size_t amount = allExpenses.size();
	for (size_t i = 0; i < amount; i++) {
		cout << "\nReport for date: "; 
		printDate(i);
		cout << "\n----------------------------------";
		cout << "\nAmount spent on meals : $" << allExpenses[i].meal;
		cout << "\nAmount spent on transport: $" << allExpenses[i].transport;
		cout << "\nAmount spent on entertainment: $" << allExpenses[i].entertainment;
		cout << "\nAmount spent in other categories: $" << allExpenses[i].other;
		cout << "\nTotal Amount spent: $" << allExpenses[i].meal + allExpenses[i].transport + allExpenses[i].entertainment + allExpenses[i].other;
		cout << endl << endl;
	}
	system("pause");
}

void weeklyReport() {
	sort(allExpenses.begin(), allExpenses.end(), compareByDate);

	Info spacer;
	const size_t amount = allExpenses.size();
	float mealTotal = 0;
	float transportTotal = 0;
	float entertainmentTotal = 0;
	float otherTotal = 0;
	float weekTotal = 0;

//Expand vector to multiple of 7 (1-week) to avoid access violation.
		
	for (size_t v = 0; v < (6 - amount); v++) {
		allExpenses.push_back(spacer);
	}

	for (size_t i = 0; i < amount ; (i += 6)) {
		
		cout << "\nReport for week starting: ";
		printDate(i);
		cout << "\n----------------------------------";
	
		for (size_t j = i; j < (i + 5); j++) {
			mealTotal += allExpenses[j].meal;
			transportTotal += allExpenses[j].transport;
			entertainmentTotal += allExpenses[j].entertainment;
			otherTotal += allExpenses[j].other;
			
		
		}

		weekTotal = (mealTotal + transportTotal + entertainmentTotal + otherTotal);
		cout << "\nAmount spent on meals : $" << mealTotal;
		cout << "\nAmount spent on transport: $" << transportTotal;
		cout << "\nAmount spent on entertainment: $" << entertainmentTotal;
		cout << "\nAmount spent in other categories: $" << otherTotal;
		cout << "\nTotal Amount spent: $" << weekTotal;
		cout << endl << endl;
	}

	//Contract vector back to original size.
	for (size_t v = 0; v < (6 - amount); v++) {
		allExpenses.pop_back();
	}
	system("pause");
}



int main() {
	
	int choice;
	bool another;


	start:
	choice = mainMenu();
	switch (choice) {
	case 1: another = true;
		while (another) {
		addExpense();
		another = anotherExpense();
		}
		break;
	case 2: dailyReport();
		break;
	case 3: weeklyReport();
		break;
	case 4:  return 0;
	default: break;
	}
	goto start;



	return 0;
}