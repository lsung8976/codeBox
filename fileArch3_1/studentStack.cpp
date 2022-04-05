#include <iostream>
using namespace std;

class Student {
    const char* name;
    int studentNumber;
public:
    Student(const char* name = "", int studentNumber = 0) {
        this->name = name;
        this->studentNumber = studentNumber;
    }
    
    void setName(const char* name){
        this->name = name;
    }

    void setStudentNumber(int number){
        studentNumber = number;
    }

    const char* getName(){
        return name;
    } 

    int getStudentNumber(){
        return studentNumber;
    }
};

const int MAX_STACK_SIZE = 20;

class ArrayStack{
    int top;
    Student *data[MAX_STACK_SIZE];
public:
    ArrayStack() { top = -1; }
    ~ArrayStack() {}
    bool isEmpty() {return top == -1; }
    bool isFull() {return top == MAX_STACK_SIZE -1; }


    void push(Student *p){
        if (isFull()) printf("스택 포화 에러");
        data[++top] = p;
    }

    Student * pop(){
        if (isEmpty()) printf("스택 공백 에러");
        return data[top--];
    }

    void display(){
        cout << "[스택 항목의 수] => " << top + 1 << endl;
        for (int i = top; i >=0 ; i--)
            cout << data[i]->getName() << ", " << data[i]->getStudentNumber() << endl;
    }
};

int main()
{
    ArrayStack stack;

    Student a;
    a.setName("Park");
    a.setStudentNumber
    (1000);

    Student b("Kim", 2000);

    Student c("Lee");
    c.setStudentNumber(3000);

    stack.push(&a);
    stack.push(&b);
    stack.push(&c);
    stack.display();

    cout << "POP!!" << endl;
    Student *p;
    p = stack.pop();
    cout << p->getName() << endl;
    cout << p->getStudentNumber() << endl;
    stack.display();

    stack.pop();
    stack.pop();
    stack.display();
    return 0;
}