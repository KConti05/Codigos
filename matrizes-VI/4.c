/*
Considere a existência de uma matriz M, contendo números reais, com x linhas e y colunas. Pede-se a implementação de uma função que, a partir de M, gere dois vetores, conforme descritos a seguir:
 - V1, com x posições, de forma que cada posição i do vetor armazene quantos elementos da linha i de M são múltiplos do primeiro valor desta linha (excluindo o próprio primeiro número);
 - V2, com y posições, de forma que cada posição i do vetor armazene quantos elementos da coluna i de M são múltiplos do primeiro valor desta coluna (excluindo o próprio primeiro número).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
//Por algum motivo, 20 linhas estava causando 'exceção de ponto flutuamte'
void geraVetor(int lin, int col, int m[lin][col], int vLinha[lin], int vColuna[col])
{
    //'contLinha' e 'contColuna' serao usados para contar a quantidade de multiplos
    int i, j, contLinha=0, contColuna=0;
    //preenchendo vLinha
    for(i=0;i<lin;i++,contLinha=0)
    {
        for(j=1;j<col;j++)
        {
            if(m[i][j]%m[i][0]==0)
            {
                contLinha++;
            }
        }
        //armazenando a quantidade de multiplos
        vLinha[i]=contLinha;
    }
    //preenchendo vColuna
    for(j=0;j<col;j++,contColuna=0)
    {
        for(i=1;i<lin;i++)
        {
            if(m[i][j]%m[0][j]==0)
            {
                contColuna++;
            }
        }
        //armazenando a quantidade de multiplos
        vColuna[j]=contColuna;
    }
}
void exibeVetor(int tam, int v[tam])
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%i ", v[i]);
    }
}
int main()
{
    int mat[10][10], vLinha[10], vColuna[10];
    //preenchendo e exibindo 'mat'
    geraMatrizAleatoria(10, 10, mat, 30);
    printf("\nMatriz:\n");
    exibeMatriz(10, 10, mat);
    //gerando vetores
    geraVetor(10, 10, mat, vLinha, vColuna);
    //exibindo vetores:
    printf("\nvLinha: ");
    exibeVetor(10, vLinha);
    printf("\nvColuna: ");
    exibeVetor(10, vColuna);
    return 0;
}
