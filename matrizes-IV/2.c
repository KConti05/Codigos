#include <stdio.h>
//bibliotecas para comando srand:
#include <stdlib.h>
#include <time.h>

void exibeMatriz(int lin, int col, int m[lin][col])
{
    int l,c;
    for(l=0;l<lin;l++)
    {
        for(c=0;c<col;c++)
        {
            printf("%3d",m[l][c]);
        }
        printf("\n");
    }
}
void preencheMatrizAleatorio(int lin, int col, int m[lin][col], int limite)
{
    int l,c;
    srand(time(NULL));
    for(l=0;l<lin;l++)
    {
        for(c=0;c<col;c++)
        {
            m[l][c]=rand()%limite;
        }
    }
}
int encontraValorEmLinha(int lin, int col, int m[lin][col], int valor, int linha)
{
    int c;
    linha--; //adequando a linha procurada à linha na matriz
    for(c=0;c<col;c++)
    {
        if(m[linha][c]==valor)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int m[10][5],valor,linha,existe;
    preencheMatrizAleatorio(10,5,m,30);
    printf("Matriz: \n");
    exibeMatriz(10,5,m);
    //recebendo as informacoes do usuario
    printf("\nValor Buscado: ");scanf("%d",&valor);
    printf("\nLinha a ser verificada: ");scanf("%d",&linha);
    //procurando valor
    existe=encontraValorEmLinha(10,5,m,valor,linha);
    //exibindo resposta
    if(existe==1)
    {
        printf("\nValor procurado %i existe na linha %d!!",valor,linha);
    }
    else
    {
        printf("\nValor procurado %i NAO existe na linha %d!!",valor,linha);
    }
    return 0;
}