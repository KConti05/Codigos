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
void exibeIntercec2Vetores(int v1[],int v2[],int lim)
{
    int ind1,ind2,qtd=0;
    int vIntersec[TAM];
    for(ind1=0;ind1<lim;ind1++)
    {
        for(ind2=0;ind2<lim;ind2++)
        {
            if(v1[ind1]==v2[ind2])
            {
                vIntersec[qtd]=v1[ind1];
                qtd++;
            }
        }
    }
    exibeVetor(vIntersec,TAM);
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    int v2[TAM]={10,2,34,5,56,67,7,89};//modificada para testar a funcao
    printf("\nv1:");
    exibeVetor(v1,TAM);
    printf("\nv2:");
    exibeVetor(v2,TAM);
    printf("\nIntercecao: ");
    exibeIntercec2Vetores(v1,v2,TAM);
    return 0;
}