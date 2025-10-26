
#include <iostream>
#include <array>
#include <fstream>
#include <string>
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
string ch2 = "" ;
bool Al1 = false;
bool Al2 = false;
bool Pal1 = false;
bool Pal2 = false;
bool flag = false;


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
				while (y != 2 && y != 4 && y != 5 || y == x ||cin.fail()) {
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

int main() {

	int type = 0;
	char choice = 'y';
	int gamesPlayed = 0;
	int archetype = 0;
	int archchoice = 0;


	while (choice == 'y') {

		cout << "Choose a name Player 1 -> ";
		getline(cin, name1);
		cout << "Choose a name Player 2 -> ";
		getline(cin, name2);

		cout << "\n\nWould you want to play regular(1) or battle(2) tictactoe -> ";
		cin >> type;

		while (type != 1 && type != 2 || cin.fail()) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
			}
			cout << "Please enter the correct value -> ";
			cin >> type;

		}

		//Regular
		if (type == 1) {

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
}
