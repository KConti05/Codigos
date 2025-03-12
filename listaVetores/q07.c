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
void somaElementosVetor(int v[],int lim)
{
    int ind;
    int soma=0;
    for(ind=0;ind<lim;ind++)
    {
        soma+=v[ind];
    }
    printf("\nSoma dos elementos do vetor: %i",soma);
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    somaElementosVetor(v1,TAM);
    return 0;
}