#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

inline void error(const char* str) {
    fprintf(stderr, "%s\n", str);
    exit(1);
}

class ArrayStack
{
    char data[MAX_STACK_SIZE];
    int top;
public:
    ArrayStack() { top = -1;}
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_STACK_SIZE - 1; }

    void push(char e) {
        if ( isFull() ) error("스택 포화 에러");
        data[++top] = e;
    }

    char pop() {
        if ( isEmpty() ) error("스택 공백 에러");
        return data[top--];
    }

    char peek() {
        if ( isEmpty() ) error("스택 공백 에러");
        return data[top];
    }
};

inline int precedence(char op)
{
    switch(op) {
        case '(' : case ')' : return 0;
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}

void infix2Postfix( FILE *fp = stdin )
{
    char c, op;
    double val;
    ArrayStack st;
    
    while( (c = getc(fp)) != '\n') {
        if((c >= '0' && c <= '9')){
            ungetc(c, fp);
            fscanf(fp, "%lf", &val);
            printf("%4.1f", val);
        }
        else if( c== '(')
            st.push(c);
        else if( c== ')') {
            while(!st.isEmpty()){
                op = st.pop();
                if( op=='(') break;
                else printf("%c", op);
            }
        }
        else if( c == '+' || c == '-' || c=='*' || c=='/' ) {
            while(!st.isEmpty()) {
                op = st.peek();
                if( precedence(c) <= precedence(op) ) {
                    printf("%c ", op);
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }
    while(!st.isEmpty())
        printf("%c ", st.pop());
    printf("\n");
}

int main()
{
    printf("수식 입력 (Infix) = ");
    infix2Postfix();

    return 0;
}