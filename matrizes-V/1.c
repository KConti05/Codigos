#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

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
int confereRegraN(int lin, int col, int m[lin][col])
{
    int i, j, somaDiag=0, somaCima=0, somaBaixo=0;
    //somando
    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==j)
            {
                somaDiag+=m[i][j];
            }
            else if(j>i)
            {
                somaCima+=m[i][j];
            }
            else
            {
                somaBaixo+=m[i][j];
            }
        }
    }
    //conferindo regra
    if(somaDiag==somaCima&&somaDiag==somaBaixo)
    {
        return 1;
    }
    return 0;
}
int main()
{
    //chamando variáveis
    int mat[N][N], mat2[N][N]={{6,3,1,2,6},
                               {1,3,5,4,2},
                               {3,4,4,2,2},
                               {5,9,1,9,3},
                               {4,0,2,1,8}}, regra;
    //gerando 'mat'
    geraMatrizAleatoria(N, N, mat, 10);
    //exibindo matrizes
    printf("\nMatriz 'mat': ");
    exibeMatriz(N, N, mat);
    printf("\nMatriz 'mat2':");
    exibeMatriz(N, N, mat2);
    //conferindo regra nas matrizes
    printf("\nMat segue a regra?");
    regra=confereRegraN(N, N, mat);
    if(regra!=0)
    {
        printf("\nSegue!:D");
    }
    else
    {
        printf("\nNao segue:(");
    }
    printf("\nMat2 segue a regra?");
    regra=confereRegraN(N, N, mat2);
    if(regra!=0)
    {
        printf("\nSegue!:D");
    }
    else
    {
        printf("\nNao segue:(");
    }
    return 0;
}