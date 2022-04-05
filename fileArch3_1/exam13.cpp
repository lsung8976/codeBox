#include <cstdio>
using namespace std;

int findMaxValue(int *p, int index)
{
    int max = p[0];
    for(int i = 1; i < index; i++)
    {
        max = (p[i] > max) ? p[i] : max;
    }
    return max;
}


int main()
{
    int arr[10] = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
    int maxVal;

    maxVal = findMaxValue(arr, 10);

    printf("배열의 최대 값 = %d \n", maxVal);
    return 0;
}