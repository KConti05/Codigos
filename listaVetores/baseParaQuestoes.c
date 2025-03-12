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
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    int v2[TAM]={10,23,34,45,56,67,78,89};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    printf("\nv2:");
    exibeVetor(v2,TAM);
    return 0;
}