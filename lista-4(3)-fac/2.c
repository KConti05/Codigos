#include <stdio.h>
#include <math.h>

int main()
{
    int dias, jaFiz=0;
    float senTermica,temp,vel; //temperatura e velocidade
    printf("Quantos dias serao analisados? ");scanf("%i",&dias);
    while(dias>jaFiz)
    {
        jaFiz++;
        printf("\n==================Dia %i==================\n",jaFiz);
        printf("Qual a temperatura(em graus Celsius)? ");scanf("%f",&temp);
        printf("Qual a velocidade do vento(em KM/H)? ");scanf("%f",&vel);
        senTermica=33+(10*sqrt(vel)+10.45-vel)*(temp-33)/22;
        printf("A sensacao termica do dia %i esta em torno de %.2fC!",jaFiz,senTermica);
    }
    return 0;
}