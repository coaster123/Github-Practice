#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    double x;
    double y;

public:

    Point(double a = 0, double b = 0) {
        x = a;
        y = b;
    }

    //distance
    double operator-(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt((dx * dx) + (dy * dy));
    }

    //midpoint
    Point operator/(const Point& other) const {
        double midX = (x + other.x) / 2;
        double midY = (y + other.y) / 2;
        return Point(midX, midY);
    }

    //check
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    //check
    bool operator!=(const Point& other) const {
        return !(x == other.x && y == other.y);
    }

    //x
    Point& operator++() {
        x++;
        return *this;
    }

    Point& operator--() {
        x--;
        return *this;
    }

    //y
    Point operator++(int) {
        Point temp = *this;
        y++;
        return temp;
    }

    Point& operator--(int) {
        Point temp = *this;
        y--;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y;
        return in;
    }
};


int main() {

    Point p1(2, 9);
    Point p2(5, 3);

    // distance
    cout << "The distance between " << p1 << " and " << p2 << " is -> " << p1 - p2 << endl;

    cout << "0 = false, 1 = true\n\n";

    // same
    cout << (p1 == p2) << "       ";
    if ((p1 == p2) == 0) {
        cout << p1 << " and " << p2 << " are not the same!" << endl;
    }
    else {
        cout << p1 << " and " << p2 << " are the same!" << endl;
    }

    // different
    cout << (p1 != p2) << "       ";
    if ((p1 != p2) == 1) {
        cout << p1 << " and " << p2 << " are different!" << endl;
    }
    else {
        cout << p1 << " and " << p2 << " are not differnt!" << endl;
    }

    // midpoint
    cout << "The midpoint between " << p1 << " and " << p2 << " is --> " << p1 / p2 << endl;

    cout << "\n\n";

    //first
    cout << "\nOriginal First Point: " << p1 << endl;
    ++p1;
    cout << "x increease by 1 --> " << p1 << endl;
    p1++;
    cout << "y increases by 1 -->  " << p1 << endl;
    --p1;
    cout << "x decreases by 1 -->  " << p1 << endl;
    p1--;
    cout << "y decreases by 1 -->  " << p1 << endl;

    cout << "\n\n";


    //second
    cout << "\nOriginal Second Point: " << p2 << endl;
    ++p2;
    cout << "x increease by 1 --> " << p2 << endl;
    p2++;
    cout << "y increases by 1 -->  " << p2 << endl;
    --p2;
    cout << "x decreases by 1 -->  " << p2 << endl;
    p2--;
    cout << "y decreases by 1 -->  " << p2 << endl;

    Point p3;
    cout << "\nEnter a point (Mkae sure there is a space in between the x and y) -->  ";
    cin >> p3;
    cout << "You entered --> " << p3 << endl;

    cout << "\n\nThe points in the program are:" << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;

}
