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
int verificaVetorCrescenteOuNao(int v[],int lim)
{
    int ind,verifica=1;
    for(ind=1;ind<lim&&verifica==1;ind++)
    {
        if(v[ind-1]>v[ind])
        {
            verifica=0;
        }
    }
    return verifica;
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    int v2[TAM]={10,23,34,45,56,67,78,89};
    int crescente;
    printf("\nv1:");
    exibeVetor(v1,TAM);
    crescente=verificaVetorCrescenteOuNao(v1,TAM);
    if(crescente==1)
    {
        printf("\nVetor crescente");
    }
    else
    {
        printf("\nVetor nao e crescente");
    }
    printf("\nv2:");
    exibeVetor(v2,TAM);
    crescente=verificaVetorCrescenteOuNao(v2,TAM);
    if(crescente==1)
    {
        printf("\nVetor crescente");
    }
    else
    {
        printf("\nVetor nao e crescente");
    }
    return 0;
}