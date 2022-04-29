#include <iostream>
#define MAX_SIZE 10
using namespace std;

class Brackets
{
    int top;
    char box[MAX_SIZE];
public:
    Brackets(const char *c) : top(-1) 
    { 
        for(int i = 0; c[i] != NULL; i++)
        {
            switch(c[i])
            {
                case '(': 
                    push('(');
                    break;
                case '{':
                    push('{');
                    break;
                case '[':
                    push('[');
                    break;
                case ')': 
                    if( isEmpty() )
                    {
                        printf("오류\n");
                        break;
                    }
                    else
                    {
                        if(pop() != '(') printf("오류\n");
                        break;
                    }
                    break;
                case '}': 
                    if( isEmpty() )
                    {
                        printf("오류\n");
                        break;
                    }
                    else
                    {
                        if(pop() != '{') printf("오류\n");
                        break;
                    }
                    break;
                case ']':
                    if( isEmpty() )
                    {
                        printf("오류\n");
                        break;
                    }
                    else
                    {
                        if(pop() != '[') printf("오류\n");
                        break;
                    }
                    break;
                default: break;
            }
        }
        if(top != -1)   printf("오류\n");
    }

    void push(char x)
    {
        if( isFull() )
        {
            printf("가득 차서 더이상 들어갈 수 없습니다.\n");
            return;
        }
        box[++top] = x;
        //display();
        //printf("%d가 들어갔습니다.\n", x);
    }

    char pop()
    {
        if( isEmpty() )
        {
            printf("비어 있어서 더이상 나올게 없습니다.\n");
            return 0;
        }
        return box[top--];
    }

    void peek()
    {
        printf("맨위에 %d가 있습니다..\n ", box[top]);
    }

    void display()
    {
        for(int i = 0 ; i <= top; i++)
        {
            printf("< %d > ", box[i]);
        }
        printf("\n");
    }


    int size()
    {
        return top;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAX_SIZE -1 ;
    }
};


int main()
{
    Brackets bk("(ab{c}d)f[g]");

    return 0;
}