

#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

string game[] = { "1","2","3","4","5","6","7","8","9" };
string original[] = { "1","2","3","4","5","6","7","8","9" };
int player1;
int player2;
string name1;
string name2;
bool win1 = false;
bool win2 = false;
bool tie = false;
int counter = 0;
string ch1 = "";
string ch2 = "";
bool Al1 = false;
bool Al2 = false;
bool Pal1 = false;
bool Pal2 = false;
bool flag = false;
bool lose = false;

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


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx



//battle
int playerOneBattle(int x) {

	while (game[x - 1] == ch1 || game[x - 1] == ch2 || x > 9 || x < 1 || cin.fail()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
		cout << "Please enter a correct value -> ";
		cin >> x;
	}

	game[x - 1] = ch1;

	return 0;
}

int playerTwoBattle(int x) {

	while (game[x - 1] == ch1 || game[x - 1] == ch2 || x > 9 || x < 1 || cin.fail()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}
		cout << "Please enter a correct value -> ";
		cin >> x;
	}

	game[x - 1] = ch2;

	return 0;
}

bool checkAl_Ability() {

	counter = 0;
	flag = false;

	for (int i = 0; i < 9; i++) {
		if (game[i] == ch1 || game[i] == ch2) {
			counter++;
		}
	}
	if (counter < 2) {
		cout << "You can't use this ability yet! There needs to be at least 2 spots filled!";
		flag = true;
	}

	return flag;

}

bool checkPal_Ability() {

	int counter = 0;
	flag = false;
	for (int i = 0; i < 9; i++) {
		if (game[i] == ch1 || game[i] == ch2) {
			counter++;
		}
	}
	if (counter < 1) {
		cout << "There has to be at least ONE piece on the board! You have to default to the regular option right now!";
		flag = true;
	}

	return flag;
}

int Alchemist() {

	counter = 0;
	flag = false;

	for (int i = 0; i < 9; i++) {
		if (game[i] == ch1 || game[i] == ch2) {
			counter++;
		}
	}


	//player 1
	if (Al1) {
		int x = 0;
		int y = 0;

		cout << "\n\n";
		board();
		cout << "\n\n\n";
		cout << name1 << ", what piece do you want to select from the board -> ";
		cin >> x;

		//choosing which one first
		while ((x > 9 || x < 1) && (game[x - 1] != ch1 || game[x - 1] != ch2) || cin.fail()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Please enter a correct value -> ";
			cin >> x;
		}

		if (game[x - 1] != ch2 && game[x - 1] != ch1) {
			while (game[x - 1] != ch2 && game[x - 1] != ch1) {
				cout << "\nThe spot you want to swap has to be occupied! Try again -> ";
				cin >> x;
			}
		}

		if (game[x - 1] == ch2) {

			//choosing for swap
			cout << "\n\nNow swap the placement with the opposite side, do not swap it with the same character -> ";
			cin >> y;
			while (y > 9 && y < 1 && game[y - 1] == ch2 || cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please choose the correct value -> ";
				cin >> y;

			}

			//swap
			game[x - 1] = ch1;
			game[y - 1] = ch2;

		}

		else if (game[x - 1] == ch1) {

			//choosing for sway
			cout << "\n\nNow swap the placement with the opposite side, do not swap it with the same character -> ";
			cin >> y;
			while (y > 9 && y < 1 && game[y - 1] == ch1 || cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please choose the correct value -> ";
				cin >> y;

			}

			//swap
			game[x - 1] = ch2;
			game[y - 1] = ch1;

		}

	}

	//player 2
	else if (Al2) {
		int x = 0;
		int y = 0;

		cout << "\n\n";
		board();
		cout << "\n\n\n";
		cout << name2 << ", what piece do you want to select from the board -> ";
		cin >> x;

		//choosing which one first
		while ((x > 9 || x < 1) && (game[x - 1] != ch1 || game[x - 1] != ch2) || cin.fail()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Please enter a correct value -> ";
			cin >> x;
		}

		if (game[x - 1] != ch2 && game[x - 1] != ch1) {
			while (game[x - 1] != ch2 && game[x - 1] != ch1) {
				cout << "\nThe spot you want to swap has to be occupied! Try again -> ";
				cin >> x;
			}
		}

		if (game[x - 1] == ch2) {

			//choosing for swap
			cout << "\n\nNow swap the placement with the opposite side, do not swap it with the same character -> ";
			cin >> y;
			while (y > 9 && y < 1 && game[y - 1] == ch2 || cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please choose the correct value -> ";
				cin >> y;

			}

			//swap
			game[x - 1] = ch1;
			game[y - 1] = ch2;

		}

		else if (game[x - 1] == ch1) {

			//choosing for sway
			cout << "\n\nNow swap the placement with the opposite side, do not swap it with the same character -> ";
			cin >> y;
			while (y > 9 && y < 1 && game[y - 1] == ch1 || cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please choose the correct value -> ";
				cin >> y;

			}

			//swap
			game[x - 1] = ch2;
			game[y - 1] = ch1;

		}

	}
	return 0;

}

