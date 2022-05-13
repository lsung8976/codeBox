#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX_LIST_SIZE 100
using namespace std;

inline void error ( char * str ) {
    fprintf(stderr, "%s\n", str);
    exit(1);
};

class ArrayList{
    int data[MAX_LIST_SIZE];
    int length;
public:
    ArrayList(void) {length = 0;}

    void insert(int pos, int e){
        if( !isFull() && pos >= 0 && pos <= length){
            for(int i = length; i >pos ; i--)
                data[i] = data[i-1];
            data[pos] = e;
            length++;
        }
        else error("포화상태 오류 또는 삽입 위치 오류");
    }

    void remove(int pos){
        if(!isEmpty() && 0 <= pos && pos <=length){
            for(int i = pos +1 ; i < length; i++)
                data[i-1] = data[i];
            length--;
        }
        else error("공백상태 오류 또는 삭제 위치 오류");
    }

    int getEntry(int pos) {return data[pos];}
    bool isEmpty() {return length == 0;}
    bool isFull() {return length== MAX_LIST_SIZE; }

    bool find(int item){
        for(int i= 0;i<length;i++)
            if(data[i] == item) return true;
        return false;
    }
    void replace(int pos, int e){
        data[pos] = e ;
    }
    int size(){return length;}
    void display(){
        printf("[배열로 구현한 리스트 전체 항목 수 = %2d] : ", size());
        for(int i =0 ;i <size(); i++)
            printf("[%2d]",data[i]);
        printf("\n");
    }
    void clear() { length = 0;}
};

int main()
{   
    ArrayList list;
    list.insert(0, 10);
    list.insert(0, 20);
    list.insert(1, 30);
    list.insert(list.size(), 40);
    list.insert(2, 50);
    list.display();
    cout << "the value of index 2 : "<< list.getEntry(2) << endl;
    list.replace(0, 100);
    list.display();

    list.remove(2);
    list.remove(list.size() - 1 );
    list.remove(0);
    list.replace(1, 90);
    list.display();

    list.clear();
    list.display();

    return 0;
}