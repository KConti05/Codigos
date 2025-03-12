#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerNumAleat(int limInf, int limSup)
{
    int dif=(limSup-limInf)+1;
    return rand()%dif+limInf;
}
int main()
{
    //declaração de variáveis
    srand(time(NULL));
    //resto do programa
}