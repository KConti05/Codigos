#include <stdio.h>

int eHorarioComercial(int hora)
{
    if(hora>=8&&hora<=18)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int calculaMulta(int velocidade,int limVelocidade)
{
    int valMulta,hora;
    if(velocidade<=limVelocidade)
    {
        valMulta=0;
    }
    else if(velocidade<=(limVelocidade+10))
    {
        valMulta=50;
    }
    else if(velocidade<=(limVelocidade+30))
    {
        valMulta=100;
    }
    else
    {
        printf("Qual horario? ");scanf("%i",&hora);
        hora=eHorarioComercial(hora);
        if(hora==0)
        {
            valMulta=200;
        }
        else
        {
            valMulta=400+2*(velocidade-limVelocidade);
        }
    }
    return valMulta;
}
int main()
{
    int velMax,velMot,multa,jaFiz=1;
    printf("Qual a velocidade maxima na avenida? ");scanf("%i",&velMax);
    printf("\n=========MOTORISTA %i=========\n",jaFiz);
    printf("Velocidade do primerio motorista(<=0 para encerrar): ");scanf("%i",&velMot);
    while(velMot>0)
    {
        multa=calculaMulta(velMot,velMax);
        if(multa==0)
        {
            printf("Sem multa.");
        }
        else
        {
            printf("Multa de %i reais.",multa);
        }
        jaFiz++;
        printf("\n=========MOTORISTA %i=========\n",jaFiz);
        printf("Velocidade do proximo motorista(<=0 para encerrar): ");scanf("%i",&velMot);
    }
    return 0;
}