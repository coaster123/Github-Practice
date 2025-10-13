#include <iostream>
#include <vector>
#include <cassert>
#include <functional>
using namespace std;

template <typename T>
vector<T> vec_fill(T elem)
{
    vector<T> vec;
    for (int i = 0; i < 10; i++)
    {
        vec.push_back(elem + i);
    }
    return vec;
}

template <typename U, typename Transformer, typename Predicate>
U until(U x, Transformer transformer, Predicate predicate)
{
    if (predicate(x))
    {
        return x;
    }
    return until(transformer(x), transformer, predicate);
}

template <typename T>
void sort_descending(T& x, T& y, T& z) {
    cout << "Before -> x: " << x << " y: " << y << " z: " << z << "\n";

    if (x < y) {
        swap(x, y);
    }
    if (y < z) {
        swap(y, z);
    }
    if (x < y) {
        swap(x, y);
    }

    cout << "After  -> x: " << x << " y: " << y << " z: " << z << "\n";
}

int two(int x)
{
    return x * 2;
}

bool hundredCheck(int x)
{
    return x >= 100;
}


int main()
{
    auto vec = vec_fill(1);
    for (auto a : vec)
    {
        cout << a << " ";
    }

    cout << "\n\n";

    assert(until(5, two, hundredCheck) == 160);
    assert(until(2, two, hundredCheck) == 128);
    assert(until(3, two, hundredCheck) == 192);

    int a = 3, b = 5, c = 1;
    sort_descending(a, b, c);
    assert(a == 5 && b == 3 && c == 1);

    double x = 4.2, y = 9.5, z = 2.8;
    sort_descending(x, y, z);
    assert(x == 9.5 && y == 4.2 && z == 2.8);
    
    cout << "\n\n";


    cout << "Pass!!";
    
}

