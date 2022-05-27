//Louis Ulysse Grace - Section B - Question 4


#include <iostream>
#include <string>
using namespace std;

void line() {
    cout << "\n--------------------------------------------------------------";
}

void hangman() {
    cout << "\n   _____\n";
    cout << "  |     |\n";
    cout << "  |     o\n";
    cout << "  |    \\|/\n";
    cout << "  |     |\n";
    cout << "  |    / \\\n";
    cout << "  | \n";
    cout << "  | \n";
    cout << "----- ";
}

void walkman() {
    cout << "\n o\n";
    cout << "\\|/\n";
    cout << " |\n";
    cout << "/ \\\n";
}

void invertman() {
    cout << "\n   _____\n";
    cout << "  |     |\n";
    cout << "  |    /|\\\n";
    cout << "  |     |\n";
    cout << "  |    /|\\\n";
    cout << "  |     o\n";
    cout << "  | \n";
    cout << "  | \n";
    cout << "----- ";
}

bool play() {

    char answer;


    for (int i = 0; i < 3; i++) {
        cout << "\nGuess the missing letter in Yo_bee: ";
        cin >> answer;
        if (answer == 'o') {
            return true;
        }
        else if (i < 2) {
            cout << "Sorry, try again.";
        }
    }
    return false;
}

int main()
{
    bool result;

    cout << "Welcome to hangman. This game is to check your spelling skill.";
    line();
    hangman();
    result = play();

    if (result == true) {
        cout << "\nYour guess is correct!";
        walkman();
    }
    else {
        cout << "\nYour guess is wrong.";
        invertman();
    }


    cout << endl;
    system("pause");
    return 0;
}