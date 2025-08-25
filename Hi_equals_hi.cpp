
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string strcmp_case_insensitive(string one, string two){

    string temp1 = one;
    string temp2 = two;

    temp1.erase(remove(temp1.begin(),temp1.end(),' '),temp1.end());
    temp2.erase(remove(temp2.begin(),temp2.end(),' '),temp2.end());

    transform(temp1.begin(),temp1.end(),temp1.begin(),::tolower);
    transform(temp2.begin(),temp2.end(),temp2.begin(),::tolower);

    if(temp1 == temp2){
        cout << "The Comparison of " << one << " and " << two << " returns 0";
    }
    else if(temp1 > temp2){
        cout << "The Comparison of " << one << " and " << two << " returns 1";
    }
    else if(temp2 > temp1){
        cout << "The Comparison of " << one << " and " << two << " returns -1";
    }


    return 0;
}

int main(){

    string one = "";
    string two = "";

    cout << "What is your first string -> ";
    getline(cin,one);
    cout << "\nWhat is the second string -> ";
    getline(cin,two);

    cout << "\n\n";

    strcmp_case_insensitive(one,two);

}
