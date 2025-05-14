/*Suponha a existência de um vetor de tamanho
TAM, cada posição armazenando o nome da
pessoa e a sua data de aniversário
(representada por um struct do tipo TData,
contendo os campos dia e mes). Pede-se o
desenvolvimento das seguintes funções:
 Determinar a quantidade de pessoas que
fazem aniversário no mês M;
 Exibir os nomes de todas pessoas que fazem
aniversário entre as datas d1 e d2, ambas
do tipo TData.*/

#include <stdio.h>
#define TAM 5
typedef struct
{
  int dia;
  int mes;
} TData;
typedef struct
{
  char nome[30];
  TData aniversario;
} TPessoa;

int pessoasEmMes(int tamanho,TPessoa vetor[tamanho],int mes)
{
  int i,qtdPessoas=0;
  for(i=0;i<tamanho;i++)
  {
    if(string[i].aniversario.mes==mes)
    {
      qtdPessoas++;
    }
  }
  return qtdPessoas;
}
void nomesEntreDatas(int tamanho, TPessoas vetor[tamanho],  
int main()
{
  int i;  
  TPessoa vPessoas[TAM];
  for(i=0;i<TAM;i++)
  {
    printf("\nNome:\n");fgets(vPessoas[i].nome,TAM,stdin);
    printf("\nDia do Aniversario:\n");scanf("%i",vPessoas[i].aniversario.dia);
    printf("\nMes do Aniversario:\n");scanf("%i",vPessias[i].aniversario.mes);
  }
  printf("\n\nLista de Pessoas:\n");
  for(i=0;i<TAM;i++)
  {
    printf("\nPessoa %i:\n",i+1);
    printf("Nome: %s\n",vPessoas[i].nome);
    printf("Data de ANiversario: %i/%i\n",vPessoas[i].aniversario.dia,vPessoas[i].aniversario.mes);
  }
}
