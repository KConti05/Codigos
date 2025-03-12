#include <stdio.h>
#include <math.h>

float recebeLado(int num)
{
    float lado;
    printf("\nQual o tamanho do lado %i: ",num);scanf("%f",&lado);
    while(lado<=0)
    {
        printf("\nValor invalido\nDigite um valor acima de 0: ");scanf("%f",&lado);
    }
    return lado;
}
float calculaDiagonal(float a,float b,float c)
{
    return sqrt(pow(a,2)+pow(b,2)+pow(c,2));
}
float decideTamanhoEsfera(float diagonal)
{
    if(diagonal<=10)
    {
        return 10;
    }
    else if(diagonal<=15)
    {
        return 15;
    }
    else if(diagonal<=20)
    {
        return 20;
    }
    else 
    {
        return 25;
    }
}
int main()
{
    int codigo,esf10=0,esf15=0,esf20=0,esf25=0,jaFiz=1;
    float lado1,lado2,lado3,diagonal,tamEsfera;
    printf("Produto %i\n",jaFiz);
    printf("Codigo do produto(negativo para encerrar): ");scanf("%i",&codigo);
    while(codigo>=0)
    {
        lado1=recebeLado(1);
        lado2=recebeLado(2);
        lado3=recebeLado(3);
        diagonal=calculaDiagonal(lado1,lado2,lado3);
        if(diagonal<=25)
        {
            tamEsfera=decideTamanhoEsfera(diagonal);
            printf("\nDiagonal da Embalagem: %.2f",tamEsfera);
        }
        else
        {
            printf("Brinquedo grande demais.");
        }
        if(tamEsfera==10)
        {
            esf10++;
        }
        else if(tamEsfera==15)
        {
            esf15++;
        }
        else if(tamEsfera==20)
        {
            esf20++;
        }
        else
        {
            esf25++;
        }
        jaFiz++;
        printf("\nProduto %i\n",jaFiz);
        printf("Codigo do produto(negativo para encerrar): ");scanf("%i",&codigo);
    }
    printf("\nEsferas de 10: %i\nEsferas de 15: %i\nEsferas de 20: %i\nEsferas de 25: %i",esf10,esf15,esf20,esf25);
    return 0;
}