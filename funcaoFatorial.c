#include <stdio.h>

int calculaFatorial(int num, int lim) //Numero fatorial, limite do fatorial(geralmente lim=num)
{
    while(lim)
    {
        num=num*(num-1);
    }
    return num;
}