/*Bubblesort é a forma de organização de um vetor mais simples. Consiste em organizar os valores do vetor de forma crescente, 2 a 2, até que todo o vetor esteja organizado*/
#include <stdio.h>

void bubblesort(int tamanho, int vet[tamanho])
{
  int i, j, mudanças, passa;
  for(i=tamanho-1;i>0;i--)
  {
    for(j=0;j<i;j++)
    {
      if(vet[j]>vet[j+1])
      {
        passa=vet[j];
        vet[j]=vet[j+1];
        vet[j+1]=passa;
        mudanças++;
      }
    }
  }
}
