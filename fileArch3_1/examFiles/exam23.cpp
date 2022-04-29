#include <stdio.h>
#include <stdlib.h>

inline void error (const char *str ) {
    fprintf(stderr, "%s\n", str);
}

#define MAX_QUEUE_SIZE 10

class CircularQueue
{
protected:
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
    int lastOp;
public:
    CircularQueue() {front = rear = lastOp = 0; }
    ~CircularQueue() { }
    bool isEmpty() { return (lastOp == 0) && (front == rear); }
    bool isFull() { return (lastOp == 1) && (rear == front); };

    void enqueue( int var ) {
        if( isFull() )
            error(" error : 큐가 포화상태입니다\n");
        else{
            rear = (rear + 1) % MAX_QUEUE_SIZE;
            data[rear] = var;
            lastOp = 1;
        }
    }

    int dequeue() {
        if( isEmpty() )
            error(" error : 큐가 공백상태입니다\n");
        else {
            front = (front + 1)%MAX_QUEUE_SIZE;
            return data[front];
            lastOp = 0;
        }
    }
    int peek() {
        if( isEmpty() )
            error(" error : 큐가 공백상태입니다\n");
            
        else
            return data[(front + 1)% MAX_QUEUE_SIZE];
    }
    void display() {
        printf("큐 내용 : ");
        int maxi = (front < rear) ? rear : rear+MAX_QUEUE_SIZE;
        for(int i = front + 1; i <= maxi; i++)
            printf("[%2d]", data[i%MAX_QUEUE_SIZE]);
        printf("\n");
    }
};

int main()
{
    CircularQueue que;
    for(int i=1;i<15;i++)
        que.enqueue(i);
    que.display();

    for(int i=1;i<6;i++)
        que.dequeue();
    que.display();
    
    for(int i=1;i<15;i++)
        que.enqueue(i);
    que.display();

    return 0;
}