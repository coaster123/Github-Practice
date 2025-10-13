
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

int two(int x)
{
    return x * 2;
}

bool hundredCheck(int x)
{
    return x >= 100;
}

template <typename V>
void order(V& a, V& b, V& c)
{
    cout << "a: " << a << " b: " << b << " c: " << c;
    cout << "\n";
    while (a < b || b < c || a < c)
    {
        if (a < b)
        {
            V temp = b;
            b = a;
            a = temp;
        }

        if (b < c)
        {
            V temp = c;
            c = b;
            b = temp;
        }
    }
    cout << "a: " << a << " b: " << b << " c: " << c << endl;
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
    order(a, b, c);
    assert(a == 5 && b == 3 && c == 1);

    double x = 4.2, y = 9.5, z = 2.8;
    order(x, y, z);
    assert(x == 9.5 && y == 4.2 && z == 2.8);
    
    cout << "\n\n";


    cout << "Pass!!";
    
}
