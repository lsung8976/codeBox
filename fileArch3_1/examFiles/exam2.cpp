#include <iostream>
using namespace std;

int find_gcd(int ,int);

int main()
{
    int a, b;
    cout << "a=";
    cin >> a;

    cout << "b=";
    cin >> b;

    cout << "GCD=" << find_gcd(a,b);
    return 0;
}

int find_gcd(int a, int b)
{
    while (1)
    {
        if (a > b) a = a - b;
        else if (b > a) b = b - a;
        else break;
    }
    return a;
}