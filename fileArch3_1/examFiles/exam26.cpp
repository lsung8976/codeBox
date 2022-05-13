#include <iostream>
using namespace std;


class Node{
    char data;
public:
    Node* link;
    Node(char c = ' '){
        data = c;
        link = NULL;
    }

    Node* getLink() { return link; }
    void setLink(Node *next) { link = next; }
    void display() {
        for(Node *p = link; p != NULL; p = p->link)
            printf("%2c", p->data);
        cout << endl;
    }

    void insertNext(Node *nextNode){
        if(nextNode != NULL){
            nextNode->link = link;
            link = nextNode;
        }
    }

    void insertFront(Node *frontNode){
        if(frontNode != NULL){
            frontNode->link = link;
            link = frontNode;
        }
    }

    Node* removeNext()
    {
        Node *p = link;
        if(link != NULL) link = link->link;
        return p;
    }
};

int main()
{
    Node head;
    head.insertNext(new Node('a'));
    head.link->insertNext(new Node('b'));
    head.link->link->insertNext(new Node('c'));

    head.insertFront(new Node('d'));
    head.insertNext(new Node('e'));
    head.insertFront(new Node('f'));

    head.display();

    head.removeNext();
    head.display();

    head.link->link->insertNext(new Node('g'));
    head.link->link->insertFront(new Node('h'));
    head.display();
    return 0;
}