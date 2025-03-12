#include <stdio.h>
//bibliotecas para srand
#include <stdlib.h>
#include <time.h>

void preencheMatrizAleatorio(int lin, int col, int m[lin][col],int limite)
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
void preencheVetor(int lin, int col, int m[lin][col],int v[col])
{
    int soma=0, l, c;
    for(c=0;c<col;c++)
    {
        for(l=0;l<lin;l++)
        {
            soma+=m[l][c];
        }
        v[c]=soma;
        soma=0;
    }
}
void exibeVetor(int tam, int v[tam])
{
    printf("Vetor: ");
    for(int cont=0;cont<tam;cont++)
    {
        printf("%i, ",v[cont]);
    }
}
int main()
{
    int mValores[5][7], vSomas[7];
    //preenchendo a matriz e o vetor
    preencheMatrizAleatorio(5,7,mValores,10);
    preencheVetor(5,7,mValores,vSomas);
    //exibindo ambos
    exibeMatriz(5,7,mValores);
    exibeVetor(7,vSomas);
    return 0;
}