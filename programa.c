#include "programa.h"

int** criaMatrix(int n){
    int** matrix = (int**) malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        matrix[i] = (int*) malloc(sizeof(int) * n);
    }

    return matrix;
}

void destroiMatrix(fractal uni){
    for(int i = 0; i < uni.matrix_size; i++){
        free(uni.matrix[i]);
    }
    free(uni.matrix);
}

void printMatrix(fractal uni){
    int size = uni.matrix_size;
    int** matrix = uni.matrix;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }

}

void setup(fractal* unix){
    fractal uni = *unix;
    int point, size = uni.matrix_size;
    if(size % 2 == 0){
        point = size;
    }else point = size - 1;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(i == j && i + j == point){
                uni.matrix[i][j] = 1;
                continue;
            }

            uni.matrix[i][j] = 0;
        }
    }
    unix->aglo_size = 1;
}

int tem_vizinho(int x, int y, fractal uni){
    int sum = 0;
    if(uni.matrix[x][y] == 1)sum++;
    if(x != uni.matrix_size - 1 && uni.matrix[x + 1][y] == 1){
        sum++;
    }
    if(x != 0 && uni.matrix[x - 1][y] == 1){
        sum++;
    }
    if(y != uni.matrix_size - 1 && uni.matrix[x][y + 1] == 1){
        sum++;
    }
    if(y != 0 && uni.matrix[x][y - 1] == 1){
        sum++;
    }
    return sum;
}

void find_empty(int* x, int* y, fractal uni){
    int a, b;

    do{
        a = rand() % uni.matrix_size;
        b = rand() % uni.matrix_size;
    }while(tem_vizinho(a, b, uni));

    *x = a;
    *y = b;
}

int inside(int x, int y, fractal uni){
    return (x > 0 && x < uni.matrix_size && y > 0 && y < uni.matrix_size);
}

int mov(int* x, int*y, int dir, fractal uni){
    switch(dir){
        case 0:
            *x = *x - 1;
            break;
        case 1:
            *x = *x + 1;
            break;
        case 2:
            *y = *y - 1;
            break;
        case 3:
            *y = *y + 1;
            break;
    }
    if(inside(*x, *y, uni) && tem_vizinho(*x, *y, uni)){
        return 0;
    }else return 1;
}