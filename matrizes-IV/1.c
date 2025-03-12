#include <stdio.h>
//bibliotecas para usar a função srand
#include <stdlib.h>
#include <time.h>

void exibirMatriz (int lin, int col, int m[lin][col])
{
	int i, j;
	for (i=0;i<lin;i++)
	{
		for (j=0;j<col;j++)
		{
			printf ("%3d ", m[i][j]);
		}
		printf ("\n");
	}
}
void preencherMatrizAleatorio (int lin, int col, int m[lin][col], int limite)
{
	int i, j;
	srand(time(NULL));
	for (i=0;i<lin;i++)
	{
		for (j=0;j<col;j++)
		{
			m[i][j] = rand()%limite;
		}
	}	
}
void transposta(int lin, int col, int m[lin][col], int mt[col][lin])
{
    int l,c;
    for(l=0;l<lin;l++)
    {
        for(c=0;c<col;c++)
        {
            mt[c][l]=m[l][c];
        }
    }
}
int main()
{
    int m[8][5],mt[5][8];
    preencherMatrizAleatorio(8,5,m,40);
    exibirMatriz(8,5,m);
    transposta(8,5,m,mt);
    exibirMatriz(5,8,mt);
    return 0;
}