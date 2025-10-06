

#include <functional>
#include <iostream>
#include <cassert>
using namespace std;



int until(int x, function<int(int)> f, function<bool(int)> g) {
    while (!g(x)) {
        x = f(x);
    }
    return x;
}

int double_number(int n) {
    return n * 2;
}

bool greater_than_100(int n) {
    return n > 100;
}

bool greater_than_200(int n) {
    return n > 200;
}

bool greater_than_500(int n) {
    return n > 500;
}


int main() {

    assert(until(1, double_number, greater_than_100) == 128);
    assert(until(1, double_number, greater_than_200) == 256);
    assert(until(1, double_number, greater_than_500) == 512);

    cout << "PASS!";
   
}

