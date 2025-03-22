/*
Desenvolver uma função que, dada uma string s, crie uma substring que inicie na posição p de s e contenha n caracteres.
Observações: 
i)se p e/ou n forem inválidos, a substring será vazia; 
ii) se s não possuir n caracteres além de p, a substring a ser criada começará em p e terminará no final de s.
*/

#include <stdio.h>
#include <string.h>

void criaSubstring(char string[],char substring[],int posicao,int quantidade)
{
    int i,tamanho;
    //preenchendo 'tamanho'
    tamanho=strlen(string);
    if((posicao>=tamanho)||(posicao<0)||(quantidade<0)||(quantidade>tamanho))
    {
        substring[0]='\0';
    }
    else
    {
        for(i=0;(posicao<=quantidade)&&(string[posicao]);i++,posicao++)
        {
            substring[i]=string[posicao];
        }
        substring[i]='\0';
    }
}
int main()
{
    int p,n;
    char string[20], substring[20];
    //recebendo variaveis
    printf("\nEntre com a string: ");gets(string);
    printf("\nA partir de qual posicao da string '%s' comecara a substring: ",string);scanf("%i",&p);
    printf("\nQuantas posicoes da string serao copiadas: ");scanf("%i",&n);
    //criando substring
    criaSubstring(string, substring, p, n);
    //exibindo strings
    printf("\nString: %s\nSubstring(%i posicoes a partir da posicao %i): %s",string,n,p,substring);
    return 0;
}