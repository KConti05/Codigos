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
void exibeMultiplosPosicao(int v[],int lim)
{
    int ind;
    printf("\nValores multiplos de suas posicoes:");
    for(ind=1;ind<lim;ind++)//ind comeca em 1 pois nao ha divisao por 0!
    {
        if(v[ind]%ind==0)
        {
            printf("\nv[%i]: %i",ind,v[ind]);
        }
    }
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    exibeMultiplosPosicao(v1,TAM);
    return 0;
}