/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de caracteres no
mesmo.*/

#include <stdio.h>
#include <stdlib.h>

int contCarac(char *nomeArq)
{
  //variaveis:
  FILE *arq;
  int cont=0;
  char conf; //para conferir se ainda ha caracteres
  //abrindo arquivo:
  arq=fopen(nomeArq,"r");
  //verificando abertura:
  if(!arq)
  {
    return -1; //retorno -1 para sinalizar erro na abertura.
  }
  while(fscanf(arq,"%c",&conf)!=EOF) //EOF significa end of file
  {
    cont++;
  }
  //fechando arquivo:
  fclose(arq);
  //retornando quantidade de caracteres
  return cont;
}

int main()
{
  //variaveis:
  char nomeArq[50];
  int resp;
  //recebendo nomeArq:
  printf("\nNome do Arquivo:\n");scanf("%s",nomeArq);
  //chamando a funcao:
  resp=contCarac(nomeArq);
  //apresentando resposta:
  switch(resp)
  {
    case -1: printf("\nErro na abertura de %s",nomeArq);
             break;
    case 0: printf("\nArquivo %s esta vazio.",nomeArq);
            break;
    default: printf("\nO Arquivo %s possui %i caracteres.",nomeArq,resp);
  }
  return 0;
}
