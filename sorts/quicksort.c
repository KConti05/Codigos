/*É um método de ordenação que separa o vetor em pares de subvetores, um com os elementos menores que um 'compara', escolhido para rodar o vetor, e outro com os maiores que o 'compara', recursivamente até que o 
vetor esteja ordenado. 
Para isso usa-se uma função 'particiona' que divide o vetor e retorna o índice que marca a divisão e outra 'quickSort' que utiliza da particiona para dividir e organizar o vetor recursivamente.*/

#include <stdio.h>

int particiona(int *vet, int inicio, int fim)//para esta funcão é mais interessante usar inicio e fim do que o tamanho do vetor.
{
  int passa, compara=(vet[inicio]+vet[fim]+vet[(inicio+fim)/2])/3; //para o quicksort é interessante que o 'compara' seja uma media do vetor, para isso soma-se inicio, fim e meio e divide a soma por 3.
  while(inicio<fim)
  {
    //procurando um elemento maior que o 'compara', do inicio para o fim:
    while(inicio<fim && vet[inicio]<=compara)
    {
      inicio+=1;
    }
    //procurando um elemento menor que o 'compara', do fim para o inicio:
    while(inicio<fim && vet[fim]>=compara)
    {
      fim-=1;
    }
    //realizando a troca:
    passa=vet[inicio];
    vet[inicio]=vet[fim];
    vet[fim]=passa;
  }
}
void quickSort(int *vet, int inicio, int fim)
{
  if(inicio<fim) //caso base
  {
    int pos=particiona(vet, inicio, fim); //variavel que salva a posicao da divisoria do vetor.
    //Metade inferior a 'compara' de particiona
    quickSort(vet, inicio, pos-1);
    //metade superior a 'compara'
    quickSort(vet, pos, fim);
  }
}
