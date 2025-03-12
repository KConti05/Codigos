//Kauã Contiero Duarte de Oliveira
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerNumAleat(int limInf, int limSup)
{
    int dif=(limSup-limInf)+1;
    return rand()%dif+limInf;
}
int main()
{
    int questoes,resposta,matricula=0,concorda=0,discorda=0,gPro=0,gContra=0,gNeutro=0,jaFizA=0,jaFizQ=0;float defGrupo;
    srand(time(NULL));
    printf("Serao quantas questoes? ");scanf("%i",&questoes);
    defGrupo=2*questoes/3;
    while(matricula>=0)
    { 
        jaFizA++;
        printf("\n====================Aluno %i====================\n",jaFizA);
        printf("Qual a matricula do aluno? ");scanf("%i",&matricula);   
        while(jaFizQ<questoes)
        {
            jaFizQ++;
            printf("\n====================Questao %i====================\n",jaFizQ);
            resposta=gerNumAleat(1,2);
            if(resposta==1)
            {
                printf("Concorda.");
                concorda++;
            }
            else if(resposta==2)
            {
                printf("Discorda.");
                discorda++;
            }
        }
        jaFizQ=0;
        if(concorda>=defGrupo)
        {
            printf("\nGrupo Pro");
            gPro++;
        }
        else if(discorda>=defGrupo)
        {
            printf("\nGrupo Contra");
            gContra++;
        }
        else
        {
            printf("\nGrupo Neutro");
            gNeutro++;
        }
        concorda=0;
        discorda=0;
    }
    if(gPro>gContra&&gPro>gNeutro)
    {
        printf("\nO Grupo Pro teve mais integrantes, tendo %i alunos.",gPro); 
    }
    else if(gContra>gPro&&gContra>gNeutro)
    {
        printf("\nO Grupo Contra teve mais integrantes, tendo %i alunos.",gContra);
    }
    else
    {
        printf("\nO Grupo Neutro teve mais integrantes, tendo %i alunos.",gNeutro);
    }   
    return 0;
}