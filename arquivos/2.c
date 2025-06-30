/*Desenvolver uma função que, dado um arquivo
texto, verifique o número de vezes que um
determinado caracter aparece no arquivo.*/

#include <stdio.h>

int procuraCarac(char *nomeArq, char carac)
{
  //varaiveis:
  FILE* arq;
  int cont=0;
  char conf; //usado para conferir se o arquivo acabou
  //abrindo arquivo:
  arq=fopen(nomeArq,"r");
  //verificando abertura:
  if(!arq)
  {
    return -1;
  }
  while(fscanf(arq,"%c",conf)!=EOF) //EOF significa end of file
  {
    if(conf==carac)
    {
      cont++;
    }
  }
  //fechando arquivo:
  fclose(arq);
  //retornando quantidade:
  return cont;
}
int main()
{
  //variaveis:
  char nomeArq[50];
  char carac;
  int resp;
  //recebendo nomeArq:
  printf("\nNome do Arquivo:\n");scanf("%s",nomeArq);
  //limpando buffer:
  fflush(stdin);
  //recebendo caractere buscado:
  printf("\nCaractere procurado:\n");scanf("%c",carac);
  //chamando a funcao:
  resp=procuraCarac(nomeArq,carac);
  //apresentando resposta:
  switch(resp)
  {
    case -1: printf("\nErro na abertura de %s",nomeArq);
             break;
    case 0: printf("\nArquivo %s nao possui %c.",nomeArq,carac);
            break;
    default: printf("\nO Arquivo %s possui %i caracteres %c.",nomeArq,resp,carac);
  }
  return 0;
}
