//Uma funcao para validar dados
#include <stdio.h>

int validaDado() //tanto o dado quanto a funcao podem ser floats se necessarios!
{
   int limite,dado; //o limite geralmente e dado pelo proprio codigo nao precisando criar a variavel
   printf("Pergunta dado: ");scanf("%i",&dado);
   while(dado>=limite) //a funcao logica do while pode ser alterada para se adequar ao limite
   {
       printf("Valor nao valido!");
       printf("Digite um valor valido:");scanf("%i",&dado);/*lembrar de dizer a limitacao de valor
       valido, o usuario nao e advinho!*/
   }
   return dado;
}