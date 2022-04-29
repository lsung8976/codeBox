#include <stdio.h>
#include <string.h>
#define MAX_STRING 100

//Student 클래스
class Student{
    int id;
    char name[MAX_STRING];
    char dept[MAX_STRING];
public:
    Student(int i = 0, char* name = "", char* dep ="") {
        set(i, name, dep);
    }
    void set(int i, char* nam, char* dep)
    {
        id = i;
        strcpy(name, nam);
        strcpy(dept, dep);
    }
    void display()
    {
        printf("학번 : %-15d 성명:%-10s 학과:%-20s\n", id, name, dept);
    }
};

// student node 클래스
class Node : public Student
{
    Node* link;
public:
    Node(int id = 0, char * name ="", char * dept="") : Student(id, name, dept) {link = NULL;}
    ~Node(void) {}
    Node *getLink() { return link; }
    void setLink(Node *p) { link = p; }
};

// linkedStack 클래스
class LinkedStack{
    Node *top;
public:
    LinkedStack() { top = NULL; }
    ~LinkedStack() { while(!isEmpty()) delete pop();}
    bool isEmpty() {return top == NULL; }
    void push( Node *n ){
        if( isEmpty() ) top = n;
        else{
            n->setLink( top );
            top = n;
        }
    }
    Node *pop(){
        if( isEmpty() ) return NULL;
        Node *n = top;
        top = top->getLink();
        return n;
    }
    Node *peek(){ return top; }
    void display(){
        printf("[LinkedStack]\n");
        for(Node *p = top; p != NULL; p=p->getLink())
            p->display();
        printf("\n");
    }
};

int main()
{
    LinkedStack stack;
    stack.push( new Node(20181234, "홍길동", "컴퓨터공학과"));
    stack.push( new Node(20184567, "이순신", "기계공학과"));
    stack.push( new Node(20184567, "황희","법학과"));
    stack.display();

    Node *node = stack.pop();
    printf("[pop항목]\n");
    node->display();
    printf("\n");
    delete node;
    stack.display();

    return 0;
}