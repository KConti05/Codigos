/*É um método de ordenação que analisa o vetor como um todo passando os menores elementos, 1 a 1, para o início do vetor até que todo o vetor esteja ordenado*/
#include <stdio.h>

void selectionSort(int tamanho, int vet[tamanho])
{
  int i, j, menor, ind_Menor;
  for(i=0;i<tamanho-1;i++)
  {
    menor=vet[i];
    ind_Menor=i;
    for(j=i+1;j<tamanho;j++)
    {
      if(vet[j]<menor)
      {
        menor=vet[j];
        ind_Menor=j;
      }
    }
    if(ind_Menor!=i)
    {
      vet[ind_Menor]=vet[i];
      vet[i]=menor;
    }
  }
}
