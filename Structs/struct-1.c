#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct
{
  int anoModelo;
  int anoFabricacao;
} TAnoModeloFabricacao;
typedef struct
{
  int placa; //considera-se um codigo numerico de 7 digitos
  int modelo; //considera-se um codigo numerico
  int marca; //considera-se um codigo numerico
  float quilometragem;
  TAnoModeloFabricacao ano;
  float valor;
  char tipo;
} TCarros;

//gera um inteiro aleatório.
int gerNumAleat(int limInf, int limSup)
{
  int dif=(limSup-limInf)+1;
  return rand()%dif+limInf;
}
//Zera uma variável do tipo TCarros.
void zeraTCarros(TCarros var)
{
   var.placa=0;
   var.modelo=0;
   var.marca=0;
   var.quilometragem=0;
   var.ano.anoModelo=0;
   var.ano.anoFabricacao=0;
   var.valor=0;
   var.tipo=0;
}
//printa um vetor do tipo TCarros.
void printTCarros(TCarros vetor[10])
{
   int i;
   for(i=0;i<10;i++)
   {
       printf("\n\nPlaca: %i\nModelo: %i\nMarca: %i\nAno do Modelo/De Fabricacao: %i/%i\nTipo: %c\nValor: R$ %.2f\n",vetor[i].placa,vetor[i].modelo,vetor[i].marca,vetor[i].ano.anoModelo,vetor[i].ano.anoFabricacao,vetor[i].tipo,vetor[i].valor);
   }
}
//busca carros de determinado modelo fabricados entre ano1 e ano2(inclusive) com valor de até x.
void buscaCarros(int modelo, int ano1, int ano2, float valor, TCarros vetor[10])
{
   int i;
   for(i=0;i<10;i++)
   {
       if((vetor[i].modelo==modelo)&&(((vetor[i].ano.anoModelo>=ano1)||(vetor[i].ano.anoModelo<=ano2))&&vetor[i].valor<=valor))
       {
           printf("\n\nModelo: %i\nMarca: %i\nAno do Modelo/De Fabricacao: %i/%i\nTipo: %c\nValor: R$ %.2f\n",vetor[i].modelo,vetor[i].marca,vetor[i].ano.anoModelo,vetor[i].ano.anoFabricacao,vetor[i].tipo,vetor[i].valor);
       }
   }
}
//reajusta o preço de todos os carros 0km em um aumento de p%.
void reajusta0KM(float p,TCarros vetor[10])
{
   int i;
   for(i=0;i<10;i++)
   {
       if(!vetor[i].tipo)
       {
           vetor[i].valor*=(100+p)/100;
       }
   }
}
//retira carro do estoque que possui a placa recebida.
void retiraPorPlaca(int placa, TCarros vetor[10])
{
   int i;
   for(i=0;i<10;i++)
   {
       if(vetor[i].placa==placa)
       {
           zeraTCarros(vetor[i]);
       }
   }
}
int main()
{
  TCarros carros[10];
  int i,buscaAno1,buscaAno2,buscaPreco,buscaModelo,removePlaca,aumentoPorcentagem;
  //preenchendo o vetor:
  for(i=0;i<10;i++)
  {
      carros[i].placa=gerNumAleat(1000000,9999999);
      carros[i].modelo=gerNumAleat(1,3); //modelo de carro entre 1 e 3
      carros[i].marca=gerNumAleat(1,6); //marca entre 1 e 6
      carros[i].quilometragem=gerNumAleat(0,1);
      carros[i].ano.anoFabricacao=gerNumAleat(2000,2024);
      carros[i].ano.anoModelo=gerNumAleat(2001,2025);
      carros[i].valor=gerNumAleat(10000,45000);
      if(carros[i].quilometragem)
      {
          carros[i].tipo='u';
      }
      else
      {
          carros[i].tipo=0;
      }
  }
  printf("\nCatalogo de carros:\n");
  printTCarros(carros);
  printf("\nPorcentagem de aumento dos carros 0:\n");scanf("%i",&aumentoPorcentagem);
  reajusta0KM(aumentoPorcentagem,carros);
  printf("\nCatalogo de carros atualizado:\n");
  printTCarros(carros);
  printf("\nLimite de valor procurado: \n");scanf("%i",&buscaPreco);
  printf("\nAno1 buscado(mais antigo):\n");scanf("%i",&buscaAno1);
  printf("\nAno2 buscado(mais novo):\n");scanf("%i",&buscaAno2);
  printf("\nModelo de preferencia(1,2 ou 3):\n");scanf("%i",&buscaModelo);
  buscaCarros(buscaModelo,buscaAno1,buscaAno2,buscaPreco,carros);
  printf("\nVeiculo(placa) a ser comprado:\n");scanf("%i",&removePlaca);
  retiraPorPlaca(removePlaca,carros);
  printf("\nCatalogo de carros atualizado:\n");
  printTCarros(carros);
  return 0;
}
