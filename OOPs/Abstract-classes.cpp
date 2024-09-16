#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
};

class Rectangle : Shape
{
public:
    void draw()
    {
        cout << "Rectangle \n";
    }
};

class Square : Shape
{
public:
    void draw()
    {
        cout << "Square \n";
    }
};

int main()
{
    Rectangle rec;
    Square sq;

    rec.draw();
    sq.draw();
    return 0;
}