/*
Suponha que não existissem as funções strlen, strcpy, strcat e strcmp. Pede-se, então, a
implementação de funções que tenham o mesmo objetivo daquelas.
*/

#include <stdio.h>

//strlen: recebe uma string e retorna seu tamanho, ignorando '\0'.
int stringTamanho(char string[])
{
    //'i' contara a quantidade de letras da string
    int i;
    //a condição 'i' significa que i nao seja nulo, equivale a 'i!='\0''
    for(i=0;string[i];i++);
    //por ser um for sem ação, apenas contando i, pode-se eliminar as chaves e apenas finaliza-lo com um ';'.
    return i;
}
//strcpy: recebe 2 strings, 'destino' e 'fonte, os caracteres da string 'fonte' serao copiados para a string 'destino'. Para nao causar OVERFLOW a string 'fonte' deve ser menor que a string 'destino'
void stringCopia(char strDestino[], char strFonte[])
{
    int i;
    //realizando a copia
    for(i=0;strFonte[i];i++)
    {
        strDestino[i]=strFonte[i];
    }
    //finalizando com o '\0'
    strDestino[i]='\0';
}
//strcat: a string 'fonte' e concatenada(copiada ao fim) com a string 'destino', o primeiro caracter de 'fonte' subistitui o '\0' da 'destino'.
void stringConcatena(char strDestino[], char strFonte[])
{
    //'i' servira para preencher a 'destino' enquanto j percorrera 'fonte'
    int i, j;
    //realizando a concatenacao, i usa a 'stringTamanho' para ter um valor inicial, começando a preencher no '\0' de 'fonte'
    for(i=stringTamanho(strDestino),j=0;strFonte[j];i++,j++)
    {
        strDestino[i]=strFonte[j];
    }
    //finalizando com '\0'
    strDestino[i]='\0';
}
//strcmp: recebe duas string e as compara retornando o valor da diferneca entre as duas(a diferenca e a distancia alfabetica entre as duas, utilizando a tabela ASCII de parametro)
int stringCompara(char string1[], char string2[])
{
    int i;
    //realizando a comparacao, a condicao do for faz com que elas sejam comparadas enquanto o caracter de ambas tiver o mesmo valor e ate que uma delas acabe
    for(i=0;(string1)&&(string1==string2);i++);
    //no momento em que uma das condicoes pare de ser atendidas o valor retornado sera a diferenca entre os ultimos 2 caracteres comparados
    return (string1[i]-string2[i]);
}
int main()
{
    //declarando 3 strings para testes, 2 delas serao recebidas pelo usuario e a terceira sera preenchida durante a execucao do programa
    char string1[20],string2[20],string3[20];
    //'tamanho' sera usada para armazenar o tamanho das 2 primeiras strings
    int vTamanho[2];
    //recebendo a primeira string e exibindo seu tamanho com a funcao 'stringTamanho'
    //gets funciona como um scaf para strings
    printf("\nPrimeira String: "); gets(string1);
    vTamanho[0]=stringTamanho(string1);
    printf("\n A string %s possui %i caracteres.\n",string1,vTamanho[0]);
    //recebendo e exibindo o tamanho de 'string2'
    printf("\nSegunda String: "); gets(string2);
    vTamanho[1]=stringTamanho(string2);
    printf("\n A string %s possui %i caracteres.\n",string2,vTamanho[1]);
    //preenchendo a 'string3' utilizando 'stringCopia'
    stringCopia(string3,string1);
    //concatenando a segunda string na terceira utilizando 'stringConcatena'
    stringConcatena(string3,string2);
    //exibindo as 3 strings pos concatenacao
    printf("\nAs strings ficaram: %s, %s e %s.\n", string1, string2, string3);
    //comparando as strings e exibindo a distancia alfabetica entre elas
    printf("\nA distancia alfabetica entre %s e %s e: %i\n",string1,string2,stringCompara(string1,string2));
    printf("\nA distancia alfabetica entre %s e %s e: %i\n",string2,string3,stringCompara(string2,string3));
    printf("\nA distancia alfabetica entre %s e %s e: %i\n",string1,string3,stringCompara(string1,string3));
    return 0;
}