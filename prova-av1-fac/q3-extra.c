#include <stdio.h>

int main()
{
  int alunos,jaFizTurm=0,jaFizAlun=0;
  float valorDoado,maiorValor=0,valorMedio,valorTotalTurma=0,valorTotal=0;
  while(jaFizTurm<5)
  {
    jaFizTurm++;
    printf("\n===============TURMA %i===============\n",jaFizTurm);
    printf("Quantos alunos na turma? ");scanf("%i",&alunos);
    while(alunos>jaFizAlun)
    {
      jaFizAlun++;
      printf("\n===============ALUNO %i===============\n",jaFizAlun);
      printf("Qual o valor doado? ");scanf("%f",&valorDoado);
      if(valorDoado>maiorValor)
      {
        maiorValor=valorDoado;
      }
      valorTotalTurma=valorTotalTurma+valorDoado;
    }
    valorMedio=valorTotalTurma/alunos;
    printf("\nMaior valor doado: R$%.2f\nMédia de Doações: R$%.2f\nTotal Arrecadado: R$.2f",maiorValor,valorMedio,valorTotalTurma); //esqueci da ultima %
    valorTotal=valorTotal+valorTotalTurma;
    jaFizAlun=0;
    maiorValor=0;
    valorMedio=0;
    valorTotalTurma=0;
  }
  printf("\nValor arrecadado pelas 5 turmas: R$%.2f",valorTotal);
  return 0 //a porra do ultimo ;
}