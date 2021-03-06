#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

//class Node2
class Node2{
    Node2* prev;
    Node2* next;
    int data;
public:
    Node2(int val = 0) : data(val), prev(NULL), next(NULL){}
    Node2* getPrev() {return prev;}
    Node2* getNext() {return next;}
    void setPrev(Node2* p) { prev = p;}
    void setNext(Node2* n) { next = n; }
    void display() {printf(" <%2d>", data);}

    void insertNext(Node2 *n){
        if(n!= NULL){
            n->prev = this;
            n->next = next;
            if(next != NULL) next->prev = n;
            next = n;
        }
    }

    Node2* removeNext(){
        if(prev != NULL) prev->next = next;
        if(next != NULL) next->prev = prev;
        return this;
    }
    
};

//class DblLinkedList
class DblLinkedList{
    Node2 org;
public:
    DblLinkedList(): org(0) {}
    ~DblLinkedList() { while(!isEmpty()) delete remove(0); }
    Node2* getHead() {return org.getNext(); }
    bool isEmpty() {return getHead() == NULL; }
    void clear() {while(!isEmpty()) delete remove(0);}

    int size(){
        Node2 *n = &org;
        int cnt = 0;
        while(n->getNext() != NULL)
        {
            cnt++;
            n = n->getNext();
        }
        return cnt;
    }
    
    Node2* getEntry(int pos){
        Node2* n = &org;
        for(int i = -1; i < pos; i++ , n = n->getNext())
            if(n == NULL) break;
        return n;
    }

    void insert(int pos, Node2 *n){
        Node2 *prev = getEntry(pos - 1);
        if(prev != NULL)
            prev->insertNext(n);
    }

    Node2* remove(int pos) {
        Node2* prev = getEntry(pos);
        return prev->removeNext();
    }

    void replace(int pos, Node2 *n){
        Node2 *prev = getEntry(pos - 1);
        remove(pos);
        if(prev != NULL)
            prev->insertNext(n);
    }
    
    void display()
    {
        printf("[the size of the doubly linked list = %2d : ", size());
        for(Node2 *p = getHead(); p != NULL; p = p->getNext())
            p->display();
        printf("\n");
    }
};

int main()
{
    DblLinkedList list;
    
    list.insert(0, new Node2(10));
    list.insert(0, new Node2(20));
    list.insert(1, new Node2(30));
    list.insert(list.size(), new Node2(40));
    list.insert(2, new Node2(50));
    list.display();

    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);

    list.replace(1, new Node2(90));
    list.display();

    list.clear();

    list.display();

    return 0;
}