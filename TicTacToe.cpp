
#include <iostream>
#include <array>
using namespace std;

string game[] = { "1","2","3","4","5","6","7","8","9" };
int player1;
int player2;
bool win1 = false;
bool win2 = false;
bool tie = false;
int counter = 0;

void board() {

	for (int i = 0; i < 9; i++) {
		if (i == 3 || i == 6) {
			cout << "\n\n";
		}
		cout << game[i] << " ";
	}
}

int playerOne(int x) {

	while (game[x - 1] == "X" || game[x - 1] == "O" || x > 9 || x < 1 || cin.fail()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
		cout << "Please enter a correct value -> ";
		cin >> x;
	}

	game[x - 1] = "X";

	return 0;
}

int playerTwo(int x) {

	while (game[x - 1] == "X" || game[x - 1] == "O" || x > 9 || x < 1 || cin.fail()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
		cout << "Please enter a correct value -> ";
		cin >> x;
	}

	game[x - 1] = "O";

	return 0;
}




int checkOne() {

	for (int i = 0; i < 9; i++) {

		//Vertical
		if (i == 0 || i == 1 || i == 2) {

			if (game[i] == "X" && game[i + 3] == "X" && game[i + 6] == "X") {
				win1 = true;
			}

		}

		//Horizontal
		if (i == 0 || i == 3 || i == 6) {
			if (i == 0) {
				if (game[0] == "X" && game[1] == "X" && game[2] == "X") {
					win1 = true;
				}
			}
			else if (i == 3) {
				if (game[3] == "X" && game[4] == "X" && game[5] == "X") {
					win1 = true;
				}
			}
			else if (i == 6) {
				if (game[6] == "X" && game[7] == "X" && game[8] == "X") {
					win1 = true;
				}
			}

		}

		//Diagonal
		if (i == 0 || i == 2) {

			if (i == 0) {
				if (game[i] == "X" && game[i + 4] == "X" && game[i + 8] == "X") {
					win1 = true;
				}

			}
			else if (i == 2) {
				if (game[i] == "X" && game[i + 2] == "X" && game[i + 4] == "X") {
					win1 = true;
				}
			}
		}
	}
	return 0;
}

int checkTwo() {

	for (int i = 0; i < 9; i++) {

		//Vertical
		if (i == 0 || i == 1 || i == 2) {
			if (game[i] == "O" && game[i + 3] == "O" && game[i + 6] == "O") {
				win2 = true;
			}
		}

		//Horizontal
		if (i == 0 || i == 3 || i == 6) {
			if (i == 0) {
				if (game[0] == "O" && game[1] == "O" && game[2] == "O") {
					win2 = true;
				}
			}
			else if (i == 3) {
				if (game[3] == "O" && game[4] == "O" && game[5] == "O") {
					win2 = true;
				}
			}
			else if (i == 6) {
				if (game[6] == "O" && game[7] == "O" && game[8] == "O") {
					win2 = true;
				}
			}
		}

		//Diagonal
		if (i == 0 || i == 2) {

			if (i == 0) {
				if (game[i] == "O" && game[i + 4] == "O" && game[i + 8] == "O") {
					win2 = true;
				}

			}
			else if (i == 2) {
				if (game[i] == "O" && game[i + 2] == "O" && game[i + 4] == "O") {
					win2 = true;
				}
			}
		}
	}
	return 0;
}

int checkTie() {

	counter = 0;

	for (int i = 0; i < 9; i++) {
		if (game[i] == "X" || game[i] == "O") {
			counter++;
		}
	}

	if (counter == 9) {
		tie = true;
	}

	return 0;
}

int main() {
	while (!win1 && !win2 && !tie) {

		if (tie || win1 || win2) {}
		else {
			board();
			cout << "\nIt is Player 1's turn -> ";
			cin >> player1;
			playerOne(player1);
		}
		checkOne();
		checkTwo();
		checkTie();

		if (tie || win1 || win2) {}
		else {
			board();
			cout << "\nIt is Player 2's turn -> ";
			cin >> player2;
			playerTwo(player2);
		}
		checkOne();
		checkTwo();
		checkTie();
	}

	cout << "\n\n";
	board();

	if (win1) {
		cout << "\nPlayer 1 was the winner!";
	}
	else if (win2) {
		cout << "\nPlayer 2 was the winner!";
	}
	else if (tie) {
		cout << "\nThe game was tied";
	}
}
