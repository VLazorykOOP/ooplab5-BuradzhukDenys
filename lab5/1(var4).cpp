#include <iostream>

using namespace std;

const double pi = 3.14; //число пі

class Point //Створюємо клас точки
{
protected:
    double x, y; //Координати точки
public:
    Point() : x(0), y(0) {} //Конструктор за замовчуванням

    Point(double newX, double newY) : x(newX), y(newY) {} //Конструктор, який приймає координати для точки

    virtual ~Point() {} //Деструктор

    //Гетери
    double GetCoordinateX() const {return x;}
    double GetCoordinateY() const{return y;}

    //Сетери
    void SetCoordinateX(double newX){this->x = newX;}
    void SetCoordinateY(double newY){this->y = newY;}

    //Метод для виведення даних на екран
    virtual void print() const
    {
        cout << "Point(" << x << ", " << y << ")\n";
    }

    //Метод для обчислення площі
    virtual double area() const
    {
        return 0.0;
    }
};

class Ellipse : public Point //Створюємо похідний клас еліпс, від точки
{
private:
    double a, b; //Півосі еліпса
public:
    Ellipse() : Point(), a(0), b(0) {} //Конструктор за замовчуванням
    Ellipse(double newX, double newY, double newA, double newB) : Point(newX, newY), a(newA), b(newB) {} //Конструктор, який приймає координати для центру еліпса, та його піввісь

    ~Ellipse() {} //Деструктор

    //Гетери
    double GetMajorAxis() const {return a;}
    double GetMinorAxis() const {return b;}

    //Сетери
    void SetMajorAxis(double newA) {this->a = newA;}
    void SetMinorAxis(double newB) {this->b = newB;}

    //Метод для виведення даних на екран
    void print() const override
    {
        cout << "Ellipse center: (" << x << ", " << y << "), axes: " << a << ", " << b << endl;
    }

    //Метод для обчислення площі
    double area() const override
    {
        return pi * a * b;
    }
};

class Circle : public Ellipse //Створюємо похідний клас коло, від еліпса
{
public:
    Circle() : Ellipse() {} //Конструктор за замовчуванням
    Circle(double newX, double newY, double radius) : Ellipse(newX, newY, radius, radius) {} //Конструктор, який приймає координати для центру кола, та його радіус

    ~Circle() {} //Деструктор

    //Гетери
    double GetRadius() const {return GetMajorAxis();};

    //Сетери
    void SetRadius(double radius)
    {
        SetMajorAxis(radius);
        SetMinorAxis(radius);
    }

    //Метод для виведення даних на екран
    void print() const override
    {
        cout << "Circle center: (" << x << ", " << y << "), radius: " << GetMajorAxis() << endl;
    }

    //Метод для обчислення площі
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