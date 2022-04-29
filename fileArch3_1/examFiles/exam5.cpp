#include <iostream>
using namespace std;

class Vehicle{
public:
    int speed = 0;

    void speedup()
    {
        cout << "Vehicle speed " << (speed += 2) << endl;
    }

    void speeddown()
    {
        cout << "Vehicle speed " << (speed -= 2) << endl;
    }
};

class Car : public Vehicle{
    
public:
    void turboboost()
    {
        cout << "Car speed " << (speed *= 2) << endl;
    }
    void speedup() //오버라이딩
    {
        cout << "Car speed " << (speed += 3) << endl;
    }

    void speeddown() // 오버라이딩
    {
        cout << "Car speed " << (speed -= 3) << endl;
    }
};

class Truck : public Vehicle{
    
public:
    void speedup() // 오버라이딩
    {
        cout << "Truck speed " << (speed += 1) << endl;
    }

    void speeddown() // 오버라이딩
    {
        cout << "Truck speed " << (speed -= 1) << endl;
    }
};

int main()
{
    Vehicle v;
    Car c;
    Truck t;
    v.speedup();
    v.speedup();
    v.speeddown();

    c.speedup();
    c.speedup();
    c.turboboost();
    c.speeddown();

    t.speedup();
    t.speedup();
    t.speeddown();

    return 0;
}