#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Implementar uma função que, dadas uma matriz M de inteiros (com lin linhas e col colunas) e duas colunas c1 e c2, inverta a ordem (por linha) dos elementos compreendidos entre estas colunas. 
 */
 
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
void zeraVetor(int tam, int v[tam])
{
    int i;
    for(i=0;i<tam;i++)
    {
        v[i]=0;
    }
}
//funcao, questao 2 lista de matrizes V modificada:
void trocaEntreColunas(int lin, int col, int m[lin][col], int col1, int col2)
{
    //o vetor 'vPassa' sera usado para auxiliar a passagem dos elementos de uma coluna a outra.
    int i,vPassa[lin];
    //ajeitando colunas
    col1--;
    col2--;
    //realizando trocas
    for(;col1<col2;col1++,col2--)
    {
        zeraVetor(lin,vPassa);
        //armazenando elementos de 'col1' no 'vPassa'
        for(i=0;i<lin;i++)
        {
            vPassa[i]=m[i][col1];
        }
        //realizando as trocas
        for(i=0;i<lin;i++)
        {
            m[i][col1]=m[i][col2];
            m[i][col2]=vPassa[i];
        }
    }
}
int main()
{
    int mat[5][8], colunaInicial, colunaFinal;
    //preenchendo e exibindo matriz 'mat'
    geraMatrizAleatoria(5, 8, mat, 10);
    printf("\nMatriz base:\n");
    exibeMatriz(5, 8, mat);
    //recebendo colunas para trocas
    printf("\nColuna Inicial das trocas: ");scanf("%i",&colunaInicial);
    printf("\nColuna Final das trocas: ");scanf("%i",&colunaFinal);
    //realizando trocas
    trocaEntreColunas(5, 8, mat, colunaInicial, colunaFinal);
    //exibindo nova matriz
    printf("\nMatriz trocada:\n");
    exibeMatriz(5, 8, mat);
    return 0;
}
