#include <iostream>
using namespace std;

class Node{
public:
    int m;
    Node *link;
    Node(int num = 0) : m(num) { link = NULL; }
    void insertNext(Node *nextNode)
    {
        nextNode->link = link;
        link = nextNode;
    }
    void insertFront(Node *frontNode){
        frontNode->link = link;
        link = frontNode;
    }
    
    void removeNext()
    {
        if(link!=NULL) link = link->link;
    }

    void display()
    {
        Node *p = link;
        while(p!=NULL)
        {
            cout << p->m << " => ";
            p = p->link;
        }
        cout << endl;
    }
};

int main(){
    Node head;
    head.insertNext(new Node(10));
    head.link->insertNext(new Node(20));
    head.link->link->insertNext(new Node(30));
    head.insertFront(new Node(99));
    head.display();

    head.removeNext();
    head.display();

    head.link->link->insertNext(new Node(44));
    head.display();
    
    return 0;
}