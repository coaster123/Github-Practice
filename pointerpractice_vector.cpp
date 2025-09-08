#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main(){
    
    srand(time(0));
    vector<int> num(20);

    for (int i = 0; i < 20; i++) {
        num[i] = rand() % 100 + 1;
        cout << num[i] << " ";
    }

    cout << "\n\n";

    int* start = &num[0];
    int* end = &num[20-1];

    while (start < end) {
        start++;
        end--;
    }

    if (start > end) {
        start--;
    }

    int mid = start - &num[0];
    int midvalue = *start;

    cout << "The two points meet at index '" << mid << "' and the value of that is -> " << midvalue;

}
