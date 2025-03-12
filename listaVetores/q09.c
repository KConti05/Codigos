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
void exibeMenoresQueUltimoElemento(int v[],int lim)
{
    int ind;
    printf("\nElementos menores que v[%i](%i):",lim,v[lim-1]);
    for(ind=0;ind<lim;ind++)
    {
        if(v[ind]<v[lim-1])
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
    exibeMenoresQueUltimoElemento(v1,TAM);
    return 0;
}