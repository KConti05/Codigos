#include <stdio.h>
#define TAM 8

void exibeVetor(int v[],int lim)
{
    int ind;
    for(ind=0;ind<lim;ind++)
    {
        printf("\nv[%i]: %i",ind,v[ind]);
    }
}
void exibeVetorParesImpares(int v[],int lim)
{
    int ind;
    printf("\nElementos em posicoes pares:");
    for(ind=0;ind<lim;ind+=2)
    {
        printf("\nv[%i]: %i",ind,v[ind]);
    }
    printf("\nElementos em posicoes impares:");
    for(ind=1;ind<lim;ind+=2)
    {
        printf("\nv[%i]: %i",ind,v[ind]);
    }
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    exibeVetorParesImpares(v1,TAM);
    return 0;
}