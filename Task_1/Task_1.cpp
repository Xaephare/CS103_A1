//Louis Ulysse Grace - Section A - Question 1

#include <iostream>
#include <string>
using namespace std;



struct soccer {
	int playerNumber = 0;
	float playerSpeed = 0;
	string playerPos = "null";
};



int playerNum(int number) {
	cout << "What number is this player?: ";
	cin >> number;
	
	return number;
}

float playerSpd(float speed) {
	cout << "What is this players maximum speed to two decimal places? (eg 15.2): ";
	cin >> speed;

	return speed;
}

string playerPosition(string position) {

	enum positionFinal{goalkeeper, midfielder, striker, winger, defender};
	char playerLetter;
	char arrOfPos[5] = { 'g', 'm', 's', 'w', 'd' };
	int playerPosNum;
	cout << "Which position does this player play? (input the first letter of their position) \n g=goalkeeper, m=midfielder, s=striker, w=winger, d=defender: ";
	cin >> playerLetter;


	for (int i = 0; i < 5; i++) {
		if (playerLetter == arrOfPos[i]) {
		playerPosNum = i;
		}
	}

	
	switch (playerPosNum) {
		case goalkeeper: position = "goalkeeper";
			break;
		case midfielder: position = "midfielder";
			break;
		case striker: position = "striker";
			break;
		case winger: position = "winger";
			break;
		case defender: position = "defender";
			break;
		}


	return position;
}



int main() {
	
	
	soccer player1;
	soccer player2;
	
	
	cout << "Player 1 information:\n---------------------\n";
	player1.playerNumber = playerNum(0);
	player1.playerSpeed = playerSpd(0);
	player1.playerPos = playerPosition("null");

	cout << "\n\nPlayer 2 information:\n---------------------\n";
	player2.playerNumber = playerNum(0);
	player2.playerSpeed = playerSpd(0);
	player2.playerPos = playerPosition("null");

	cout << "\n\n------------------------------------------------------------";
	cout << "\nPlayer 1 number: " << player1.playerNumber;
	cout << "\nPlayer 1 maximum speed: " << player1.playerSpeed;
	cout << "\nPlayer 1 position: " << player1.playerPos;
	cout << "\n------------------------------------------------------------";

	cout << "\n------------------------------------------------------------";
	cout << "\nPlayer 2 number: " << player2.playerNumber;
	cout << "\nPlayer 2 maximum speed: " << player2.playerSpeed;
	cout << "\nPlayer 2 position: " << player2.playerPos;
	cout << "\n------------------------------------------------------------\n";

	system("pause");
	return 0;
}