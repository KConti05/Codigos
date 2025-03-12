//Kauã Contiero Duarte de Oliveira
#include <stdio.h>
#include <math.h>

float calculaAreaQuadrado(float l)
{
    float areaQuadrado=pow(l,2);
    return areaQuadrado;
}
float calculaAreaTriEquilatero(float l)
{
    float areaTriangulo=(pow(l,2)*sqrt(3.0))/4.0;
    return areaTriangulo;
}
float calculaAreaHachurada(float l)
{
    float areaHachurada=calculaAreaQuadrado(l)-calculaAreaTriEquilatero(l)+calculaAreaTriEquilatero(l/2.0)+calculaAreaQuadrado(2.0*l/3.0);
    return areaHachurada;
}
int main()
{
    float lado;
    printf("Qual o lado(em metros) do quadrado? ");scanf("%f",&lado);
    printf("A área hachurada da figura é %.2f metros.",calculaAreaHachurada(lado));
    return 0;
}