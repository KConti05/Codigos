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
void exibeInversoVetor(int v[],int lim)
{
    int ind;
    for(ind=lim-1;ind>=0;ind--)
    {
        printf("\nv[%i]: %i",ind,v[ind]);
    }
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    printf("\nv1 na ordem inversa:");
    exibeInversoVetor(v1,TAM);
    return 0;
}