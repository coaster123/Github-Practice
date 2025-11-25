
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


//Queue
class Queue {
private:
    vector<int> data;
public:
    void enqueue(int v) {
        data.push_back(v);
    }

    bool empty() const {
        return data.empty();
    }
};


//Wuack
class Quack {
private:
    vector<int> data;
public:
    void push_front(int v) {
        data.insert(data.begin(), v);
    }

    void push_back(int v) {
        data.push_back(v);
    }

    int pop_front() {
        if (data.empty()) {
            throw out_of_range("Quack empty");
        }
        int x = data.front();
        data.erase(data.begin());
        return x;
    }

    int pop_back() {
        if (data.empty()) {
            throw out_of_range("Quack empty");
        }
        int x = data.back();
        data.pop_back();
        return x;
    }

    bool empty() const {
        return data.empty();
    }
};

