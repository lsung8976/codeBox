#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int**  alloc2DInt(int r, int c) {
    if( r <= 0 || c <= 0) return NULL;
    int** map = new int* [r];
    for(int i=0; i < r; i++) {
        map[i] = new int[c];
    }
    return map;
}

void print2DInt(int **mat, int r, int c) {
    if(mat != NULL) {
        for(int i = 0; i < r ; i++){
            for(int j = 0 ;j < c ; j++)
            {
                printf("%3d ", mat[i][j]);
            }
            cout << endl;
        }
    }
}

void free2DInt(int **mat, int r, int c) {
    if(mat != NULL) {
        for(int i = 0; i < r ; i++)
            delete [] mat[i];
        delete [] mat;
    }
}

void set2D(int **map, int r, int c) {
    if(map != NULL) {
        for(int i = 0; i < r ; i++){
            for(int j = 0 ;j < c ; j++) {
                map[i][j] = (i + 1) * (j + 1);
            }
        }
    }
}

int main()
{
    int **mat;
    class Matsize{
    public:
        int row, col;
        Matsize(int r = 0, int c = 0){
            row = r;
            col = c;
        }
        void setSize(int r, int c){
            row = r;
            col = c;
        }
    };


    Matsize s[4];
    s[0].setSize(3,4);
    s[1].setSize(7, 10);
    s[2].setSize(12, 6);
    s[3].setSize(16, 8);
    for(int i = 0; i < 4; i++) {
        printf("%d row %d col \n", s[i].row, s[i].col);
        mat = alloc2DInt(s[i].row, s[i].col);   //2차원 배열을 동적으로 할당하는 함수
        set2D(mat, s[i].row, s[i].col);         //mat[i][k] = (i+1) * (j+1)로 만드는 함수
        print2DInt(mat, s[i].row, s[i].col);    //2차원 배열을 출력하는 함수
        free2DInt(mat, s[i].row, s[i].col);     //동적으로 할당 되었던 2차원 배열을 삭제 하는 함수

        cout << endl;
    }
    return 0;
}