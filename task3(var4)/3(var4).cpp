#include <iostream>
#include <string>
#include <initializer_list>

using namespace std;

//Створюємо класс рядка
class Line
{
protected:
    //Поле класа з string
    string line;
public:
    //Конструктор за замовчуванням
    Line() : line("")
    {
        cout << "Line default constructor\n";
    }

    //Конструктор з текстом
    Line(const string& newLine) : line(newLine)
    {
        cout << "Line constructor(string newLine)\n";
    }

    //Конструктор копії
    Line(const Line& other) : line(other.line)
    {
        cout << "Line copy constructor\n";
    }

    //Деструктор
    virtual ~Line()
    {
        cout << "Line destructor\n";
    }

    //Перевантажений оператор присвоєння
    Line& operator=(const Line& other)
    {
        //Якщо цей рядок не дорівнює іншому рядку, то записуємо інший рядок в цей
        if (this != &other)
        {
            this->line = other.line;
            cout << "Line assignment operator\n";
        }

        return *this;
    }

    //Перевантажений оператор виводу
    friend ostream& operator<<(ostream& out, Line& text)
    {
        out << text.line;
        return out;
    }

    //Перевантажений оператор вводу
    friend istream& operator>>(istream& is, Line& text)
    {
        getline(is, text.line);
        return is;
    }
};

//Створюємо похідний клас рядок із цифр від класу рядок
class LineNumbers : public Line
{
public:
    //Конструктор за замовчуванням
    LineNumbers() : Line()
    {
        cout << "Line of numbers constructor\n";
    }

    //Конструктор з рядком із цифр
    LineNumbers(const string& numbers)
    {
        cout << "Line of numbers constructor(string text)\n";
        //Перевіряємо, чи в рядку тільки цифри
        for (char c : numbers)
        {
            try
            {
                //Якщо знаходимо не цифру, кидаємо виключення
                if (!isdigit(c))
                {
                    throw string("This text, is not numbers");
                }
            }
            //Ловимо виключення та виводимо помилку на екран
            catch (string error)
            {
                cout << error << endl;
                return;
            }
        }

        line = numbers;
    }

    //Конструктор копії, який викликає конструктор копії базового класу
    LineNumbers(const LineNumbers& other) : Line(other)
    {
        cout << "Line of numbers copy constructor\n";
    }

    //Деструктор
    ~LineNumbers()
    {
        cout << "Line of numbers destructor\n";
    }

    //Перевантажений оператор присвоєння, який викликає оператор присвоєння базового класу
    LineNumbers& operator=(const LineNumbers& other)
    {
        Line::operator=(other);
        return *this;
    }

    //Перевантаженийоператор виводу
    friend ostream& operator<<(ostream& out, LineNumbers& text)
    {
        out << text.line;
        return out;
    }

    //Перевантажений оператор вводу
    friend istream& operator>>(istream& is, LineNumbers& text)
    {
        //Створюємо рядок і записуємо в нього текст з клавіатруи
        string input;
        getline(is, input);

        //Проходимося по кожному символу в рядку
        for (char c : input)
        {
            try
            {
                //Якщо знаходимо не цифру, кидаємо виключення
                if (!isdigit(c))
                {
                    throw string("This text, is not numbers");
                }
            }
            //Ловимо виключення та виводимо помилку на екран
            catch (string error)
            {
                cout << error << endl;
                return;
            }
        }

        text.line = input;
        return is;
    }
};

int main()
{
    cout << "Base class Line:\n";
    Line l1;
    Line l2("Hello world!");
    Line l3(l2);

    cout << "Line1: " << l1 << endl;
    cout << "Line2: " << l2 << endl;
    cout << "Line3: " << l3 << endl;

    Line l4("Hello!");
    Line l5;
    l5 = l4;

    cout << "Line4: " << l4 << endl;
    cout << "Line5: " << l5 << endl;

    Line l6;
    cout << "Enter a line 6 text: ";
    cin >> l6;
    cout << "Line6: " << l6 << endl;

    cout << "\n----------------------------------------------\n";
    cout << "Derived class LineNumbers:\n";
    LineNumbers ln1;
    LineNumbers ln2("Hello world");
    LineNumbers ln3("123456");
    LineNumbers ln4(ln3);

    cout << "Line of numbers 1: " << ln1 << endl;
    cout << "Line of numbers 1: " << ln2 << endl;
    cout << "Line of numbers 1: " << ln3 << endl;
    cout << "Line of numbers 1: " << ln4 << endl;

    LineNumbers ln5;
    LineNumbers ln6("7890");
    ln5 = ln6;

    cout << "Line of numbers 5: " << ln5 << endl;
    cout << "Line of numbers 6: " << ln6 << endl;

    LineNumbers ln7;
    cout << "Enter a line of numbers 7 digits:\n";
    cin >> ln7;
    cout << "Line of numbers 7: " << ln7 << endl;
}