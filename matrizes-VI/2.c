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
//funcao, questao 2 lista de matrizes V modificada:
int trocaColunas(int lin, int col, int m[lin][col], int col1, int col2)
{
    //o vetor 'vPassa' sera usado para auxiliar a passagem dos elementos de uma coluna a outra.
    int i, vPassa[lin];
    //conferindo se a troca pode ser feita
    if((col1>0&&col1<col)&&(col2>0&&col2<col)&&(col1!=col2))
    {
        zeraVetor(lin,vPassa);
        //armazenando elementos de col1 no 'vPassa'
        for(i=0;i<lin;i++)
        {
            vPassa[i]=m[i][col1];
        }
        //realizando as trocas
        for(i=0;i<lin;i++)
        {
            m[lin-i-1][col1]=m[i][col2];
            m[i][col2]=vPassa[i];
        }
        //avisando que as trocas foram feitas
        return 1;
    }
    //avisando caso a troca nao pôde ser feita
    return 0;
}
