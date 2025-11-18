#include <iostream>
#include <math.h>
#include <array>
using namespace std;

bool isPrime(int n) {

    for (int i = 0; i <= sqrt(n); i++) {

        if (n % i == 0) {

            return false;

        }
        else {
            return true;
        }

    }

}

int main() {

    string items[] = { "Milk","Chicken","Egg","Pickles","Sugar"};
    cout << "Let's make some pancakes!" << endl;

    cout << "\n\n";

    cout << "The ingrediants we have are -> " << endl;
    for (int i = 0; i < 5; i++) {

        cout << items[i] << endl;

    }







}
