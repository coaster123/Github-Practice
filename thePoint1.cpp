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

    
    double operator-(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt((dx * dx) + (dy * dy));
    }

    
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    
    bool operator!=(const Point& other) const {
        return !(x == other.x && y == other.y);
    }

    Point operator/(const Point& other) const {
        double midX = (x + other.x) / 2;
        double midY = (y + other.y) / 2;
        return Point(midX, midY);
    }

    friend ostream& operator<<(ostream& out, const Point& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};


int main() {

    Point p1(2, 9);
    Point p2(5, 3);
    
    //distance
    cout << "The distance between " << p1 << " and " << p2 << " is -> " << p1 - p2 << endl;  
    
    
    cout << "0 = false, 1 = true\n\n";

    //same
    cout << (p1 == p2) << "       "; 
    if ((p1 == p2) == 0) {
        cout << p1 << " and " << p2 << " are not the same!" << endl;
    }
    else {
        cout << p1 << " and " << p2 << " are the same!" << endl;
    }
    
    //different
    cout << (p1 != p2) << "       "; 
    if ((p1 != p2) == 1) {
        cout << p1 << " and " << p2 << " are different!" << endl;
    }
    else {
        cout << p1 << " and " << p2 << " are not differnt!" << endl;
    }

    //midpoint
    cout << "The midpoint between " << p1 << " and " << p2 << " is --> " << p1 / p2 << endl;

}
