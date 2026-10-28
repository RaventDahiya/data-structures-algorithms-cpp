// runtime / dynamic polymorphism

#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual void draw()
    {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape
{
    void draw() override
    {
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape
{
    void draw() override
    {
        cout << "Drawing a rectangle" << endl;
    }
};

void draw_shape(Shape *shape)
{
    shape->draw();
}

int main()
{
    Shape *shape1 = new Circle();
    Shape *shape2 = new Rectangle();
    draw_shape(shape1);
    draw_shape(shape2);

    return 0;
}