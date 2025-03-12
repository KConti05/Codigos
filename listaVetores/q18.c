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
void contaVizinhosMult5(int v[],int lim)
{
    int ind,pares=0;
    for(ind=1;ind<lim;ind++)
    {
        if(v[ind]%5==0&&v[ind-1]%5==0)
        {
            pares++;
        }
    }
    printf("\nVizinhos multiplos de 5 no vetor: %i",pares);
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    int v2[TAM]={10,20,34,45,55,60,78,89};//v2 modificado para testar a funcao
    printf("\nv1:");
    exibeVetor(v1,TAM);
    contaVizinhosMult5(v1,TAM);
    printf("\nv2:");
    exibeVetor(v2,TAM);
    contaVizinhosMult5(v2,TAM);
    return 0;
}