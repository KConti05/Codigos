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
void capturaParaVetor(int v[],int lim)
{
    int ind;
    for(ind=0;ind<lim;ind++)
    {
        printf("\nNovo valor para v[%i]: ",ind);scanf("%i",&v[ind]);
    }
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nVetor antes:");
    exibeVetor(v1,TAM);
    printf("\nRecebendo novos valores:");
    capturaParaVetor(v1,TAM);
    printf("\nVetor depois:");
    exibeVetor(v1,TAM);
    return 0;
}