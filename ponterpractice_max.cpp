#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {

    srand(time(0));

    int arr[10];

    for (int i = 0; i < 10; i++) {

        arr[i] = rand() % 10 + 1;
        cout << arr[i] << " ";

    }

    int* max_ptr = &arr[0];

    for (int i = 0; i < 10; i++) {
        if (arr[i] > *max_ptr) {
            max_ptr = &arr[i];
        }
    }

    cout << "\n\nMax number in this random array of numbers is -> " << *max_ptr;

}
