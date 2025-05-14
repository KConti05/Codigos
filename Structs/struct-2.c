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

int pessoasEmMes(int tamanho,TPessoa string[tamanho],int mes)
{
  
}
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
