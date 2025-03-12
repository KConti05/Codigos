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
void multiplicaElementosVetor(int v[],int lim)
{
    int ind, prod=1;
    for(ind=0;ind<lim;ind++)
    {
        prod=prod*v[ind];
    }
    printf("\nProduto dos elementos do vetor: %i",prod);
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    multiplicaElementosVetor(v1,TAM);
    return 0;
}