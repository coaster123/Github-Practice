#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main(){
    
    srand(time(0));
    const int size = 20;
    vector<int> num(size);

    for (int i = 0; i < size; i++) {
        num[i] = rand() % 100 + 1;
        cout << num[i] << " ";
    }

    cout << "\n\n";

    int* start_ptr = &num[0];
    int* end_ptr = &num[size-1];

    while (start_ptr < end_ptr) {
        start_ptr++;
        end_ptr--;
    }

    if (start_ptr > end_ptr) {
        start_ptr--;
    }

    int mid = start_ptr - &num[0];
    int midvalue = *start_ptr;

    cout << "The two points meet at index -> " << mid;
    cout << "\nThe value of the middle index is -> " << midvalue;


}
