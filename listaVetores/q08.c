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
void contaImparesVetor(int v[],int lim)
{
    int ind, impar=0;
    for(ind=0;ind<lim;ind++)
    {
        if(v[ind]%2!=0)
        {
            impar++;
        }
    }
    printf("\nQtd de Elementos Impares: %i",impar);
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    printf("\nv1:");
    exibeVetor(v1,TAM);
    contaImparesVetor(v1,TAM);
    return 0;
}