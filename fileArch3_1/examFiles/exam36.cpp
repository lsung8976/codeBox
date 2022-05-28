
#include <stdio.h>

#define WIDTH	20
#define HEIGHT	10

void labelComponent(unsigned char img[HEIGHT][WIDTH], int x, int y, int label){
    if( x < 0 || y < 0 || x >= HEIGHT || y >= WIDTH ) return;
    if( img[x][y] == 9 ) {
        img[x][y] = label;
        labelComponent(img, x - 1, y, label);
        labelComponent(img, x, y - 1, label);
        labelComponent(img, x + 1, y, label);
        labelComponent(img, x, y + 1, label);
    }
}

void printImage(unsigned char img[HEIGHT][WIDTH] , char *str = "default"){
    printf("%s", str);
    for(int i = 0; i < HEIGHT; i++){  
        for(int j = 0; j < WIDTH; j++){
            if( img[i][j] >= 1 && img[i][j] <= 9) printf("%d", img[i][j]);
            else printf(".");
        }
        printf("\n");
    }
}

void blobColoring(unsigned char img[HEIGHT][WIDTH]){
    char label = 1;
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if( img[i][j] == 9 ) labelComponent(img, i, j, label++);
        }
    }
}


int main()
{
	unsigned char image[HEIGHT][WIDTH] = {
		0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		9,9,9,9,9,0,9,0,0,0,0,0,0,0,0,9,0,0,9,9,
		0,0,9,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		0,9,9,9,0,0,9,9,9,0,0,9,0,0,0,0,0,0,9,9,
		0,9,0,9,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		9,9,0,9,9,0,9,0,0,0,0,0,0,0,0,0,0,0,9,9,
		9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,0,0,
		9,0,0,0,9,0,9,0,0,0,0,0,9,0,9,0,0,0,9,9,
		0,0,0,0,0,0,9,0,0,0,0,9,9,9,9,9,0,0,9,9,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
	};

	printImage  ( image, "<Original image>\n" );
	blobColoring( image );
	printImage  ( image, "<Labelled image>\n" );
	
	return 0;
}