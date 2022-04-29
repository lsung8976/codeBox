#include <iostream>
using namespace std;

class Rectangle{
    int width;
    int height;
public:
    Rectangle(int a, int b)
    {
        width = a;
        height = b;
    }
    int calcArea() //메소드
    {
        return width * height;
    }
};

int main()
{
    Rectangle r(3, 4);

    cout << "사각형의 넓이 : " << r.calcArea() << '\n';
    return 0;
}