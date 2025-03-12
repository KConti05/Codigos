#include <stdio.h>

int main()
{
    int codigo,jaFiz=1,qtdSaque=0;
    float saldo,cheque,saque,deposito,maiorPag=0,totalsacado=0,medSaques;
    printf("Saldo inical: ");scanf("%f",&saldo);
    printf("\n=========================OPERACAO %i=========================\n",jaFiz);
    printf("Codigo(0-encerra,4-Pagamento de Cheque,10-Saque,33-Deposito): ");scanf("%i",&codigo);
    while(codigo!=0)
    {
        if(codigo==4)
        {
            printf("Valor do Cheque: ");scanf("%f",&cheque);
            saldo=saldo-cheque;
            if(cheque>maiorPag)
            {
                maiorPag=cheque;
            }
        }
        else if(codigo==10)
        {
            printf("Valor Sacado: ");scanf("%f",&saque);
            saldo=saldo-saque;
            totalsacado=totalsacado+saque;
            qtdSaque++;
        }
        else if(codigo==33)
        {
            printf("Valor do Deposito: ");scanf("%f",&deposito);
            saldo=saldo+deposito;
        }
        if(saldo<0)
        {
            printf("\nCuidado! Saldo Negativo!");
        }
        jaFiz++;
         printf("\n=========================OPERACAO %i=========================\n",jaFiz);
        printf("Codigo(0-encerra,4-Pagamento de Cheque,10-Saque,33-Deposito): ");scanf("%i",&codigo);
    }
    printf("\nSaldo final: R$%.2f",saldo);
    if(qtdSaque==0)
    {
        printf("\nNao houve saques.");
    }
    else
    {
        medSaques=totalsacado/qtdSaque;
        printf("\nMedia de Saques: R$ %.2f",medSaques);
    }
    if(maiorPag==0)
    {
        printf("\nNao houve pagamentos de cheque.");
    }
    else
    {
        printf("\nMaior Pagamento: R$%.2f",maiorPag);
    }
    return 0;
}