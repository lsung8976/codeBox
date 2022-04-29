#include <iostream>
#include <stdio.h>
using namespace std;

void swap(int &x, int &y);
void add_swap(int *p1, int *p2);

int add(int a, int b);
int main()
{
    const char* stringArr[3]={
        "fervent-lecture",
        "TCP/IP",
        "SocketProgramming"
    };

    char str1[5] = {'a','b','c'};
    char str2[5] = "abc";
    str2[2]='D';
    
    int (*fp)(int ,int);
    fp = add;

    int a[5]= {1,2,3,4,5};
    int b=9;
    int *pB=&b;
    double e = 3.14;
    double *pE = &e;
    char ca = 65, cb = 66;
    char* arr[2] = {&ca, &cb};
    const char* strarr[3] = {"abc", "defg", "hijkl"};
    int arrInt[5] = {1, 2, 3, 4 ,5};
    char arrChar[100];


    printf("%d, %d\n", a[0], a[1]);
    printf("%d, %d\n", &a[0], &a[1]);
    printf("%d\n", a);
    printf("%d, %f\n", *pB, *pE);
    printf("%d, %d\n", &pB, &pE);
    printf("%d\n", *arr[0]);
    printf("%d\n", *arr[1]);
    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d, %d \n", &arr[0], &ca);
    printf("%d, %d \n", &arr[1], &cb);
    printf("%lu\n", sizeof(arr[0]));
    printf("%lu\n", sizeof(*arr[0]));
    printf("%d\n", &strarr[0]);
    printf("%d\n", &strarr[1]);
    printf("%d\n", &strarr[2]);
    printf("%s\n", strarr[0]);
    printf("%s\n", strarr[1]);
    printf("%s\n", strarr[2]);
    printf("%lu\n", sizeof(strarr[0]));
    printf("%lu\n", sizeof(strarr[1]));
    printf("%lu\n", sizeof(strarr[2]));
    printf("%lu\n", sizeof(arr));
    printf("%lu\n", sizeof(strarr));

    pB=arrInt;
    printf("pB의 정체 : %d\n",pB);
    printf("arrInt의 정체 : %d\n",arrInt);
    printf("arrInt를 받은 pB[3]의 정체 : %d\n",pB[3]);

    printf("-----------------------\n");
    printf("%s\n", stringArr[0]);
    printf("%s\n", stringArr[1]);
    printf("%s\n", stringArr[2]);
    printf("%d\n", stringArr[0]);
    printf("%d\n", stringArr[1]);
    printf("%d\n", stringArr[2]);
    printf("%d\n", sizeof(stringArr[0]));
    printf("%d\n", sizeof(stringArr[1]));
    printf("%d\n", sizeof(stringArr[2]));
    printf("%d\n", sizeof(*stringArr[0]));
    printf("%d\n", sizeof(*stringArr[1]));
    printf("%d\n", sizeof(*stringArr[2]));


    //*arr1 => arr[2] //char형
    //arr2[100] => arrChar[100]

    printf("-----------------------\n");
    printf("%d\n", sizeof(arr));
    printf("%d\n", sizeof(arrChar));
    printf("%d\n", sizeof(&arr));
    printf("%d\n", sizeof(&arrChar));
    printf("%d\n", sizeof(arr[0]));
    printf("%d\n", sizeof(arrChar[0]));

    printf("-----------------------\n");

    printf("%c\n", str1[0]);
    printf("%c\n", str1[1]);
    printf("%c\n", str1[2]);
    printf("%c\n", str1[3]);
    printf("%c\n", str1[4]);
    printf("##\n");

    printf("%c\n", str2[0]);
    printf("%c\n", str2[1]);
    printf("%c\n", str2[2]);
    printf("%c\n", str2[3]);
    printf("%c\n", str2[4]);
    printf("##\n");

    int x = 100;
    int y = 200;
    printf("%d, %d\n", x, y);
    swap(x, y);
    printf("%d, %d\n", x, y);
    add_swap(&x, &y);
    printf("%d, %d\n", x, y);

    printf("================\n");
    
    cout << fp(1, 2) << endl;
    cout << (* fp)(3, 4) << endl;


    return 0;
}

void swap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void add_swap(int *p1, int *p2)
{
    int tmp;    //tmp는 주소를 저장하는게 아니다

    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int add(int a, int b){ return a + b; }