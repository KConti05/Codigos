#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

//fucao para transcrever o arquivo em um vetor do tipo TInsumo
int transcreveArquivo(char *nomeArq, TInsumo *vCurso) //recebe o arquivo e o vetor, confere se arquivo abre e, abrindo, transcreve para o vetor, por fim retorna se operacao foi feita.
{
  int i, j, k, inic=0; //i usado para preencher vCurso, j usado para rodar sApoio e k usado para preencher sTranscreve. inic usado para marcar onde sApoio parou de ser lido 
  char sTranscreve[50], sApoio[10]; //sTrasncreve usado para receber cada linha do arquivo e sApoio ajuda na conversao de cada informacao para tipo int ou float
  FILE* arq;
  //abrindo arquivo:
  arq=fopen(nomeArq, "r");
  //testando se foi aberto:
  if(arq==NULL)
  {
    return 0;
  }
  /*Para transcrever considerei o padrao:
   - todo codigo de curso tem 4 digitos
   - toda nota tem 4 digitos(inteiro entre 0 e 9, "." de separacao e 2 casas decimais)*/
  //transcrevendo:
  for(i=0;fscanf(arq,"%s",sTranscreve)!=EOF;i++) //roda vCurso enquanto o arquivo nao terminar, preenchendo
  {
    //lendo sTranscreve:
    for(j=0;j<strlen(sTranscreve);j++)
    {
      if(sTranscreve[j]=="|") //sempre que encontrar um "|", preenche a informacao em sApoio e passa para vCurso, entao marcando onde parou em inic
      {
        for(k=inic;k<j;k++)
        {
          sTranscreve[k]=sApoio[k];
        }
        switch(inic)
        {
          case 0: vCurso[i].codCurso=atoi(sApoio);
                  break;
          case 6: vCurso[i].notaEnade=atof(sApoio);
                  break;
          case 11: vCurso[i].notaIdd=atof(sApoio);
                  break;
          case 16: vCurso[i].doutores=atof(sApoio);
                  break;
          case 21: vCurso[i].mestres=atof(sApoio);
                  break;
          case 26: vCurso[i].regmTrabalho=atof(sApoio);
                  break;
          case 31: vCurso[i].orgPedag=atof(sApoio);
                  break;
          case 36: vCurso[i].infraestrutura=atof(sApoio);
                  break;
          case 41: vCurso[i].amplAcademica=atof(sApoio);
                  break;
          case 46: vCurso[i].nAlunos=atoi(sApoio);
        }
        inic=j+1;
      }
    }
  }
  //fechando arquivo
  fclose(arq);
  //sinalizando realizacao da operacao:
  return 1;
}
//funcao para calculo de CPC continuo:
void calculaCpcCont(TInsumo *vCurso, float *vCpc) //recebe o vetor de cursos lidos e um vetor para armazenar os CPCs dos cursos
{
  int i;
  for(i=0;i<30;i++) //roda o vetor cursos e armazena no vetor cpc o cpc do curso com indice(i) equivalente
    {
      vCpc[i]=((vCurso[i].notaEnade*20.0)+(vCurso[i].notaIdd*35.0)+(vCurso[i].doutores*15.0)+(vCurso[i].mestres*7.5)+(vCurso[i].regmTrabalho*7.5)+(vCurso[i].orgPedag*7.5)+(vCurso[i].infraestrutura*5.0)+(vCurso[i].amplAcademica*2.5))/100.0;
    }
}
//funcao para calculo de IGC continuo:
float calculaIgcCont(TInsumo *vCurso, float *vCpc) //recebe os vetores vCurso e vCpc e retorna o valor do igc
{
   int i, totAlun=0; //totAlun sera usado no calculo da medio do igc
   float igc=0;
   for(i=0;i<30;i++) //roda os vetores progressivamente calculando igc e totAlun
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
void calculaCpcFaixaQualid(float *vCpc, int mFaixa[][2]) //preenche a matriz vFaixa rodando o de vCpcs e determinando a faixa de cada curso junto da qualidade(0-insatisfatorio,1-satisfatorio)
{
  int i;
  //preenchendo vFaixa:
  for(i=0;i<30;i++)
  {
    if(vCpc[i]<0.945)
    {
      mFaixa[i][0]=1;
      mFaixa[i][1]=0; //insatisfatorio
    }
    else if(vCpc[i]<1.945)
    {
      mFaixa[i][0]=2;
      mFaixa[i][1]=0; //insatisfatorio
    }
    else if(vCpc[i]<2.945)
    {
      mFaixa[i][0]=3;
      mFaixa[i][1]=1; //satisfatorio
    }
    else if(vCpc[i]<3.945)
    {
      mFaixa[i][0]=4;
      mFaixa[i][1]=1; //satisfatorio
    }
    else
    {
      mFaixa[i][0]=5;
      mFaixa[i][1]=1; //satisfatorio
    }
  }   
}
//funcao para exibir todos os cursos
void exibeCursos(float igcCont, int igcFaixa, TInsumo *vCurso, float *vCpc, int mFaixa[][2]) //recebe os Cursos, os Cpcs dos cursos, o Igc(continuo e faixa) e a matriz com as faixas e qualidades dos cursos para exibi-los de forma organizada
{
  int i, faixas;
  printf("\nCURSOS POR FAIXA DE QUALIDADE:\n");
  //exibindo cursos por faixa
  for(faixas=1;faixas<6;faixas++)
  {
    printf("\nFaixa de Qualidade: %i\n",faixas);
    //Procurando faixa em mFaixa:
    for(i=0;i<30;i++)
    {
      //testando se a faixa e a requerida:
      if(mFaixa[i][1]==faixas)
      {
        //exibindo o curso a depender da qualidade:
        if(faixas<3) //insatisfatorio
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
//funcao para adicionar novos cursos:
int adicionaCursos(char *nomeArq)
{
  char sContinua[3]="sim", sEscreve[10];
  FILE *arq;
  //abrindo arquivo:
  arq=fopen(nomeArq, "w");
  //testando se foi aberto:
  if(arq==NULL)
  {
    return 0;
  }
  //adicionando cursos:
  while(strncmp(sContinua,"sim",3)==0)
  {
    printf("\n\nCodigo do Curso(4 digitos):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nNota do Enade(2 casas decimais, exceto 10. Se 10, 1 casa decimal):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nIDD:(2 casas decimais, exceto 10. Se 10, 1 casa decimal):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nNota Doutores(2 casas decimais, exceto 10. Se 10, 1 casa decimal):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nNota Mestres(2 casas decimais, exceto 10. Se 10, 1 casa decimal):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nNota Regime de Trabalho(2 casas decimais, exceto 10. Se 10, 1 casa decimal):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nNota Organizacao Didatico-Pedagogica(2 casas decimais, exceto 10. Se 10, 1 casa decimal):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nNota Infraestrutura(2 casas decimais, exceto 10. Se 10, 1 casa decimal):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nNota Oportunidade de Ampliacao Academica e Profissional(2 casas decimais, exceto 10. Se 10, 1 casa decimal):\n");scanf("%s",sEscreve);
    fprintf(arq,"%s|",sEscreve);
    printf("\nQuantidade de Alunos:\n");scanf("%s",sEscreve);
    fprintf(arq,"%s",sEscreve);
    printf("\n\nDeseja adicionar mais cursos?\n");scanf("%s",sContinua);
  }
  //fechando arquivo:
  fclose(arq);
  //retornando operacao feita:
  return 1;
}

int main()
{
  //variaveis:
  int igcFaixa, anotCursos, mFaixa[30][2]; //mFaixa armazena na coluna 0 o valor da Faixa e na coluna 1 a qualidades(0-insatisfatorio, 1-satisfatorio), anotCursos recebera se o arquivo foi transcrito
  float igcCont, vCpc[30];
  char sNomeArq[30], sUso[15];
  TInsumo vCursos[30];
  //recebendo nome do arquivo:
  printf("\nNome do Arquivo:\n");scanf("%s",sNomeArq);
  //perguntando uso do arquivo:
  while(strncmp(sUso,"fim",15)!=0)
  {
    printf("\nQual o uso do arquivo?(digite 'adicionar' para adicionar novos cursos, 'exibir' para exibir cursos e 'fim' para encerrar)\n");scanf("%s",sUso); 
    if(strncmp(sUso,"exibir",15)==0)
    {
      //transcrevendo arquivo para o vetor
      anotCursos=transcreveArquivo(sNomeArq, vCursos);
      //testando se arquivo foi aberto e executando
      if(anotCursos)
      {
        //realizando calculos:
        calculaCpcCont(vCursos, vCpc);
        calculaCpcFaixaQualid(vCpc, mFaixa);
        igcCont=calculaIgcCont(vCursos,vCpc);
        igcFaixa=calculaIgcFaixa(igcCont);
        //exibindo
        exibeCursos(igcCont,igcFaixa,vCursos,vCpc,mFaixa);
      }
      else
      {
        printf("\nArquivo nao pode ser aberto!\n");
        return 0;
      }
    }
    else if(strncmp(sUso,"adicionar",15)==0)
    {
      //preenchendo arquivo
      anotCursos=adicionaCursos(sNomeArq);
      if(!anotCursos)
      {
        printf("\nArquivo nao pode ser aberto!\n");
        return 0;
      }
    }
  }
  return 0;
}
