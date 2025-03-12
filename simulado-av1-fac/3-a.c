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
    int questoes,resposta,jaFiz=0;
    srand(time(NULL));
    printf("Serao quantas questoes? ");scanf("%i",&questoes);
    while(jaFiz<questoes)
    {
        jaFiz++;
        printf("\n====================Questao %i====================\n",jaFiz);
        resposta=gerNumAleat(1,2);
        if(resposta==1)
        {
            printf("Concorda.");
        }
        else if(resposta==2)
        {
            printf("Discorda.");
        }
    }
    return 0;
}