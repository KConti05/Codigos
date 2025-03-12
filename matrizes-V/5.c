/*
Desenvolver uma função que receba duas matrizes de inteiros, ambas de ordem 10, com as seguintes características:
a. M1: matriz contendo números inteiros quaisquer;
b. M2: matriz contendo apenas os valores 0 ou 1.
Desenvolver uma função que a partir destas matrizes gere a matriz M3, também de ordem 10, cujos elementos são definidos da seguinte forma:
M2ij = 0 → M3ij = M1ij
M2ij = 1 → M3ij = soma dos elementos da linha i com os da coluna j da matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void geraMatrizAlatoria(int lin, int col, int m[lin][col], int limite)
{
    int i, j;
    srand(time(NULL));
    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            m[i][j]=rand()%limite;
        }
    }
}
void exibeMatriz(int lin, int col, int m[lin][col])
{
    int i, j;
    for(i=0;i<lin;i++)
    {
        printf("\n");
        for(j=0;j<col;j++)
        {
            printf("%i ", m[i][j]);
        }
    }
}
int somaLinha(int m[N][N], int lin)
{
    int j, soma=0;
    for(j=0;j<N;j++)
    {
        soma+=m[lin][j];
    }
    return soma;
}
int somaColuna(int m[N][N], int col)
{
    int i, soma=0;
    for(i=0;i<N;i++)
    {
        soma+=m[i][col];
    }
    return soma;
}
void geraMatrizM3(int m1[N][N], int m2[N][N], int m3[N][N])
{
    int i, j, somaLin, somaCol;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(m2[i][j]==0)
            {
                m3[i][j]=m1[i][j];
            }
            else
            {
                somaLin=somaLinha(m1, i);
                somaCol=somaColuna(m1, j);
                m3[i][j]=somaLin+somaCol;
            }
        }
    }
}
int main()
{
    int m1[N][N], m2[N][N], m3[N][N];
    //preenchendo 'm1' e 'm2'
    geraMatrizAlatoria(N, N, m1, 10);
    geraMatrizAlatoria(N, N, m2, 2);
    //exibindo 'm1' e 'm2'
    printf("\nm1:\n");
    exibeMatriz(N, N, m1);
    printf("\nm2:\n");
    exibeMatriz(N, N, m2);
    //preenchendo 'm3'
    geraMatrizM3(m1, m2, m3);
    //exibindo 'm3'
    printf("\nm3:\n");
    exibeMatriz(N, N, m3);
    return 0;
}