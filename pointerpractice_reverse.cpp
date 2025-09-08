#include <iostream>
#include <string>
using namespace std;

int main(){
    
    char str[] = "Computer Science";
    char* ptr = str;
    int length = 0;

    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    cout << "Lenght of the string is -> " << length;
    
    cout << "\n\n";
    cout << "The reverse of the string is -> ";
    for (int i = length; i >= 0; i--) {
        cout << str[i];
    }


}
