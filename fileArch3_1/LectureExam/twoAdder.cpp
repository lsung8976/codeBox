#include <iostream>
using namespace std;

int main()
{
    int a, b, b_cpy;
    int sum=0;
    b_cpy = 0;
    cin >> a >> b;

    while(a!=0)
    {
        if(a%2)
            b_cpy = b;
        cout << a << " " << b << " " << b_cpy << endl;
        a>>=1;
        b<<=1;
        sum+=b_cpy;
        b_cpy = 0;
    }
    cout << sum << endl;
    return 0;
}