#include <stdio.h>
//bibliotecas para comando srand
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
int confereMatrizSimetrica(int lin,int col, int m[lin][col])
{
    int l,c;
    int mt[col][lin]; //matriz para teste
    for(l=0;l<lin;l++)
    {
        for(c=0;c<col;c++)
        {
            mt[c][l]=m[l][c];
            if(m[l][c]!=mt[c][l])
            {
                return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int m[4][5],simetria;
    preencheMatrizAleatorio(4,5,m,1);
    exibeMatriz(4,5,m);
    simetria=confereMatrizSimetrica(4,5,m);
    if(simetria==1)
    {
        printf("A Matiz e simetrica!");
    }
    else
    {
        printf("A Matiz NAO e simetrica!");
    }
    return 0;
}