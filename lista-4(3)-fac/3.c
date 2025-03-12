#include <stdio.h>

int main()
{
    int partidas,jaFiz=0,golTime1,golTime2;
    printf("Quantas rodadas? ");scanf("%i",&partidas);
    while(partidas>jaFiz)
    {
        jaFiz++;
        printf("\n==============RODADA %i==============\n",jaFiz);
        printf("Quantos gols o primeiro time fez? ");scanf("%i",&golTime1);
        printf("E quantos gols o segundo fez? ");scanf("%i",&golTime2);
        if(golTime1>golTime2)
        {
            printf("Time 1 venceu por %i a %i!",golTime1,golTime2);
        }
        else if(golTime2>golTime1)
        {
            printf("Time 2 venceu por %i a %i!",golTime2,golTime1);
        }
        else
        {
            if(golTime1==0)
            {
                printf("Nao houve gols! Empate.");
            }
            else
            {
                printf("Ambos fizeram %i gols, empate!",golTime1);
            }
        }
    }
    return 0;
}