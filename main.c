#include "programa.h"

int main(void){

    srand(time(NULL));

    fractal uni;

    printf("selecione o tamanho da matrix: ");
    scanf("%d", &uni.matrix_size);

    uni.matrix = criaMatrix(uni.matrix_size);

    setup(&uni);

    printMatrix(uni);

    int x, y;
    while(uni.aglo_size < 5){
        find_empty(&x, &y, uni);
        while(inside(x, y, uni)){
            int flag = mov(&x, &y, rand() % 4, uni);
            if(flag == 0){
                uni.aglo_size += 1;
                uni.matrix[x][y] = 1;
                break;
            }
        }
    }
    printf("\n");
    printMatrix(uni);

    destroiMatrix(uni);

    return 0;
}