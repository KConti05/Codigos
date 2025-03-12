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
int retornaPosicaoNoVetor(int num,int v[],int lim)
{
    int ind,posicao=-1;
    for(ind=0;ind<lim&&posicao==-1;ind++)
    {
        if(v[ind]==num)
        {
            posicao=ind;
        }
    }
    return posicao;
}
int main()
{
    int v1[TAM]={1,5,2,7,3,8,4,6};
    int num,posicao;
    printf("\nv1:");
    exibeVetor(v1,TAM);
    printf("\nNumero a ser conferido: ");scanf("%i",&num);
    posicao=retornaPosicaoNoVetor(num,v1,TAM);
    printf("A posicao de %i no vetor e v1[%i](-1 caso nao esteja no vetor).",num,posicao);
    return 0;
}