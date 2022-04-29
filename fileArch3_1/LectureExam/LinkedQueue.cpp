#include <iostream>
using namespace std;

class Node{
    Node* link;
    int data;
public:
    Node(int val = 0) : data(val), link(NULL) {}
    Node* getLink() {return link;}
    void setLink(Node *next) {link = next;}
    void display() {printf(" <%2d> ", data);}
};

class LinkedQueue{
    Node* front;
    Node* rear;
public:
    LinkedQueue() : front(NULL), rear(NULL) { }
    ~LinkedQueue() { while(!isEmpty()) delete dequeue(); }
    bool isEmpty() {return front==NULL; }

    void enqueue(Node *p){
        if(isEmpty()) front = rear = p;
        else{
            rear->setLink(p);
            rear = p;
        }
    }
    Node* dequeue(){
        if(isEmpty()) return NULL;
        else if((front->getLink() == rear->getLink()) && (rear->getLink()== NULL)){
            Node *p = front;
            front = rear = NULL;
            return p;
        }
        else{
            Node *p = front;
            front = front->getLink();
            return p;
        }
    }

    void display(){
        for(Node *p = front; p != NULL; p = p->getLink())
            p->display();
        cout << endl;
    }
};

int main()
{
    LinkedQueue que;
    for(int i=1 ;i< 10; i++)
        que.enqueue(new Node(i));
    que.display();
    delete que.dequeue();
    delete que.dequeue();
    delete que.dequeue();
    que.display();
}