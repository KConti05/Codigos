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
//funcao para calculo de IGC faixa:
int calculaIgcFaixa(float igc)//recebe igc e retorna sua faixa
{
  if(igc<0.945)
  {
    return 1;
  }
  else if(igc<1.945)
  {
    return 2;
  }
  else if(igc<2.945)
  {
    return 3;
  }
  else if(igc<3.945)
  {
    return 4;
  }
  else
  {
    return 5;
  }
}
//funcao para calculo de CPC faixa e qualidades:
void calculaCpcFaixaQualid(float *vCpc, int *mFaixa) //preenche a matriz vFaixa rodando o de vCpcs e determinando a faixa de cada curso junto da qualidade(0-insatisfatorio,1-satisfatorio)
{
  int i;
  //preenchendo vFaixa:
  for(i=0;i<strlen(vCpc);i++)
  {
    if(vCpc[i]<0.945)
    {
      vFaixa[i][0]=1;
      vFaixa[i][1]=0; //insatisfatorio
    }
    else if(vCpc[i]<1.945)
    {
      vFaixa[i][0]=2;
      vFaixa[i][1]=0; //insatisfatorio
    }
    else if(vCpc[i]<2.945)
    {
      vFaixa[i][0]=3;
      vFaixa[i][1]=1; //satisfatorio
    }
    else if(vCpc[i]<3.945)
    {
      vFaixa[i][0]=4;
      vFaixa[i][1]=1; //satisfatorio
    }
    else
    {
      vFaixa[i][0]=5;
      vFaixa[i][1]=1; //satisfatorio
    }
  }   
}
//funcao para exibir todos os cursos
void exibeCursos(float igcCont, int igcFaixa, Tinsumo *vCurso, float *vCpc, int *mFaixa,) //recebe os Cursos, os Cpcs dos cursos, o Igc(continuo e faixa) e a matriz com as faixas e qualidades dos cursos para exibi-los de forma organizada
{
  int i, faixas;
  printf("\nCURSOS POR FAIXA DE QUALIDADE:\n");
  //exibindo cursos por faixa
  for(faixas=1;faixas<6;faixas++)
  {
    printf("\nFaixa de Qualidade: %i\n",faixas);
    //Procurando faixa em mFaixa:
    for(i=0;i<strlen(vCpc);i++)
    {
      //testando se a faixa e a requerida:
      if(mFaixa[i][1]==faixas)
      {
        //exibindo o curso a depender da qualidade:
        if(faixa<3) //insatisfatorio
        {
          printf("\nCodigo do Curso: %i;\nCPC Continuo: %.3f;\nCPC Faixa: %i;\nQualidade: INSATISFATORIO!\n",vCurso[i].codCurso,vCpc[i],mFaixa[i][0]);
        }
        else //satisfatorio
        {
          printf("\nCodigo do Curso: %i;\nCPC Continuo: %.3f;\nCPC Faixa: %i;\nQualidade: Satisfatorio!\n",vCurso[i].codCurso,vCpc[i],mFaixa[i][0]);
        }
      }
    }
  }
  printf("\n\nIGC continuo dos Cursos: %.3f\nFaixa do IGC: %i\n",igcCont,igcFaixa);
}
int main()
{
  //variaveis:
  int igcFaixa, mFaixa[30][2]; //mFaixa armazena na coluna 0 o valor da Faixa e na coluna 1 a qualidades(0-insatisfatorio, 1-satisfatorio)
  float igcCont, vCpc[30];
  char nomeArq[30];
  TInsumo vCursos[30];
  return 0;
}
