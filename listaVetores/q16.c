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
int conferePertencimentoVetor(int num,int v[],int lim)
{
    int ind,ocorrencia=0;
    for(ind=0;ind<lim&&ocorrencia==0;ind++)
    {
        if(v[ind]==num)
        {
            ocorrencia++;
        }
    }
    return ocorrencia;
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    int num,pertence;
    printf("\nv1:");
    exibeVetor(v1,TAM);
    printf("\nNumero a ser conferido: ");scanf("%i",&num);
    pertence=conferePertencimentoVetor(num,v1,TAM);
    printf("\nPertence?(0-nao, 1-sim)\n%i",pertence);
    return 0;
}
