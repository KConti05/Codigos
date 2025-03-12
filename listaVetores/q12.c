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
int somaElementosVetor(int v[],int lim) //funcao modificada da q07.
{
    int ind;
    int soma=0;
    for(ind=0;ind<lim;ind++)
    {
        soma+=v[ind];
    }
    return soma;
}
float calculaMediaVetor(int v[],int lim) //funcao modificada da q11.
{
    int soma;
    float media;
    soma=somaElementosVetor(v,lim);
    return media=soma/lim;
}
void exibeValoresMaiorMedia(int v[],int lim)
{
    int ind;
    float media=calculaMediaVetor(v,lim);
    printf("\nElementos maiores que a media:");
    for(ind=0;ind<lim;ind++)
    {
        if(v[ind]>media)
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
    exibeValoresMaiorMedia(v1,TAM);
    return 0;
}