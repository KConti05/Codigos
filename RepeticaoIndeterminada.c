#include <stdio.h>

int modeloIndeterminado()
{
   int valorDeControle,limite;
   printf("pergunta valor de controle");scanf("%i",&valorDeControle); /*o primeiro
   valor de controle e perguntado antes da repeticao.*/
   //Repeticao Indeterminada:
   while(valorDeControle>=limite) //o limite e o valor limite que englobe a repeticao.
   {
       printf("Repeticao e feita!");
       printf("pergunta valor de controle de novo");scanf("%i",&valorDeControle);/*isso nao e errado,
       a estrutura e assim!*/
   }
   return 0;
}
/*OBS¹.: Em calculos de media o valor da quantidade de integrantes deve ser testada pois pode nao haver integrantes, ai­ daria uma divisao por zero, o codigo fica:

if(integrantes!=0)
{
   media=total/integrantes;   
}
else
{
   printf("Nao ha integrantes!(fazueli)");
}
*/