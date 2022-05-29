//Louis Ulysse Grace - Section B - Question 5

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



bool menu(int &score) {
	int choice;
	cout << "--------------------------------------------------------------------------------------";
	cout << "\nIdentify the Shapes";
	cout << "\n-------------------------";

	if (score > 0) {
		cout << "\nFinal score:" << score;
		cout << "\n------------";
	}

	cout << "\n1 - Play";
	cout << "\n2 - Exit";
	cout << endl;
	cin >> choice;

	if (choice == 1) {
		return true;
	}
	else if (choice == 2) {
		return false;
	}

	return false;
}

void triangle() {
	cout << "\n   *";
	cout << "\n  ***";
	cout << "\n *****";
	cout << "\n*******";
}

void square() {
	cout << "\n*******";
	cout << "\n*******";
	cout << "\n*******";
	cout << "\n*******";
}

//Function takes in width and height arguments to draw rectangle.
void rectangle(int height, int width) {
	for (int i = 0; i < height ; i++) {
		cout << endl;
		for (int j = 0; j < width; j++) {
			cout << "*";
		}
	}
}

//Function randomly picks which shape to generate and then sets the correct answer.
char game() {
	char realAnswer;
	int shape = 0;
	shape = rand() % (3);
	
	if (shape == 0) {
		triangle();
		realAnswer = 'b';
	}
	else if (shape == 1) {
		square();
		realAnswer = 'c';
	}
	else {
		rectangle(3, 9);
		realAnswer = 'a';
	}

	return realAnswer;
}

char choices() {
	char userAnswer = ' ';

	cout << "\n\na. Rectangle";
	cout << "\n\nb. Triangle";
	cout << "\n\nc. Square";
	cout << "\n\nd. None of the above";
	cout << "\n\nAnswer: ";
	cin >> userAnswer;

	//Check to make sure answer is legal.
	while (userAnswer > 'd') {
		cout << "Try again: ";
		cin >> userAnswer;
	}

	return userAnswer;
}

int calculateScore(char userAnswer, char realAnswer, int &score) {
	

	if (userAnswer == realAnswer) {
		score += 10;
	}
	return score;
}

int main() {
	
	srand(time(0));
	int score = 0;
	bool playing = menu(score);
	char userAnswer = ' ';
	char realAnswer = ' ';

	//Loop that runs while playing is true. menu function returns boolean based on your choice (play/exit).
	while (playing) {
		realAnswer = game();
		userAnswer = choices();
		calculateScore(userAnswer, realAnswer, score);
		playing = menu(score);
	}

	cout << endl;
	system("pause");
	return 0;
}	