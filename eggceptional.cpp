#include <iostream>
#include <vector>
using namespace std;

class egg {

protected:
    string size;
    string flavor;

public:
    egg(string s, string f) : size(s), flavor(f) {}
    string getSize() const {
        return size;
    }
    string getFlavor() const {
        return flavor;
    }
    virtual void eat_egg() const = 0;

};

class scrambledEgg : public egg {

public:
    scrambledEgg() : egg("large", "spicy") {}
    void eat_egg() const override {
        cout << "This is a " << size << " and " << flavor << " pair of scramblde eggs";
    }
};

class sunnysideup : public egg {

public:
    sunnysideup() : egg("small", "buttery") {}
    void eat_egg() const override {
        cout << "Yum, these sunny side up eggs are so " << flavor << ", too bad they are " << size;
    }

};

class BadEgg {
public:
    const char* what() const noexcept {
        cout << "There is a ROTTEN EGG in this cartn, throw away immediately";
    }
};

class rottenEgg : public egg {

public:
    rottenEgg() : egg("Huge", "Rotten") {}

    void eat_egg() const override {
        throw BadEgg();
    }
};

class Carton {

private:
    vector<shared_ptr<egg>> eggs;

public:
    Carton() {
        eggs.reserve(12);
    }

    void addEgg(shared_ptr<egg> e) {
        eggs.push_back(e);
    }

    void eatEgg() {
        shared_ptr<egg> e = eggs[0];
        eggs.erase(eggs.begin());

        if (e->getFlavor() == "Rotten") {
            BadEgg bad;
            cout << bad.what() << "\n";
        }
        else {
            e->eat_egg();
        }
    }
};

int main() {

    Carton carton;
    string choice;
    int count = 12;

    carton.addEgg(make_shared<scrambledEgg>());
    carton.addEgg(make_shared<sunnysideup>());
    carton.addEgg(make_shared<scrambledEgg>());
    carton.addEgg(make_shared<sunnysideup>());
    carton.addEgg(make_shared<scrambledEgg>());
    carton.addEgg(make_shared<sunnysideup>());
    carton.addEgg(make_shared<scrambledEgg>());
    carton.addEgg(make_shared<sunnysideup>());
    carton.addEgg(make_shared<scrambledEgg>());
    carton.addEgg(make_shared<sunnysideup>());
    carton.addEgg(make_shared<scrambledEgg>());

    cout << "Do you want your eggs from a shady place(1) or a supermarket(2) -> ";
    cin >> choice;

    while (choice != "1" && choice != "2") {
        cout << "Please try again -> ";
        cin >> choice;
    }

    if (choice == "1") {
        carton.addEgg(make_shared<rottenEgg>());
    }
    else if (choice == "2") {
        carton.addEgg(make_shared<sunnysideup>());
    }

    while (count != 0) {
        carton.eatEgg();
        cout << "\n";
        count--;
    }

}
