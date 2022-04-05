#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int x, y;
    int result = 0;
    cout << "input x = ";
    cin >> x;
    cout << "input y = ";
    cin >> y;

    while(x>0)
    {
        if(x%2 == 1)
            result += y;
        x >>= 1;
        y <<= 1;
    }
    cout << "Result :" << result << endl;
}