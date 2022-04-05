#include <iostream>
#define MAX_SIZE 7
using namespace std;


class Stack
{
    int top;
    int box[MAX_SIZE];
public:
    Stack() : top(-1) { }
    void push(int x)
    {
        if( isFull() )
        {
            printf("가득 차서 더이상 들어갈 수 없습니다.\n");
            return;
        }
        box[++top] = x;
        printf("%d가 들어갔습니다.\n", x);
    }

    void pop()
    {
        if( isEmpty() )
        {
            printf("비어 있어서 더이상 나올게 없습니다.\n");
            return;
        }
        printf("%d가 빠져나왔습니다.\n ", box[top--]);
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
        if(top == -1)   return 1;
        else
        {
            return 0;
        }
    }
    bool isFull()
    {
        if(top == MAX_SIZE)   return 1;
        else
        {
            return 0;
        }
    }
};


int main()
{
    Stack st;

    st.push(1);
    st.push(21);
    st.push(11);
    st.push(14);
    st.push(13);
    st.push(12);
    st.push(32);
    st.push(42);
    st.push(52); 
    st.peek();

    st.display();

    st.pop();
    st.pop();
    st.pop();
    st.pop();

    st.display();

    return 0;
}