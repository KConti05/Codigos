#include <stdio.h>

void exibeMatriz(int lin,int col, int m[lin][col])
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
void criaMatriz(int lin, int col, int m[lin][col])
{
    int l,c;
    for(l=0;l<lin;l++)
    {
        for(c=0;c<col;c++)
        {
            m[l][c]=l+c+1;
        }
    }
}
int main()
{
    int m[5][5];
    criaMatriz(5,5,m);
    exibeMatriz(5,5,m);
    return 0;
}