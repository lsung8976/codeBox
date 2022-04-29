#include <iostream>
using namespace std;

class Complex
{
public:
    int real;
    int imagine;
    Complex(int re = 0, int im = 0) : real(re), imagine(im) {}
    
    void print()
    {
        if (imagine >= 0)
            cout << "(" << real << "+" << imagine << "i)";
        else
            cout << "(" << real << imagine << "i)";
    }
    void add(Complex &a, Complex &b)
    {
        real = a.real + b.real;
        imagine = a.imagine + b.imagine;
    }
};

int main()
{
    Complex a(7, 8);
    a.print();
    cout << "+";
    Complex b(2, 9);
    b.print();
    cout << "=";
    Complex c;
    c.add(a, b);
    c.print();
    cout << endl;

    Complex d(5, 3);
    d.print();
    cout << "+";
    Complex e(3, -4);
    e.print();
    cout << "=";
    Complex f;
    f.add(d, e);
    f.print();
    cout << endl;

    return 0;
}