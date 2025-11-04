#include <string>
#include <iostream>
#include <set>
using namespace std;

class Unicorn {

private:
    string name;
    static set<string> takenName;

public:

    Unicorn(const string& unicornName) {

        if (takenName.count(unicornName) > 0) {
            cout << "This name for a Unicorn is already taken!" << endl;
            name = "";
        }
        else {
            name = unicornName;
            takenName.insert(unicornName);
            cout << name << " has joined the party!" << endl;
        }
    }

    ~Unicorn() {
        if (name != "") {
            cout << name << " has left the party!" << endl;
            takenName.erase(name);
        }
    }
};

set<string> Unicorn::takenName;

int main(){

    Unicorn* one = new Unicorn("Heisenburg");
    Unicorn* two = new Unicorn("Saul_Goodman");
    Unicorn* three = new Unicorn("Jesse_Pinkman");

    Unicorn u4("Jesse_Pinkman");

    delete one;
    
}


