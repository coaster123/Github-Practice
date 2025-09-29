
#include <iostream>
#include <cmath>
using namespace std;

class Shape {

public:

    double area;
    double perimeter;
    virtual void getArea() {}
    virtual void getPerimeter(){}

};

class Circle : public Shape {

    double pi = 3.14159265359;
    double radius;

public:

    Circle(double r) : radius(r){}

    void getArea() override {
        area = pi * (radius * radius);
        cout << area;
    }

    void getPerimeter() {
        perimeter = 2 * pi * radius;
        cout << perimeter;
    }
};

class Rectangle : public Shape {

    double width;
    double length;

public:

    Rectangle(double l, double w) : length(l), width(w){}

    void getArea() override {
        area = length * width;
        cout << area;
    }

    void getPerimeter() {
        perimeter = (2 * width) + (2 * length);
        cout << perimeter;
    }
};

class RightTriangle : public Shape {

    double base;
    double height;
    double longSide;

public:

    RightTriangle(double b, double h, double l) : base(b), height(h), longSide(l){}

    void getArea() {
        area = (base * height) / 2;
        cout << area;
    }

    void getPerimeter() {
        perimeter = longSide + base + height;
        cout << perimeter;
    }
};

int main() {


    //Circle
    double radius;
    cout << "----Circle------";
    cout << "\n\nWhat is the radius for Cirlce -> ";
    cin >> radius;
    cout << "\nThe area of the Circle is -> ";
    Shape* C = new Circle(radius);
    C->getArea();
    cout << "\nThe Perimeter of the Circle is -> ";
    C->getPerimeter();


    //Rectangle
    double length;
    double width;
    cout << "\n\n\n-------Rectangle-------";
    cout << "\n\nWhat is the length for the Rectangle -> ";
    cin >> length;
    cout << "What is the width for the Rectangle -> ";
    cin >> width;
    Shape* R = new Rectangle(length, width);
    cout << "\nThe area of the Rectangle is -> ";
    R->getArea();
    cout << "\nThe Perimeter of the Rectangle is -> ";
    R->getPerimeter();

    //Right Triangle
    double base;
    double height;
    double LongSide;
    cout << "\n\n\n-------Right Triangle-------";
    cout << "\n\nWhat is the base for the Right Triangle -> ";
    cin >> base;
    cout << "What is the height for the Right Triangle -> ";
    cin >> height;
    cout << "What is the long side for the Right Triangle -> ";
    cin >> LongSide;
    Shape* T = new RightTriangle(base, height,LongSide);
    cout << "\nThe area of the Right Triangle is -> ";
    T->getArea();
    cout << "\nThe Perimeter of the Rectangle is -> ";
    T->getPerimeter();



}
