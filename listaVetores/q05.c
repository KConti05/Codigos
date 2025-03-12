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
void exibePosicaoEspecifica(int v[],int lim)
{
    int ind;
    printf("\nPosicao Desejada(escerra com valor >=8 ou <0): ");scanf("%i",&ind);
    while(ind<lim&&ind>=0)
    {
        printf("\nv[%i]: %i",ind,v[ind]);
        printf("\nProxima Posicao Desejada(escerra com valor >=8 ou <0): ");scanf("%i",&ind);
    }
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nv1: ");
    exibeVetor(v1,TAM);
    exibePosicaoEspecifica(v1,TAM);
    return 0;
}