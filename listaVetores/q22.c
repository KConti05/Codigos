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
void exibeUniao2Vetores(int v1[],int v2[],int lim)
{
    int ind;
    int vUniao[2*TAM];
    
    for(ind=0;ind<2*lim;ind+=2)
    {
        if(v1[ind]!=v2[ind])
        {
            vUniao[ind]=v1[ind/2];
            vUniao[ind+1]=v2[ind/2];
        }
        else
        {
            vUniao[ind]=v1[ind];
            ind--;
        }
    }
    exibeVetor(vUniao,2*TAM);
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    int v2[TAM]={10,23,34,45,56,67,78,89};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    printf("\nv2:");
    exibeVetor(v2,TAM);
    printf("\nUniao de v1 e v2:");
    exibeUniao2Vetores(v1,v2,TAM);
    return 0;
}