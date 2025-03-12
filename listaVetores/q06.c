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
void exibeMaiorValorVetor(int v[],int lim)
{
    int ind;
    int maiorValor=v[0];
    for(ind=1;ind<lim;ind++)
    {
        if(v[ind]>maiorValor)
        {
            maiorValor=v[ind];
        }
    }
    printf("\nMaior Valor: %i",maiorValor);
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    exibeMaiorValorVetor(v1,TAM);
    return 0;
}