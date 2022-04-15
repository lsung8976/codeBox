#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_STACK_SIZE 100

inline void error(const char* str) {
    fprintf(stderr, "%s\n", str);
    exit(1);
}

class OperandStack
{
    double data[MAX_STACK_SIZE];
    int top;
public:
    OperandStack() {top = -1;}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }

    void push(double e) {
        if ( isFull() ) error("스택 포화 에러");
        data[++top] = e;
    }

    double pop() {
        if ( isEmpty() ) error("스택 공백 에러");
        return data[top--];
    }
};

double calcPostfixExpr( FILE *fp = stdin )
{
    char c;
    double val;
    OperandStack st;
    
    while( (c=getc(fp)) != '\n') {
        if( c=='+' || c == '-' || c=='*' || c=='/' ) {
            double val2 = st.pop();
            double val1 = st.pop();
            switch(c){
                case '+' : st.push (val1 + val2); break;
                case '-' : st.push (val1 - val2); break;
                case '*' : st.push (val1 * val2); break;
                case '/' : st.push (val1 / val2); break;
            }
        }
        else if((c >= '0' && c <= '9')){
            ungetc(c, fp);
            fscanf(fp, "%lf", &val);
            st.push(val);
        }
    }
    return (st.pop());
}

int main()
{
    printf("수식 입력 (Postfix) = ");
    double res = calcPostfixExpr();
    printf("계산 결과 => %f \n", res);

    return 0;
}