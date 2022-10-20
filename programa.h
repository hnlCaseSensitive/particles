#ifndef _PROGRAMA_H_
#define _PROGRAMA_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct frac
{
    int** matrix;
    int aglo_size, matrix_size;
}fractal;

// criaMatrix : Int - > ponteiro para ponteiro de int
// aloca dinamicamente uma matrix n x n dado n passado por argumento
int** criaMatrix(int n);

// printMatrix : fractal -> void
// imprime a matrix na tela
void printMatrix(fractal uni);

// setup : fractal -> void
// inicializa as variaveis
void setup(fractal* uni);

// tem_vizinho : int int fractal -> int
// verifica se existe um vizinho dado as coordenadas x e y
int tem_vizinho(int x, int y, fractal uni);

// find_empty : int int fractal -> void
// altera os valores de x e y para que apontem para um local vazio e sem vizinhos
void find_empty(int* x, int* y, fractal uni);

// inside : int int fractal -> int
// verifica se as coordenadas x e y estao dentro da matrix
int inside(int x, int y, fractal uni);

// mov : int int int fractal -> int
// dado um movimento aleatorio altera as variaveis para condizer com o movimento
int mov(int* x, int*y, int dir, fractal uni);

// destroiMatrix : fractal -> void
// desaloca a memoria alocada pela matrix
void destroiMatrix(fractal uni);

#endif