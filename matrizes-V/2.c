#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Dada uma matriz MLxC, onde L e C são constantes, desenvolver uma função que “troque” os elementos de duas colunas c1 e c2, respeitadas as seguintes regras:
a. A troca só será possível se as colunas c1 e c2 existirem na matriz. Caso existam, a troca será realizada e o valor 1 retornado pela função; por outro lado, 0 será retornado se uma ou as duas colunas forem inválidas;
b. Após a troca, a coluna c2 conterá exatamente os elementos originais da coluna c1, na mesma ordem. Porém, os valores da coluna c1 serão os originais da c2, na ordem inversa.
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
int main()
{
    const int L=8, C=5;
    int mat[L][C],trocou, coluna1, coluna2;
    //preenchendo a matriz
    geraMatrizAleatoria(L, C, mat, 10);
    //exibindo a matriz
    exibeMatriz(L, C, mat);
    //pedindo colunas a serem trocadas
    printf("\nQual a primeira coluna a ser trocada?\n");scanf("%i",&coluna1);
    printf("\nQual a segunda coluna a ser trocada?\n");scanf("%i",&coluna2);
    //realizando a troca e exibindo se conseguiu ser feita ou nao
    trocou=trocaColunas(L, C, mat, coluna1, coluna2);
    if(trocou!=0)
    {
        printf("\nA troca foi feita com sucesso!\n");
        exibeMatriz(L, C, mat);
    }
    else
    {
        printf("\nA troca nao pode ser feita, escolha colunas existentes na Matriz.\n");
    }
    return 0;
}