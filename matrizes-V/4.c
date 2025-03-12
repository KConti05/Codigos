/*
Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que verifique se os elementos da matriz estão ordenados de forma crescente. Para isto, as seguintes regras devem ser atendidas:
a. Os elementos de cada linha devem estar ordenados crescentemente (ou seja, cada elemento será maior ou igual àquele da mesma linha, porém da coluna anterior – caso exista);
b. O primeiro elemento de cada linha deve ser maior ou igual ao último da linha anterior (caso exista). Caso a matriz M atenda aos critérios definidos, o valor 1 deverá ser retornado pela função; caso contrário, 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 3
#define C 4

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
            printf("%i ", m[i][j]);
        }
    }
}
int confereMatrizCrescente(int lin, int col, int m[lin][col])
{
    int i, j;
    for(i=0;i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            //conferindo se e o primeiro numero
            if(i-1!=-1&&j-1!=-1)
            {
                //nao sendo primeiro numero, conferindo se e o primeiro da linha
                if(j-1==-1)
                {
                    //se for o primeiro da linha, compara com o ultimo da ultima linha
                    if(m[i][j]<=m[i-1][col-1])
                    {
                        return 0;
                    }
                }
                else
                {
                    //nao sendo o primeiro da linha, compara com o anterior da linha
                    if(m[i][j]<=m[i][j-1])
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int main()
{
    int mat1[L][C], mat2[L][C]={{1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12}},cresc;
    //preenchendo 'mat1'
    geraMatrizAleatoria(L, C, mat1, 10);
    //exibindo 'mat1' e 'mat2'
    printf("\nMat1:\n");
    exibeMatriz(L, C, mat1);
    printf("\nMat2:\n");
    exibeMatriz(L, C, mat2);
    //conferindo se cada matriz e crescente
    cresc=confereMatrizCrescente(L, C, mat1);
    if(cresc!=0)
    {
        printf("\nMat1 e crescente!\n");
    }
    else
    {
        printf("\nMat1 NAO e crescente!\n");
    }
    cresc=confereMatrizCrescente(L, C, mat2);
    if(cresc!=0)
    {
        printf("\nMat2 e crescente!\n");
    }
    else
    {
        printf("\nMat2 NAO e crescente!\n");
    }
    return 0;
}