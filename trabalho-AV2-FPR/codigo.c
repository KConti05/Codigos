#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
//criação da variavel TInsumo
typedef struct
{
  int codCurso;
  float notaEnade;
  float notaIdd;
  float doutores;
  float mestres;
  float regmTrabalho;
  float orgPedag;
  float infraestrutura;
  float amplAcademica;
  int nAlunos;
} TInsumo;

//funcao para calculo de CPC continuo:
void calculaCpcCont(TInsumo *vCurso, float *vCpc) //recebe o vetor de cursos lidos e um vetor para armazenar os CPCs dos cursos
{
  int i;
  for(i=0;i<strlen(vCurso);i++) //roda o vetor cursos e armazena no vetor cpc o cpc do curso com indice(i) equivalente
    {
      vCpc[i]=((vCurso[i].notaEnade*20.0)+(vCurso[i].notaIdd*35.0)+(vCurso[i].doutores*15.0)+(vCurso[i].mestres*7.5)+(vCurso[i].regmTrabalho*7.5)+(vCurso[i].orgPedag*7.5)+(vCurso[i].infraestrutura*5.0)+(vCurso[i].amplAcademica*2.5))/100.0;
    }
}
//funcao para calculo de IGC continuo:
float calculaIgcCont(TInsumo *vCurso, float *vCpc) //recebe os vetores vCurso e vCpc e retorna o valor do igc
{
   int i, totAlun=0; //totAlun sera usado no calculo da medio do igc
   float igc=0;
   for(i=0;i<strlen(vCurso);i++) //roda os vetores progressivamente calculando igc e totAlun
   {
      igc+=vCpc[i]*vCurso[i].nAlunos;
      totAlun+=vCurso[i].nAlunos;
   }
   return igc/totAlun;
}
//funcao para calculo de CPC e IGC faixa:
int calculaFaixa()
{
}
