#include <stdio.h>
#include <math.h>

float calculaFuncaoQuadratica(float a,float b,float c)
{
    float delta=pow(b,2)-4*a*c;
    if(delta<0)
    {
        return printf("Nao ha raizes reais!");
    }
    else
    {
        float x1=(-1*b+sqrt(delta))/2*a;
        float x2=(-1*b+sqrt(delta))/2*a;
        return printf("x1=%.2f\nx2=%.2f",x1,x2);
    }
}
int main()
{
    float coeficienteAngular,coeficienteLinear,termoIndependente;
    printf("Considerando uma função de segundo grau do tipo f(x)=ax2+bx+c.\nDiga um valor para a: ");scanf("%f",&coeficienteAngular);
    printf("Um valor para o b: ");scanf("%f",&coeficienteLinear);
    printf("E um valor para c: ");scanf("%f",&termoIndependente);
    calculaFuncaoQuadratica(coeficienteAngular,coeficienteLinear,termoIndependente);
    return 0;
}