int Paladin() {

	//player 1
	if (Pal1) {

		int x;
		int y;
		cout << "\n\n";
		board();
		cout << "\n\nSelect a spot to begin the process " << name1 << " -> ";
		cin >> x;
		while (x > 9 || x < 1 || cin.fail()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Please enter a correct value -> ";
			cin >> x;
		}

		while (game[x - 1] != ch1 && game[x - 1] != ch2 || cin.fail()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Please choose a spot that is occupied -> ";
			cin >> x;


		}

		cout << "\n\n";
		board();
		cout << "\n\n";
		cout << "Now choose a spot that is adjacent to the spot you chose (one spot right, left, below, above or diagonal of the spot, HAS TO BE UNOCCUPIED!!) -> ";
		cin >> y;

		//Input Check
		if (y > 9 || y < 1 || game[y - 1] == ch1 || game[y - 1] == ch2 || cin.fail()) {
			while (y > 9 || y < 1 || game[y - 1] == ch1 || game[y - 1] == ch2 || cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please choose correctly -> ";
				cin >> y;
			}
		}
		//Adjacent Check
		else {

			if (x == 1) {
				while (y != 2 && y != 4 && y != 5 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 2) {
				while (y != 1 && y != 3 && y != 4 && y != 5 && y != 6 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 3) {
				while (y != 2 && y != 5 && y != 6 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 4) {
				while (y != 1 && y != 2 && y != 5 && y != 7 && y != 8 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 5) {
				while (x == y || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 6) {
				while (y != 2 && y != 3 && y != 5 && y != 8 && y != 9 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 7) {
				while (y != 4 && y != 5 && y != 8 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 8) {
				while (y != 4 && y != 5 && y != 6 && y != 7 && y != 9 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 9) {
				while (y != 5 && y != 6 && y != 8 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}

			}

		}

		if (game[x - 1] == ch1) {
			game[y - 1] = ch1;
			game[x - 1] = original[x - 1];
		}
		else if (game[x - 1] == ch2) {
			game[y - 1] = ch2;
			game[x - 1] = original[x - 1];
		}

	}
	//player 2
	else if (Pal2) {

		int x;
		int y;
		cout << "\n\n";
		board();
		cout << "\n\nSelect a spot to begin the process " << name2 << " -> ";
		cin >> x;
		while (x > 9 || x < 1 || cin.fail()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Please enter a correct value -> ";
			cin >> x;
		}

		while (game[x - 1] != ch1 && game[x - 1] != ch2 || cin.fail()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Please choose a spot that is occupied -> ";
			cin >> x;


		}

		cout << "\n\n";
		board();
		cout << "\n\n";
		cout << "Now choose a spot that is adjacent to the spot you chose (one spot right, left, below, above or diagonal of the spot, HAS TO BE UNOCCUPIED!!) -> ";
		cin >> y;

		//Input Check
		if (y > 9 || y < 1 || game[y - 1] == ch1 || game[y - 1] == ch2 || cin.fail()) {
			while (y > 9 || y < 1 || game[y - 1] == ch1 || game[y - 1] == ch2 || cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please choose correctly -> ";
				cin >> y;
			}
		}
		//Adjacent Check
		else {

			if (x == 1) {
				while (y != 2 && y != 4 && y != 5 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 2) {
				while (y != 1 && y != 3 && y != 4 && y != 5 && y != 6 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 3) {
				while (y != 2 && y != 5 && y != 6 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 4) {
				while (y != 1 && y != 2 && y != 5 && y != 7 && y != 8 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 5) {
				while (x == y || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 6) {
				while (y != 2 && y != 3 && y != 5 && y != 8 && y != 9 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 7) {
				while (y != 4 && y != 5 && y != 8 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 8) {
				while (y != 4 && y != 5 && y != 6 && y != 7 && y != 9 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}
			}
			else if (x == 9) {
				while (y != 5 && y != 6 && y != 8 || y == x || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "You did not pick the correct adjacent spot, Please try again -> ";
					cin >> y;
				}

			}

		}

		if (game[x - 1] == ch1) {
			game[y - 1] = ch1;
			game[x - 1] = original[x - 1];
		}
		else if (game[x - 1] == ch2) {
			game[y - 1] = ch2;
			game[x - 1] = original[x - 1];
		}

	}
	return 0;

}

int checkOneBattle() {

	for (int i = 0; i < 9; i++) {
		//Vertical
		if (i == 0 || i == 1 || i == 2) {
			if (game[i] == ch1 && game[i + 3] == ch1 && game[i + 6] == ch1) {
				win1 = true;
			}
		}
		//Horizontal
		if (i == 0 || i == 3 || i == 6) {
			if (i == 0) {
				if (game[0] == ch1 && game[1] == ch1 && game[2] == ch1) {
					win1 = true;
				}
			}
			else if (i == 3) {
				if (game[3] == ch1 && game[4] == ch1 && game[5] == ch1) {
					win1 = true;
				}
			}
			else if (i == 6) {
				if (game[6] == ch1 && game[7] == ch1 && game[8] == ch1) {
					win1 = true;
				}
			}
		}
		//Diagonal
		if (i == 0 || i == 2) {
			if (i == 0) {
				if (game[i] == ch1 && game[i + 4] == ch1 && game[i + 8] == ch1) {
					win1 = true;
				}
			}
			else if (i == 2) {
				if (game[i] == ch1 && game[i + 2] == ch1 && game[i + 4] == ch1) {
					win1 = true;
				}
			}
		}
	}
	return 0;
}

int checkTwoBattle() {

	for (int i = 0; i < 9; i++) {
		//Vertical
		if (i == 0 || i == 1 || i == 2) {
			if (game[i] == ch2 && game[i + 3] == ch2 && game[i + 6] == ch2) {
				win2 = true;
			}
		}
		//Horizontal
		if (i == 0 || i == 3 || i == 6) {
			if (i == 0) {
				if (game[0] == ch2 && game[1] == ch2 && game[2] == ch2) {
					win2 = true;
				}
			}
			else if (i == 3) {
				if (game[3] == ch2 && game[4] == ch2 && game[5] == ch2) {
					win2 = true;
				}
			}
			else if (i == 6) {
				if (game[6] == ch2 && game[7] == ch2 && game[8] == ch2) {
					win2 = true;
				}
			}
		}
		//Diagonal
		if (i == 0 || i == 2) {

			if (i == 0) {
				if (game[i] == ch2 && game[i + 4] == ch2 && game[i + 8] == ch2) {
					win2 = true;
				}

			}
			else if (i == 2) {
				if (game[i] == ch2 && game[i + 2] == ch2 && game[i + 4] == ch2) {
					win2 = true;
				}
			}
		}
	}
	return 0;
}

int checkTieBattle() {

	counter = 0;

	for (int i = 0; i < 9; i++) {
		if (game[i] == ch1 || game[i] == ch2) {
			counter++;
		}
	}

	if (counter == 9) {
		tie = true;
	}

	return 0;
}

//bot
int bot(string n) {

	srand(time(nullptr));
	int x = rand() % 9 + 1;

	while (game[x - 1] == "X" || game[x - 1] == "O") {
		
		srand(time(nullptr));
		x = rand() % 9 + 1;

	}

	game[x - 1] = ch2;
	cout << "The " << n << " chose the spot " << x;

	return 0;

}

int checkbotWin() {

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




int main() {

	int type = 0;
	char choice = 'y';
	int gamesPlayed = 0;
	int archetype = 0;
	int archchoice = 0;


	while (choice == 'y') {

		cout << "\tTic-Tac-Toe\n\n";

		cout << "Would you want to play regular(1), battle(2) or story mode(3) tictactoe -> ";
		cin >> type;

		while (type != 1 && type != 2 && type != 3 || cin.fail()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Please enter the correct value -> ";
			cin >> type;

		}

		//Regular
		if (type == 1) {

			cout << "Choose a name Player 1 -> ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name1);

			cout << "Choose a name Player 2 -> ";
			getline(cin, name2);

			while (!win1 && !win2 && !tie) {

				if (tie || win1 || win2) {}
				else {
					board();
					cout << "\nIt is " << name1 << "'s turn -> ";
					cin >> player1;
					playerOne(player1);
				}
				checkOne();
				checkTwo();
				checkTie();

				if (tie || win1 || win2) {}
				else {
					board();
					cout << "\nIt is " << name2 << "'s turn -> ";
					cin >> player2;
					playerTwo(player2);
				}
				checkOne();
				checkTwo();
				checkTie();
			}

		}

		//battle
		else if (type == 2) {

			Al1 = false;
			Al2 = false;
			Pal1 = false;
			Pal2 = false;

			cout << "Choose a name Player 1 -> ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name1);

			cout << "Choose a name Player 2 -> ";
			getline(cin, name2);

			cout << "\n\nWhat character would you like to have for the board player1 (It has to be 1 character long, NO NUMBERS!!) -> ";
			cin >> ch1;

			while (ch1.length() != 1 || isdigit(ch1[0])) {
				cout << "Please try again -> ";
				cin >> ch1;

			}

			cout << "What character would you like to have for the board player2 (It has to be 1 character long, NO NUMBERS!!) -> ";
			cin >> ch2;

			while (ch2.length() != 1 || ch2 == ch1 || isdigit(ch2[0])) {
				cout << "Please try again -> ";
				cin >> ch2;

			}

			cout << "\n\n";


			cout << name1 << ", what type of archetype would you like to choose? (Player 1 Always gets the first Pick)";
			cout << " \n\n\nAlchemist(1)\tPaladin(2)";
			cout << "\n\n\nSelect the type of Archetype you want to be -> ";
			cin >> archetype;
			while (archetype != 1 && archetype != 2 || cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "\nPlease put in the correct input -> ";
				cin >> archetype;

			}

			if (archetype == 1) {
				Al1 = true;
				Pal2 = true;
			}
			else if (archetype == 2) {
				Al2 = true;
				Pal1 = true;
			}


			if (Al1) {
				cout << "\n\n" << name1 << "'s archetype is the Alchemist, while " << name2 << "'s archetype is the Paladin!\n\n";
			}
			else if (Pal1) {
				cout << "\n\n" << name1 << "'s archetype is the Paladin, while " << name2 << "'s archetype is the Alchemist!\n\n";
			}

			cout << "\n\n";



			while (!win1 && !win2 && !tie) {


				if (tie || win1 || win2) {}
				else {
					//player 1
					board();
					cout << "\n\n\n";
					cout << name1 << ", would you like to do a regular move or use your ability?";
					cout << "\n\n\n";
					if (Al1) {
						cout << "Regular(1)\tAlchemist Abilty(2)";
					}
					else if (Pal1) {
						cout << "Regular(1)\tPaladin Abilty(2)";
					}

					cout << "\n\n\nWhich do you choose -> ";
					cin >> archchoice;
					while (archchoice != 1 && archchoice != 2 || cin.fail()) {
						if (cin.fail()) {
							cin.clear();
							cin.ignore();
						}
						cout << "Please put in the correct input -> ";
						cin >> archchoice;

					}

					//regular
					if (archchoice == 1) {
						cout << "\n\n\n";
						board();
						cout << "\n\nPlease input where you would like to place your character -> ";
						cin >> player1;
						playerOneBattle(player1);

					}

					//archetype ability
					else if (archchoice == 2) {

						if (Al1) {
							checkAl_Ability();
							if (flag) {
								cout << "\n\n\n";
								board();
								cout << "\n\n\nSince we have to do the default option of a regular move, choose where to put your character -> ";
								cin >> player1;
								playerOneBattle(player1);
							}
							else {
								Alchemist();
							}
						}
						else if (Pal1) {
							checkPal_Ability();
							if (flag) {
								cout << "\n\n\n";
								board();
								cout << "\n\n\nSince we have to do default option of a regular move, choose where to put your character -> ";
								cin >> player1;
								playerOneBattle(player1);
							}
							else {
								Paladin();
							}

						}

					}
				}

				checkOneBattle();
				checkTwoBattle();
				checkTieBattle();

				if (tie || win1 || win2) {}
				else {
					//player 2
					cout << "\n\n";
					board();
					cout << "\n\n";
					cout << name2 << ", would you like to do a regular move or use your ability?";
					cout << "\n\n";
					if (Al2) {
						cout << "Regular(1)\tAlchemist Abilty(2)";
					}
					else if (Pal2) {
						cout << "Regular(1)\tPaladin Abilty(2)";
					}

					cout << "\n\n\nWhich do you choose -> ";
					cin >> archchoice;
					while (archchoice != 1 && archchoice != 2 || cin.fail()) {
						if (cin.fail()) {
							cin.clear();
							cin.ignore();
						}
						cout << "\nPlease put in the correct input -> ";
						cin >> archchoice;

					}

					//regular
					if (archchoice == 1) {
						cout << "\n\n\n";
						board();
						cout << "\n\nPlease input where you would like to place your character -> ";
						cin >> player2;
						playerTwoBattle(player2);

					}

					//archetype ability
					else if (archchoice == 2) {
						if (Al2) {
							checkAl_Ability();
							if (flag) {
								cout << "\n\n\n";
								board();
								cout << "\n\n\nSince we have to do the default option of a regular move, choose where to put your character -> ";
								cin >> player2;
								playerTwoBattle(player2);
							}
							else {
								Alchemist();
							}
						}
						else if (Pal2) {
							checkPal_Ability();
							if (flag) {
								cout << "\n\n\n";
								board();
								cout << "\n\n\nSince we have to do the default option of a regular move, choose where to put your character -> ";
								cin >> player2;
								playerTwoBattle(player2);
							}
							else {
								Paladin();
							}
						}

					}

				}

				checkOneBattle();
				checkTwoBattle();
				checkTieBattle();

			}
		}

		//Story Mode
		else if (type == 3) {

			bool exit = false;

			while(!exit){
			int storeChoice = 0;

			Al1 = false;
			Pal1 = false;

			int rupees = 0;
			int health = 3;
			int attack = 1;
			int defense = 1;
			int archetype = 0;
			int archchoice = 0;
			int option = 0;
			bool notebook = false;
			

			//Bokoblin
			int bokohealth = 3;
			int bokoAttack = 2;

			//Green Bokoblin
			int greenbokoHealth = 8;
			int greenAttack = 6;

			//Red Lynel
			int redLynelHealth = 10;
			int redAttack = 8;

			//Golden Lynel
			int GoldenLynelHealth = 12;
			int goldAttack = 10;

			//Ganon
			int Ganon = 15;
			int ganonAttack = 12;

			if (lose) {

				cout << "\n\n\tGAME OVER!!!";

			}


			cout << "\n\nWelcome to Story Mode TicTacToe!!!";

			//Dialogue
			cout << "\n\nGuard: An evil being named Ganon has taken Princess Zelda! You must save her ...." << endl;
			cout << "Game: What is your name? -> ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name1);

			cout << "Guard: " << name1 << ", ah that is what your name is! You must leave the plateau and head into hyrule kingdom into the castle. \nThat is where Ganon is holding her!" << endl;
			cout << "\n";

			//Heading to the castle
			cout << "Here is a list of your character attributes:\n";
			cout << "Health -> " << health << endl;
			cout << "Attack -> " << attack << endl;
			cout << "Defence -> " << defense << endl;
			cout << "\n\n";

			//archtype
			cout << "Game: Oh look, you found a chest! This chest grants you either ability\nWould you like the Paladin(1) or Alchemist(2) Ability?" << endl;
			cout << "Ability -> ";
			cin >> archetype;
			while (archetype != 1 && archetype != 2 || cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please put in the correct input -> ";
				cin >> archetype;

			}

			if (archetype == 1) {
				Pal1 = true;
			}
			else if (archetype == 2) {
				Al1 = true;
			}

			if (Al1) {
				cout << "\nGame: Good choice! The Alchemist Ability can become really handy!";
			}

			else if (Pal1) {
				cout << "\nGame: Good choice! The Paladin Ability can become really handy!";
			}

			ch1 = "X";
			ch2 = "O";

			cout << "\n\n";

			//Battle 1 Bokoblin
			cout << "Game: Oh no, you just encountered a red bokoblin! Don't worry, these monsters aren't bad, but they \ncan hit a mean club!\n" << endl;
			while (bokohealth != 0 && health != 0) {

				if (tie || win1 || win2) {
					if (tie) {
						cout << "\nNo damage was done!\n\n";
						tie = false;
						for (int i = 0; i < 9; i++) {
							game[i] = original[i];
						}
					}
					else if (win1) {
						bokohealth = bokohealth - attack;
						cout << "\n" << name1 << " got a hit on the bokoblin!\nThe bokoblin now has " << bokohealth << " health left\n\n";
						win1 = false;
						for (int i = 0; i < 9; i++) {
							game[i] = original[i];
						}
					}
					else if (win2) {
						health = health - (bokoAttack - defense);
						cout << "\nThe bokoblin got a hit on you!\nYou now have " << health << " left\n\n";
						win2 = false;
						for (int i = 0; i < 9; i++) {
							game[i] = original[i];
						}
					}
				}
				else {
					//player 1
					board();
					cout << "\n\n\n";
					cout << name1 << ", would you like to do a regular move or use your ability?";
					cout << "\n\n\n";
					if (Al1) {
						cout << "Regular(1)\tAlchemist Abilty(2)";
					}
					else if (Pal1) {
						cout << "Regular(1)\tPaladin Abilty(2)";
					}

					cout << "\n\n\nWhich do you choose -> ";
					cin >> archchoice;
					while (archchoice != 1 && archchoice != 2 || cin.fail()) {
						if (cin.fail()) {
							cin.clear();
							cin.ignore();
						}
						cout << "Please put in the correct input -> ";
						cin >> archchoice;

					}

					//regular
					if (archchoice == 1) {
						cout << "\n\n\n";
						board();
						cout << "\n\nPlease input where you would like to place your character -> ";
						cin >> player1;
						playerOneBattle(player1);

					}

					//archetype ability
					else if (archchoice == 2) {

						if (Al1) {
							checkAl_Ability();
							if (flag) {
								cout << "\n\n\n";
								board();
								cout << "\n\n\nSince we have to do the default option of a regular move, choose where to put your character -> ";
								cin >> player1;
								playerOneBattle(player1);
							}
							else {
								Alchemist();
							}
						}
						else if (Pal1) {
							checkPal_Ability();
							if (flag) {
								cout << "\n\n\n";
								board();
								cout << "\n\n\nSince we have to do default option of a regular move, choose where to put your character -> ";
								cin >> player1;
								playerOneBattle(player1);
							}
							else {
								Paladin();
							}

						}

					}
				}

				checkOneBattle();
				checkbotWin();
				checkTieBattle();

				if (tie || win1 || win2) {
					if (tie) {
						cout << "\nNo damage was done!\n\n";
						tie = false;
						for (int i = 0; i < 9; i++) {
							game[i] = original[i];
						}
					}
					else if (win1) {
						bokohealth = bokohealth - attack;
						cout << "\n" << name1 << " got a hit on the bokoblin!\nThe bokoblin now has " << bokohealth << " health left\n\n";
						win1 = false;
						for (int i = 0; i < 9; i++) {
							game[i] = original[i];
						}
					}
					else if (win2) {
						health = health - (bokoAttack - defense);
						cout << "\nThe bokoblin got a hit on you!\nYou now have " << health << " left\n\n";
						win2 = false;
						for (int i = 0; i < 9; i++) {
							game[i] = original[i];
						}
					}
					
				}
				//bot
				else {
					board();
					cout << "\n\n";
					bot("bokoblin");
					cout << "\n";
				}

				checkOneBattle();
				checkbotWin();
				checkTieBattle();

			}

			if (health == 0) {
				lose = true;
			}

			if(lose){}

			//Branching Path 1 + Store
			else {

				//finish first battle
				cout << "\n\nGame: Congrats! You beat the bokoblin, and it dropped 20 rupees!" << endl;
				rupees += 20;
				cout << "Game: There is a stable in the distance! Would you like to go to the store? Yes(1) No(2) -> ";
				cin >> archetype;
				while (archetype != 1 && archetype != 2 || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "Please put in the correct input -> ";
					cin >> archetype;
				}

				//Go to the store
				if (archetype == 1) {

					cout << "\n\nBeedle: Welcome to the Lakside Stable!" << endl;
					cout << "Beedle:Here are the items I have to sell to you: " << endl;
					cout << "\nChicken leg(1)\tTraveler's Sword(2)\tTraveler's Shield(3)\n" << endl;

					cout << "Beedle: Would you like to make a purchase? Yes(1) No(2) -> ";
					cin >> archetype;
					while (archetype != 1 && archetype != 2 || cin.fail()) {
						if (cin.fail()) {
							cin.clear();
							cin.ignore();
						}
						cout << "Please put in the correct input -> ";
						cin >> archetype;
					}

					//choose an item
					if (archetype == 1) {
						cout << "\nWhich item would you like?";
						cout << "\n\nChicken leg: 5 Rupees(1)\tTraveler's Sword: 10 Rupees(2)\tTraveler's Shield: 10 Rupees(3) -> ";
						cin >> storeChoice;
						while (storeChoice != 1 && storeChoice != 2 && storeChoice != 3|| cin.fail()) {
							if (cin.fail()) {
								cin.clear();
								cin.ignore();
							}
							cout << "Please put in the correct input -> ";
							cin >> storeChoice;
						}

						if (storeChoice == 1) {
							cout << "\nGame: Congrats, you have gained 3 health from the Chicken Leg!";
							health += 3;
							rupees -= 5;
						}
						else if (storeChoice == 2) {
							cout << "\nGame: Congrats, you have now obtained the travelor's sword! You now have a 2 attack!";
							attack = 2;
							rupees -= 10;
						}
						else if (storeChoice == 3) {
							cout << "\nGame: Congrats, you have now obtained the travelor's shield! You now have 2 defense!";
							defense = 2;
							rupees -= 10;
						}

						cout << "\nYou now have " << rupees << " rupees left!";

					}

					else if (archetype == 2) {
						cout << "\nBeedle: Oh, sorry to see you go!";
					}
				}

				//Do not go to the store
				else if (archetype) {

					cout << "\nGame: Bummer, we could have gotten some cool stuff!";

				}
			}

			if(lose){}
			else {

				//battle 2 Green Bokoblin
				cout << "\nGame: Oh no, you just encountered a Green bokoblin! These ones are a little more tougher and stronger!\n" << endl;
				while (greenbokoHealth > 0 && health > 0) {

					if (tie || win1 || win2) {
						if (tie) {
							cout << "\nNo damage was done!\n\n";
							tie = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win1) {
							greenbokoHealth = greenbokoHealth - attack;
							cout << "\n" << name1 << " got a hit on the Green bokoblin!\nThe Green bokoblin now has " << greenbokoHealth << " health left\n\n";
							win1 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win2) {
							health = health - (greenAttack - defense);
							cout << "\nThe Green bokoblin got a hit on you!\nYou now have " << health << " left\n\n";
							win2 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
					}
					else {
						//player 1
						board();
						cout << "\n\n\n";
						cout << name1 << ", would you like to do a regular move or use your ability?";
						cout << "\n\n\n";
						if (Al1) {
							cout << "Regular(1)\tAlchemist Abilty(2)";
						}
						else if (Pal1) {
							cout << "Regular(1)\tPaladin Abilty(2)";
						}

						cout << "\n\n\nWhich do you choose -> ";
						cin >> archchoice;
						while (archchoice != 1 && archchoice != 2 || cin.fail()) {
							if (cin.fail()) {
								cin.clear();
								cin.ignore();
							}
							cout << "Please put in the correct input -> ";
							cin >> archchoice;

						}

						//regular
						if (archchoice == 1) {
							cout << "\n\n\n";
							board();
							cout << "\n\nPlease input where you would like to place your character -> ";
							cin >> player1;
							playerOneBattle(player1);

						}

						//archetype ability
						else if (archchoice == 2) {

							if (Al1) {
								checkAl_Ability();
								if (flag) {
									cout << "\n\n\n";
									board();
									cout << "\n\n\nSince we have to do the default option of a regular move, choose where to put your character -> ";
									cin >> player1;
									playerOneBattle(player1);
								}
								else {
									Alchemist();
								}
							}
							else if (Pal1) {
								checkPal_Ability();
								if (flag) {
									cout << "\n\n\n";
									board();
									cout << "\n\n\nSince we have to do default option of a regular move, choose where to put your character -> ";
									cin >> player1;
									playerOneBattle(player1);
								}
								else {
									Paladin();
								}

							}

						}
					}

					checkOneBattle();
					checkbotWin();
					checkTieBattle();

					if (tie || win1 || win2) {
						if (tie) {
							cout << "\nNo damage was done!\n\n";
							tie = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win1) {
							greenbokoHealth = greenbokoHealth - attack;
							cout << "\n" << name1 << " got a hit on the Green bokoblin!\nThe bokoblin now has " << greenbokoHealth << " health left\n\n";
							win1 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win2) {
							health = health - (greenAttack - defense);
							cout << "\nThe Green bokoblin got a hit on you!\nYou now have " << health << " left\n\n";
							win2 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}

					}
					//bot
					else {
						board();
						cout << "\n\n";
						bot("Green Bokoblin");
						cout << "\n";
					}

					checkOneBattle();
					checkbotWin();
					checkTieBattle();


				}
			}



			//end of battle 2

			if (health <= 0) {
				lose = true;
			}

			if (lose) {}

			//Branching Path 2 
			else {

				cout << "\nGame: Nice job on defeating the Green Bokoblin, that was very tough!\nOh look, it dropped 25 Rupees!" << endl;
				rupees += 25;
				cout << "Game: there is a chest in the distance, there is a notebook on the table in the ruins but there is a monster in the distance, what do you want to do?" << endl;
				cout << "Chest(1)\tNotebook(2)\tMonster(3)" << endl;
				cout << "Choice -> ";
				cin >> option;
				while (option != 1 && option != 2 && option != 3 || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "Please put in the correct input -> ";
					cin >> option;
				}

				if (option == 1) {
					cout << "\nGame: Let's go the chest!" << endl;
					cout << "Game: Congratulations! You found an apple in the chest! You now have +1 health!";
					health++;
				}
				else if (option == 2) {
					cout << "\nGame: Let's go to the notebook" << endl;
					cout << "Game: Interesting, this could be useful later!";
				}
				else if (option == 3) {
					cout << "\nGame: Alright, lets go see the what monster this is";
				}



			}

			if(lose){}
			
			//battle 3
			else {
				cout << "\nGame: Oh no, you just encountered a Red Lynel!\nThese guys are BEASTS!!!" << endl;
				while (redLynelHealth > 0 && health > 0) {

					if (tie || win1 || win2) {
						if (tie) {
							cout << "\nNo damage was done!\n\n";
							tie = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win1) {
							redLynelHealth = redLynelHealth - attack;
							cout << "\n" << name1 << " got a hit on the Red Lynel!\nThe Red Lynel now has " << redLynelHealth << " health left\n\n";
							win1 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win2) {
							health = health - (redAttack - defense);
							cout << "\nThe Red Lynel got a hit on you!\nYou now have " << health << " left\n\n";
							win2 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
					}
					else {
						//player 1
						board();
						cout << "\n\n\n";
						cout << name1 << ", would you like to do a regular move or use your ability?";
						cout << "\n\n\n";
						if (Al1) {
							cout << "Regular(1)\tAlchemist Abilty(2)";
						}
						else if (Pal1) {
							cout << "Regular(1)\tPaladin Abilty(2)";
						}

						cout << "\n\n\nWhich do you choose -> ";
						cin >> archchoice;
						while (archchoice != 1 && archchoice != 2 || cin.fail()) {
							if (cin.fail()) {
								cin.clear();
								cin.ignore();
							}
							cout << "Please put in the correct input -> ";
							cin >> archchoice;

						}

						//regular
						if (archchoice == 1) {
							cout << "\n\n\n";
							board();
							cout << "\n\nPlease input where you would like to place your character -> ";
							cin >> player1;
							playerOneBattle(player1);

						}

						//archetype ability
						else if (archchoice == 2) {

							if (Al1) {
								checkAl_Ability();
								if (flag) {
									cout << "\n\n\n";
									board();
									cout << "\n\n\nSince we have to do the default option of a regular move, choose where to put your character -> ";
									cin >> player1;
									playerOneBattle(player1);
								}
								else {
									Alchemist();
								}
							}
							else if (Pal1) {
								checkPal_Ability();
								if (flag) {
									cout << "\n\n\n";
									board();
									cout << "\n\n\nSince we have to do default option of a regular move, choose where to put your character -> ";
									cin >> player1;
									playerOneBattle(player1);
								}
								else {
									Paladin();
								}

							}

						}
					}

					checkOneBattle();
					checkbotWin();
					checkTieBattle();

					if (tie || win1 || win2) {
						if (tie) {
							cout << "\nNo damage was done!\n\n";
							tie = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win1) {
							redLynelHealth = redLynelHealth - attack;
							cout << "\n" << name1 << " got a hit on the Red Lynel!\nThe Red Lynel now has " << redLynelHealth << " health left\n\n";
							win1 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win2) {
							health = health - (bokoAttack - defense);
							cout << "\nThe Red Lynel got a hit on you!\nYou now have " << health << " left\n\n";
							win2 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}

					}
					//bot
					else {
						board();
						cout << "\n\n";
						bot("Red Lynel");
						cout << "\n";
					}

					checkOneBattle();
					checkbotWin();
					checkTieBattle();


				}
			}

			//end of third battle

			if (health <= 0) {
				lose = true;
			}

			//branching point 3
			if(lose){}
			else {

				cout << "\nGame: Wow, you defeated a Lynel, that is some good work you did!\n" << endl;
				cout << "\n\nGame: The Red Lynel dropped 40 Rupees!!" << endl;
				rupees += 40;
				cout << "Game: There is a stable in the distance! Would you like to go to the store? Yes(1) No(2) -> ";
				cin >> archetype;
				while (archetype != 1 && archetype != 2 || cin.fail()) {
					if (cin.fail()) {
						cin.clear();
						cin.ignore();
					}
					cout << "Please put in the correct input -> ";
					cin >> archetype;
				}

				//Go to the store
				if (archetype == 1) {

					cout << "\n\nBeedle: Welcome to the Hyland Stable!" << endl;
					cout << "Beedle:Here are the items I have to sell to you: " << endl;
					cout << "\nPotion of Health(1)\tEightfold Blade(2)\tApple(3)\n" << endl;

					cout << "Beedle: Would you like to make a purchase? Yes(1) No(2) -> ";
					cin >> archetype;
					while (archetype != 1 && archetype != 2 || cin.fail()) {
						if (cin.fail()) {
							cin.clear();
							cin.ignore();
						}
						cout << "Please put in the correct input -> ";
						cin >> archetype;
					}

					//choose an item
					if (archetype == 1) {
						cout << "\nWhich item would you like?";
						cout << "\n\nPotion of Health: 25 Rupees(1)\tEightfold Blade: 30 Rupees(2)\tApple: 5 Rupees(3) -> ";
						cin >> storeChoice;
						while (storeChoice != 1 && storeChoice != 2 && storeChoice != 3 || cin.fail()) {
							if (cin.fail()) {
								cin.clear();
								cin.ignore();
							}
							cout << "Please put in the correct input -> ";
							cin >> storeChoice;
						}

						if (storeChoice == 1) {
							if (rupees - 25 < 0) {
								cout << "\nSorry, you don't have enought! Better luck Next time!";
							}
							else {
								cout << "\nGame: Congrats, you have gained 10 health from the Potion of Health!";
								health += 10;
								rupees -= 25;
							}
						}
						else if (storeChoice == 2) {
							if (rupees - 30 < 0) {
								cout << "\nSorry, you don't have enought! Better luck Next time!";
							}
							else {
								cout << "\nGame: Congrats, you have now obtained the Eightfold Blade! You now have 5 attack!";
								attack = 5;
								rupees -= 30;
							}
						}
						else if (storeChoice == 3) {
							if (rupees - 5 < 0) {
								cout << "\nSorry, you don't have enought! Better luck Next time!";
							}
							cout << "\nGame: Congrats, you have now obtained an apple! You now have gained +1 health!";
							health ++;
							rupees -= 5;
						}

						cout << "\nYou now have " << rupees << " left!";

					}

					else if (archetype == 2) {
						cout << "\nBeedle: Oh, sorry to see you go!";
					}

					cout << "\nBeedle: Well, see you another time!";

				}

				//Do not go to the store
				else if (archetype) {

					cout << "\nGame: Bummer, we could have gotten some cool stuff!";

				}

			}

			if(lose){}
			else {

				cout << "\nGame: Be on the lookout! I see a GOLD Lynel in the distance! These beasts are stronger and tougher than the red ones!" << endl;
				while (GoldenLynelHealth > 0 && health > 0) {

					if (tie || win1 || win2) {
						if (tie) {
							cout << "\nNo damage was done!\n\n";
							tie = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win1) {
							GoldenLynelHealth = GoldenLynelHealth - attack;
							cout << "\n" << name1 << " got a hit on the Gold Lynel!\nThe Gold Lynel now has " << GoldenLynelHealth << " health left\n\n";
							win1 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win2) {
							health = health - (goldAttack - defense);
							cout << "\nThe Gold Lynel got a hit on you!\nYou now have " << health << " left\n\n";
							win2 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
					}
					else {
						//player 1
						board();
						cout << "\n\n\n";
						cout << name1 << ", would you like to do a regular move or use your ability?";
						cout << "\n\n\n";
						if (Al1) {
							cout << "Regular(1)\tAlchemist Abilty(2)";
						}
						else if (Pal1) {
							cout << "Regular(1)\tPaladin Abilty(2)";
						}

						cout << "\n\n\nWhich do you choose -> ";
						cin >> archchoice;
						while (archchoice != 1 && archchoice != 2 || cin.fail()) {
							if (cin.fail()) {
								cin.clear();
								cin.ignore();
							}
							cout << "Please put in the correct input -> ";
							cin >> archchoice;

						}

						//regular
						if (archchoice == 1) {
							cout << "\n\n\n";
							board();
							cout << "\n\nPlease input where you would like to place your character -> ";
							cin >> player1;
							playerOneBattle(player1);

						}

						//archetype ability
						else if (archchoice == 2) {

							if (Al1) {
								checkAl_Ability();
								if (flag) {
									cout << "\n\n\n";
									board();
									cout << "\n\n\nSince we have to do the default option of a regular move, choose where to put your character -> ";
									cin >> player1;
									playerOneBattle(player1);
								}
								else {
									Alchemist();
								}
							}
							else if (Pal1) {
								checkPal_Ability();
								if (flag) {
									cout << "\n\n\n";
									board();
									cout << "\n\n\nSince we have to do default option of a regular move, choose where to put your character -> ";
									cin >> player1;
									playerOneBattle(player1);
								}
								else {
									Paladin();
								}

							}

						}
					}

					checkOneBattle();
					checkbotWin();
					checkTieBattle();

					if (tie || win1 || win2) {
						if (tie) {
							cout << "\nNo damage was done!\n\n";
							tie = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win1) {
							GoldenLynelHealth = GoldenLynelHealth - attack;
							cout << "\n" << name1 << " got a hit on the Gold Lynel!\nThe Gold Lynel now has " << GoldenLynelHealth << " health left\n\n";
							win1 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}
						else if (win2) {
							health = health - (goldAttack - defense);
							cout << "\nThe bokoblin got a hit on you!\nYou now have " << health << " left\n\n";
							win2 = false;
							for (int i = 0; i < 9; i++) {
								game[i] = original[i];
							}
						}

					}
					//bot
					else {
						board();
						cout << "\n\n";
						bot("Gold Lynel");
						cout << "\n";
					}

					checkOneBattle();
					checkbotWin();
					checkTieBattle();


				}

				if (health <= 0) {
					lose = true;
				}

				//end of battle 4
				if(lose){}
				else {

					cout << "\nGame: Wow, you actaully defeated that BEAST!!!" << endl;
					cout << "Game: We finally made it past all those obstacles, let's\ngo to the castle and defeat Ganon!" << endl;
					cout << "\nGame: There is a shady looking guy up ahead, should we go there? Yes(1) No(2)" << endl;
					cout << "Choice -> ";
					cin >> option;
					while (option != 1 && option != 2 || cin.fail()) {
						if (cin.fail()) {
							cin.clear();
							cin.ignore();
						}
						cout << "Please put in the correct input -> ";
						cin >> option;
					}

					//meet the shady guy
					if (option == 1) {

						cout << "\nGame: Let's go meet the shady guy!" << endl;
						cout << "Shady Guy: Hey buddy I have got this sword that glows, You want it? Yes(1) No(2)" << endl;
						cout << "Choice -> ";
						cin >> option;
						while (option != 1 && option != 2 || cin.fail()) {
							if (cin.fail()) {
								cin.clear();
								cin.ignore();
							}
							cout << "Please put in the correct input -> ";
							cin >> option;
						}

						if (option == 1) {

							cout << "\nShady Guy: Now hold on, this sword is going to cost you 75 rupees!";
							if (rupees >= 75) {

								cout << "\nShady Guy: Here you go!";
								cout << "\n\nGame: You now have the Master Sword! This sword can do 7 damage!!!";
								attack = 7;

							}

							else {
								cout << "\nShady Guy: Sorry kid, looks like you don't have enough rupees. Better Luck next time!";
							}


						}
						
						else if (option == 2) {

							cout << "\nShady Guy: Oh well, see ya around!";

						}
					}

					//Not meet the shady guy
					else if (option == 2) {

						cout << "\nGame: Let's go onward to the castle!";

					}

				}

				if(lose){}
				else {

					cout << "\nGame: Lets go after Ganon!!!";
					cout << "\nGanon: Welcome " << name1 << "! I have expecting you for a while! Lets battle!\n\n";

					while (Ganon > 0 && health > 0) {

						if (tie || win1 || win2) {
							if (tie) {
								cout << "\nNo damage was done!\n\n";
								tie = false;
								for (int i = 0; i < 9; i++) {
									game[i] = original[i];
								}
							}
							else if (win1) {
								bokohealth = bokohealth - attack;
								cout << "\n" << name1 << " got a hit on the Ganon!\nGanon now has " << Ganon << " health left\n\n";
								win1 = false;
								for (int i = 0; i < 9; i++) {
									game[i] = original[i];
								}
							}
							else if (win2) {
								health = health - (ganonAttack - defense);
								cout << "\nGanon got a hit on you!\nYou now have " << health << " left\n\n";
								win2 = false;
								for (int i = 0; i < 9; i++) {
									game[i] = original[i];
								}
							}
						}
						else {
							//player 1
							board();
							cout << "\n\n\n";
							cout << name1 << ", would you like to do a regular move or use your ability?";
							cout << "\n\n\n";
							if (Al1) {
								cout << "Regular(1)\tAlchemist Abilty(2)";
							}
							else if (Pal1) {
								cout << "Regular(1)\tPaladin Abilty(2)";
							}

							cout << "\n\n\nWhich do you choose -> ";
							cin >> archchoice;
							while (archchoice != 1 && archchoice != 2 || cin.fail()) {
								if (cin.fail()) {
									cin.clear();
									cin.ignore();
								}
								cout << "Please put in the correct input -> ";
								cin >> archchoice;

							}

							//regular
							if (archchoice == 1) {
								cout << "\n\n\n";
								board();
								cout << "\n\nPlease input where you would like to place your character -> ";
								cin >> player1;
								playerOneBattle(player1);

							}

							//archetype ability
							else if (archchoice == 2) {

								if (Al1) {
									checkAl_Ability();
									if (flag) {
										cout << "\n\n\n";
										board();
										cout << "\n\n\nSince we have to do the default option of a regular move, choose where to put your character -> ";
										cin >> player1;
										playerOneBattle(player1);
									}
									else {
										Alchemist();
									}
								}
								else if (Pal1) {
									checkPal_Ability();
									if (flag) {
										cout << "\n\n\n";
										board();
										cout << "\n\n\nSince we have to do default option of a regular move, choose where to put your character -> ";
										cin >> player1;
										playerOneBattle(player1);
									}
									else {
										Paladin();
									}

								}

							}
						}

						checkOneBattle();
						checkbotWin();
						checkTieBattle();

						if (tie || win1 || win2) {
							if (tie) {
								cout << "\nNo damage was done!\n\n";
								tie = false;
								for (int i = 0; i < 9; i++) {
									game[i] = original[i];
								}
							}
							else if (win1) {
								Ganon = Ganon - attack;
								cout << "\n" << name1 << " got a hit on the Ganon!\nGanon now has " << Ganon << " health left\n\n";
								win1 = false;
								for (int i = 0; i < 9; i++) {
									game[i] = original[i];
								}
							}
							else if (win2) {
								health = health - (ganonAttack - defense);
								cout << "\nGanon got a hit on you!\nYou now have " << health << " left\n\n";
								win2 = false;
								for (int i = 0; i < 9; i++) {
									game[i] = original[i];
								}
							}

						}
						//bot
						else {
							board();
							cout << "\n\n";
							bot("Ganon");

							srand(time(nullptr));

							int ability = rand() % 5 + 1;

							if (ability == 1) {
								cout << "\nGame: Oh no! Ganon used his power to gain +2 health!" << endl;
								Ganon += 2;
							}
							else if (ability == 2) {
								cout << "\nGame: Oh no! Ganon used his power to get stronger!" << endl;
								ganonAttack++;

							}



							cout << "\n";
						}

						checkOneBattle();
						checkbotWin();
						checkTieBattle();


					}


					if (health <= 0) {
						lose = true;
					}

					if(lose){
					
						cout << "\n\n\tGAME OVER!!!!";
					
					}
					else {

						cout << "\n\nGanon: You have defeated me this time, but next time you will never be as lucky as you are now!" << endl;
						cout << "\n*Ganon Dissapears*";
						cout << "\n\nZelda: " << name1 << ", thanks for saving me!";
						if (notebook) {

							cout << "\nZelda: YOU FOUND MY NOTEBOOK!!!";
							cout << "\nZelda: I have been looking forever for this!!";
							cout << "\nZelda: Thank you so much. Here is the green tunic that I have been saving for you!";
							cout << "\nZelda: It should be super defensive armor for you!";
							defense = 6;


						}

						cout << "\nZelda: Let's go and fix up this entire mess that Ganon has done!";
						exit = true;

					}

				}
			}

			}
		}



		if (type != 3) {
			cout << "\n\n";
			board();

			if (win1) {
				cout << "\n" << name1 << " was the winner!";
			}
			else if (win2) {
				cout << "\n" << name2 << " was the winner!";
			}
			else if (tie) {
				cout << "\nThe game was tied";
			}

			cout << "\n\nWould you like to play again (y/n) -> ";
			cin >> choice;
			while (choice != 'y' && choice != 'n' || cin.fail()) {

				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please enter a correct value -> ";
				cin >> choice;

			}

			if (choice == 'y') {
				for (int i = 0; i < 9; i++) {
					game[i] = original[i];
				}
				win1 = false;
				win2 = false;
				tie = false;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}
		}

		else if (type == 3) {

			cout << "\n\nTHANK YOU SO MUCH FOR PLAYING!!!";
			cout << "\nCredits: Konstantinos Carrera";

			cout << "Would you like to play again? Yes(y) No(n) -> "   ;
			cin >> choice;
			while (choice != 'y' && choice != 'n' || cin.fail()) {

				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Please enter a correct value -> ";
				cin >> choice;

			}

			if (choice == 'y') {
				for (int i = 0; i < 9; i++) {
					game[i] = original[i];
				}
				win1 = false;
				win2 = false;
				tie = false;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

			}


		}

	}
}
