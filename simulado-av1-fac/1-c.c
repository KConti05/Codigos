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
    float areaTriangulo=(pow(l,2)*sqrt(3))/4;
    return areaTriangulo;
}
float calculaAreaHachurada(float l)
{
    float areaHachurada=calculaAreaQuadrado(l)-calculaAreaTriEquilatero(l)+calculaAreaTriEquilatero(l/2.0)+calculaAreaQuadrado(2*l/3);
    return areaHachurada;
}