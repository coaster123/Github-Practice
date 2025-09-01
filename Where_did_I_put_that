#include <iostream>
#include <string>
using namespace std;

void findCharacter(const string& s, char c) {


	cout << "\n\n";
	if (s.find(c) == string::npos) {
		cout << "Value is -1";
	}
	else {
		cout << "Value is at " << s.find(c);
	}

}

void findString(const string& s, string i) {

	if (s.find(i) == string::npos) {
		cout << "Value is -1";
	}
	else {
		cout << "Value is " << s.find(i);
	}
	
}

int main(){
	
	int choice = 0;
	cout << "Do you want to find a character(1) or a string(2) -> ";
	cin >> choice;
	string user = "The quick brown fox";

	if (choice == 1) {

		char findC;
		cout << "What do you want to find -> ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		findC = cin.get();
		findCharacter(user, findC);


	}
	else if (choice == 2) {

		string findS = "";
		cout << "What do you want to find -> ";
		cin >> findS;
		findString(user, findS);

	}

	
}
