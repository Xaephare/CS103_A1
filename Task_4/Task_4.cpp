//Louis Ulysse Grace - Section B - Question 4


#include <iostream>
using namespace std;

void line() {
    cout << "\n--------------------------------------------------------------";
}

//All void functions created to easily draw the man.
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

//What's he hanging from? ಠ_ಠ
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

//Game, take in char and checks it against the real answer.
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

    //Play function returns boolean
    result = play();

    //If your answer is correct then the man walks, otherwise he is hung.
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