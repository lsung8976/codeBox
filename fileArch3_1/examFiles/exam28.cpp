#include <iostream>
#include <stdio.h>
using namespace std;

class Node{
    Node* link;
    int data;
public:
    Node(int val = 0) : data(val), link(NULL) {}
    Node* getLink() {return link;}
    void setLink(Node *next) {link = next;}
    void display() {printf(" <%2d>", data);}
};

class LinkedQueue{
    Node* front;
    Node* rear;
public:
    LinkedQueue(): front(NULL), rear(NULL) {}
    ~LinkedQueue() { while(!isEmpty()) delete dequeue();  }
    bool isEmpty() { return front == NULL;  }

    void enqueue(Node *p) {
        if(isEmpty()) front = rear = p;
        else{
            rear->setLink(p);
            rear = p;
        }
    }

    Node* dequeue(){
        if( !isEmpty() ){
            Node* p = front;
            front = front->getLink();
            return p;
        }
        else return NULL;
    }

    void display(){
        printf("\nQ : ");
        for(Node *p = front; p != rear; p = p->getLink())
            p->display();
        printf("\n");
    }
};

int main()
{
    LinkedQueue que;
    for(int i = 1; i < 10; i++)
        que.enqueue(new Node(i));
    que.display();

    que.dequeue()->display();
    que.dequeue()->display();
    que.dequeue()->display();
    
    que.display();

    return 0;
}