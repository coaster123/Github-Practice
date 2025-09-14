#include <iostream>
#include <vector>
using namespace std;

class Factorizer {
public:
	vector<int> primeNumbers(int n) {

		vector<int> prime;
		int check = 2;

		if (n <= 1) {
			return prime;
		}
		else {

			while (n > 1) {
				while (n%check == 0) {
					prime.push_back(check);
					n /= check;
				}
				check++;
			}

			return prime;
		}

	}
};


int main() {

	Factorizer factorizer;
	int num = 0;

	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	bool flag4 = false;

	//check
	if (factorizer.primeNumbers(0).empty()) {
		flag1 = true;
	}
	if (factorizer.primeNumbers(1).empty()) {
		flag2 = true;
	}

	vector <int> check1 = { 3,3 };
	if (factorizer.primeNumbers(9) == check1) {
		flag3 = true;
	}

	vector <int> check2 = { 2,5 };
	if (factorizer.primeNumbers(10) == check2) {
		flag4 = true;
	}

	if (flag1 && flag2 && flag3 && flag4) {


		cout << "Enter in a number -> ";
		cin >> num;

		vector<int> factors = factorizer.primeNumbers(num);

		cout << "Prime Numbers that multiply to the number you inputed:";
		cout << "\n";

		for (int f : factors) {
			cout << f << " ";
		}

	}

	else {
		cout << "This program does not work";
	}

}
