#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;
#define MAX_STACK_SIZE 100

inline void error(char * str){
    fprintf(stderr, "%s\n", str);
    exit(1);
};

class Student{
    const char* name;
    string email;
    int studentNumber;
    string phone;

public:
    Student(const char* name = "", string email = "", int studentNumber = 0, string phone="") {
        this->name = name;
        this->email = email;
        this->studentNumber = studentNumber;
        this->phone = phone;
    }

    void setName(const char* name) {
        this->name = name;
    }

    void setEmail(string email){
        this->email = email;
    }

    void setStudentNumber(int number){
        studentNumber = number;
    }

    void setPhone(string phone){
        this->phone = phone;
    }

    const char* getName(){
        return name;
    }

    string getEmail(){
        return email;
    }

    int getStudentNumber(){
        return studentNumber;
    }

    string getPhone(){
        return phone;
    }
};

class Node{
    Node* link;
    Student data;
public:
    Node(const char* name = "", string mail= "", int number = 0, string p_num= ""){
        data = Student(name, mail, number, p_num);
        link = NULL;
    }

    Node* getLink() { return link; }
    void setLink(Node *next) { link = next; }
    void display() {
        cout << data.getName() << "." << data.getStudentNumber() << "." << data.getEmail() << "." << data.getPhone() << endl;
    }

    void insertNext(Node *n){
        if(n != NULL){
            n->link = link;
            link = n;
        }
    }

    bool hasData(int val){return data.getStudentNumber() == val;};

    Node *removeNext()
    {
        Node *p = link;
        if(link != NULL) link = link->link;
        return p;
    }
};

class LinkedList{
    Node org;
public:
    LinkedList() {}
    ~LinkedList() { clear(); }

    void clear() {while (!isEmpty()) delete remove(0); }
    Node * getHead() { return org.getLink(); }
    bool isEmpty() {return getHead() == NULL; }

    Node *getEntry(int pos){
        Node *n = &org;
        for(int i = -1; i < pos; i++, n= n->getLink()){
            if(n == NULL) break;
        }
        return n;
    }

    void insert(int pos, Node *n){
        Node *prev = getEntry(pos - 1);
        if(prev != NULL)
            prev-> insertNext(n);
    }

    Node * remove(int pos){
        Node * prev = getEntry(pos - 1);
        return prev->removeNext();
    }

    Node *find(int studentNumber){
        for(Node *p = getHead(); p != NULL; p = p->getLink())
            if(p->hasData(studentNumber)) return p;
    }

    void replace(int pos, Node *n){
        Node* prev = getEntry(pos - 1);
        if(prev != NULL){
            delete prev->removeNext();
            prev->insertNext(n);
        }   
    }

    int size(){
        int count = 0;
        for(Node *p = getHead(); p != NULL; p = p->getLink())
            count++;
        return count;
    }

    int display(const char* str = "리스트"){
        printf("%s", str);
        printf("[단순 연결 리스트 항목 수 = %2d] : \n", size() );
        for(Node *p = getHead(); p != NULL; p = p->getLink())
            p->display();
        printf("\n");
    }
};

int main()
{
    LinkedList list, list2;

    list.insert(0, new Node("kim", "kim@ssu.ac.kr", 001, "010-2323-2314"));
    list.insert(0, new Node("Park", "Park@ssu.ac.kr", 002, "010-2323-2314"));
    list.insert(1, new Node("Lee", "Lee@ssu.ac.kr", 003, "010-2323-2314"));
    list.display();

    list.insert(1, new Node("Choi", "Choi@ssu.ac.kr", 004, "010-2323-2314"));
    list.insert(2, new Node("Jung", "Hung@ssu.ac.kr", 005, "010-2323-2314"));
    list.display("2개 추가후");
    cout << "studentNumber = 3  인 노드의 다음 노드" << endl;
    list.find(3)->removeNext()->display();
    list.display("studentNumber = 3 인 노드의 다음 노드 삭제 후");

    return 0;
}