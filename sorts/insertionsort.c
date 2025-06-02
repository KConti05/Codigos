/*É um método de ordenação que organiza os elementos de um vetor de forma crescente comparando os elementos, 2 a 2, e sempre que uma troca for feita também compara com o elemento anterior
até que todo o vetor esteja organizado.*/
#include <stdio.h>

void insertionSort(int tamanho, int vet[tamanho])
{
  int i, j, passa;
  for(i=0;i<tamanho-1;i++)
  {
    if(vet[i]>vet[i+1])
    {
      passa=vet[i+1];
      vet[i+1]=vet[i];
      vet[i]=passa;
      for(j=i-1;j>=0;j--)
      {
        if(passa<vet[j])
        {
          vet[j+1]=vet[j];
          vet[j]=passa;
        }
      }
    }
  }
}
