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
void contaOcorrenciasVetor(int num,int v[],int lim)
{
    int ind,ocorrencia=0;
    for(ind=0;ind<lim;ind++)
    {
        if(v[ind]==num)
        {
            ocorrencia++;
        }
    }
    printf("\nOcorrencias de %i: %i",num,ocorrencia);
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    int num;
    printf("\nv1:");
    exibeVetor(v1,TAM);
    printf("\nNumero para conferir a ocorrencia: ");scanf("%i",&num);
    contaOcorrenciasVetor(num,v1,TAM);
    return 0;
}