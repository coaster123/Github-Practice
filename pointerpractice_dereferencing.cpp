#include <iostream>
using namespace std;

int main(){
    
    int a = 0;
    int b = 0;
    cout << "Enter the value of a -> ";
    cin >> a;
    cout << "Enter the value of b -> ";
    cin >> b;

    int* ptr_a = &a;
    int* ptr_b = &b;

    cout << "The value of ptr_a is -> " << *ptr_a;
    cout << "\nThe value of ptr_b is -> " << *ptr_b;


}
