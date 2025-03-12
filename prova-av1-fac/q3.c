#include <stdio.h>

int main()
{
  int alunos,jaFiz=0;
  float valorDoado,maiorValor=0,valorMedio,valorTotal=0;
  printf("Quantos alunos? ");scanf("%i",&alunos);
  while(alunos>jaFiz)
  {
    jaFiz++;
    printf("\n===============ALUNO %i===============\n",jaFiz);
    printf("Qual o valor doado? ");scanf("%f",&valorDoado);
    if(valorDoado>maiorValor)
    {
      maiorValor=valorDoado;
    }
    valorTotal=valorTotal+valorDoado;
  }
  valorMedio=valorTotal/alunos;
  printf("\nMaior valor doado: R$%.2f\nMédia de Doações: R$%.2f\nTotal Arrecadado: R$.2f",maiorValor,valorMedio,valorTotal);//esqueci da % no ultimo .2f
  return 0 //a porra do ultimo ;
}