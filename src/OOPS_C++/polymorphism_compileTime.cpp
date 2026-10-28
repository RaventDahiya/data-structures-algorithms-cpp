#include <bits/stdc++.h>
using namespace std;

// compile time polymorphism

// function overloading
class Shape
{
public:
    void area(int side)
    {
        cout << "Area of square: " << side * side << endl;
    }

    void area(int length, int breadth)
    {
        cout << "Area of rectangle: " << length * breadth << endl;
    }

    void area(float radius)
    {
        cout << "Area of circle: " << 3.14 * radius * radius << endl;
    }
};

// operator overloading
class Complex
{

private:
    float real;
    float imag;

public:
    Complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex const &c)
    {
        Complex res;
        res.real = real + c.real;
        res.imag = imag + c.imag;
        return res;
    }

    void print()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    complex c1(3.5, 2.5), c2(1.6, 4.7);
    complex c3 = c1 + c2;
    c3.print();

    return 0;
}