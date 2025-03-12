#include <iostream>

using namespace std;

const double pi = 3.14;

class Point
{
protected:
    double x;
    double y;
public:
    Point() : x(0), y(0) {}

    Point(double newX, double newY) : x(newX), y(newY) {}

    virtual ~Point() {}

    double GetCoordinateX() const {return x;}
    double GetCoordinateY() const{return y;}

    void SetCoordinateX(double newX){this->x = newX;}
    void SetCoordinateY(double newY){this->y = newY;}

    virtual void print() const
    {
        cout << "Point(" << x << ", " << y << ")\n";
    }

    virtual double area() const
    {
        return 0.0;
    }
};

class Ellipse : public Point
{
private:
    double a, b;
public:
    Ellipse() : Point(), a(0), b(0) {}
    Ellipse(double newX, double newY, double newA, double newB) : Point(newX, newY), a(newA), b(newB) {}

    ~Ellipse() {}

    double GetMajorAxis() const {return a;}
    double GetMinorAxis() const {return b;}

    void SetMajorAxis(double newA) {this->a = newA;}
    void SetMinorAxis(double newB) {this->b = newB;}

    void print() const override
    {
        cout << "Ellipse center: (" << x << ", " << y << "), axes: " << a << ", " << b << endl;
    }

    double area() const override
    {
        return pi * a * b;
    }
};

class Circle : public Ellipse
{
public:
    Circle() : Ellipse() {}
    Circle(double newX, double newY, double radius) : Ellipse(newX, newY, radius, radius) {}

    ~Circle() {}

    double GetRadius() const {return GetMajorAxis();};

    void SetRadius(double radius)
    {
        SetMajorAxis(radius);
        SetMinorAxis(radius);
    }

    void print() const override
    {
        cout << "Circle center: (" << x << ", " << y << "), radius: " << GetMajorAxis() << endl;
    }

    double area() const override
    {
        return pi * (GetRadius() * GetRadius());
    }
};

int main()
{
    Point p;
    Ellipse e;
    Circle c;

    p.print();
    cout << "Point area: " << p.area() << endl;

    e.print();
    cout << "Ellipse area: " << e.area() << endl;

    c.print();
    cout << "Circle area: " << c.area() << endl;

    Point p2(3.8, 12);
    Ellipse e2(10, 12.5, 3, 6);
    Circle c2(3.8, 5.9, 6);

    p2.print();
    cout << "Point area: " << p2.area() << endl;

    e2.print();
    cout << "Ellipse area: " << e2.area() << endl;

    c2.print();
    cout << "Circle area: " << c2.area() << endl;

    p2.SetCoordinateX(20);
    p2.SetCoordinateY(30);
    p2.print();
    cout << "Point area: " << p2.area() << endl;

    e2.SetCoordinateX(50);
    e2.SetCoordinateY(100);
    e2.SetMajorAxis(12);
    e2.SetMinorAxis(18);
    e2.print();
    cout << "Ellipse area: " << e2.area() << endl;

    c2.SetCoordinateX(5);
    c2.SetCoordinateY(10);
    c2.SetRadius(12);
    c2.print();
    cout << "Circle area: " << c2.area() << endl;
}