#include <iostream>
using namespace std;

float power(float num, int i){
    if(i == 1) return num;
    else return num * power(num, i - 1);
}

int main()
{
    cout << "1.5^20=" << power(1.5,20) << endl;

}
