/*
Dada uma string s, desenvolver uma função que determine se s é ou não um palíndromo.
*/

#include <stdio.h>
#include <string.h>

//determina se uma string e um palindromo, retorna 0 se nao for e 1 se for
int stringPalindromo(char string[])
{
    //serao usados para rodar a string, uma vindo do inicio da string e outra vindo do fim dela.
    int i, j;
    //strlen e usado para determinar o tamanho da string
    for(i=0,j=strlen(string)-1;i<j;i++,j--)
    {
        if(string[i]!=string[j])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    //'palindromo' armazenara a resposta da funcao 'stringPalindromo'
    int palindromo;
    char string[20];
    //recebendo a string
    printf("Entre com a string: ");gets(string);
    //chamando a funcao
    palindromo=stringPalindromo(string);
    //exibindo resposta
    if(palindromo)
    {
        printf("A string '%s' e um palindromo!", string);
    }
    else
    {
        printf("A string '%s' NAO e um palindromo!", string); 
    }
    return 0;
}