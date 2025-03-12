/*
Pede-se o desenvolvimento de uma função recursiva que, dada uma matriz M de L linhas e C colunas, onde L e C são constantes, e três linhas L1, L2 e L3, altere os elementos de L3, de forma que cada um consista na soma dos elementos de L1 e L2, conforme ilustrado no exemplo abaixo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 8
#define C 5

void geraMatrizAleatoria(int lin, int col, int m[lin][col], int limite)
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
            printf("%i ",m[i][j]);
        }
    }
}
void somaDuasLinhas(int col, int m[][col], int lin1, int lin2, int lin3)
{
    int j;
    for(j=0;j<col;j++)
    {
        m[lin3][j]=m[lin1][j]+m[lin2][j];
    }
}
int main()
{
    int mat[L][C], lSoma1, lSoma2, lResult;
    //preenchendo a matriz
    geraMatrizAleatoria(L, C, mat, 10);
    //exibindo a Matriz
    exibeMatriz(L, C, mat);
    //perguntando linhas a serem alteradas
    printf("\nQual a primeira linha a ser somada?\n");scanf("%i",&lSoma1);
    printf("\nQual a segunda linha a ser somada?\n");scanf("%i",&lSoma2);
    printf("\nQual a linha que armazenara as somas?\n");scanf("%i",&lResult);
    //realizando operacao
    somaDuasLinhas(C, mat, lSoma1, lSoma2, lResult);
    //exibindo a matriz alterada
    exibeMatriz(L, C, mat);
    return 0;
}