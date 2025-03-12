#include <stdio.h>

float calculaValor(int numUnid,float precoUnid)
{
  float valorPago=numUnid*precoUnid;
  return valorPago;
}
int quantasPeloPrecoPromocional(int totalUnid,int unidNormal,int unidPromocao) //esqueci de definir o tipo das variáveis que ela recebe.
{
  int unidMetadePreco=totalUnid%(unidNormal+unidPromocao);
  return unidMetadePreco;
}
float calculaExibeValorCompraTotal(int numUnid,float precoUnid,int unidNormal,int unidPromocao)
{
  float valNormal,valPromocao,valTotal;
  int nNormal,nPromocao;
  nPromocao=quantasPeloPrecoPromocional(numUnid,unidNormal,unidPromocao);
  nNormal=numUnid-nPromocao;
  valNormal=calculaValor(nNormal,precoUnid);
  valPromocao=calculaValor(nPromocao,precoUnid/2.0);//esqueci de criar a variável do preço da Unidade
  valTotal=valNormal+valPromocao;
  return printf("\n%i unidades pelo preço normal, dando R$%.2f.\n%i unidades no preço promocional, dando R$%.2f\nValor total da compra: R$%.2f",nNormal,valNormal,nPromocao,valPromocao,valTotal);
}
int main()
{
  int numUnid,unidNormal,unidPromocao;
  float precoPorUnid,valorTotal;
  printf("Qual o total de unidades? ");scanf("%i",&numUnid);
  printf("Qual o preço por unidade? ");scanf("%f",&precoPorUnid);
  printf("Quantas unidades pelo preço normal? ");scanf("%i",&unidNormal);
  printf("Quantas unidades no preço da promoção? ");scanf("%i",&unidPromocao);
  valorTotal=calculaExibeValorCompraTotal(numUnid,precoPorUnid,unidNormal,unidPromocao);//escrevi unidPromocao errado.
  return 0;
}