#include <iostream>
#include <string>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

inline void error(const char* str) {
    fprintf(stderr, "%s\n", str);
    exit(0);
};

class ArrayStack{
    char data[MAX_STACK_SIZE];
    int top;
public:
    ArrayStack() { top = -1; }
    ~ArrayStack() {}
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

bool CheckMatching(string s) {
    ArrayStack stack;
    char ch;
    cout << s << "검사를 시작합니다." << endl;
    for(int i=0;i < s.length(); i++) {
        ch = s.at(i);
        if( ch == '(' || ch == '{' || ch == '[' )
            stack.push(ch);
        if( ch == ')' || ch == '}' || ch == ']' )
            stack.pop();
    }

    if(!stack.isEmpty())
        printf("Error\n");
    else   
        printf("OK\n");
    return stack.isEmpty();
}

int main()
{
    CheckMatching("({[()]([])})")?printf("맞음\n"):printf("문법오류\n");
    CheckMatching("({[([])]([{([({})])[({[]})]}])})")?printf("맞음\n"):printf("문법오류\n");
    CheckMatching("(()")?printf("맞음\n"):printf("문법오류\n");
    return 0;
}