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


int** criaMatrix(int n);

void printMatrix(fractal uni);

void setup(fractal uni);

int tem_vizinho(int x, int y, fractal uni);

void find_empty(int* x, int* y, fractal uni);

int inside(int x, int y, fractal uni);

int mov(int* x, int*y, int dir, fractal uni);

#endif