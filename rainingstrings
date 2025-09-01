#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {

	string business = "";
	vector <string> b;
	string choice;
	cout << "Welcome to the Business Sorting Program!";
	cout << "\nPlease enter the name of a buisness -> ";

	getline(cin,business);

	b.push_back(business);

	cout << "\nYour business is:";
	cout << "\n\n";
	
	for (size_t i = 0; i < b.size(); i++) {
		cout << "\t" << b[i] << "\n";
	}

	cout << "\nAnother Business(Yes,yes,y,Y,no) -> ";
	cin >> choice;

	while (choice == "yes" || choice == "Yes" || choice == "y" || choice == "Y") {

		cout << "\nPlease enter the name of a buisness -> ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, business);

		b.push_back(business);

		cout << "\nYour business is:";
		cout << "\n\n";

		std::sort(b.begin(), b.end());

		for (size_t i = 0; i < b.size(); i++) {
			cout << "\t" << b[i] << "\n";
		}

		cout << "\nAnother Business(Yes,yes,y,Y,no) -> ";
		cin >> choice;

	}

	cout << "\n\nThank you for using the Business Sorting Program!";

}
