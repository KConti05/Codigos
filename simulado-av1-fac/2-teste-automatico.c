//Kauã Contiero Duarte de Oliveira
#include <stdio.h>
#include <math.h>

int main()
{
    //testes:
    int zona=0,andar=0,camera=1,jaFiz=0;
    float area=20,seguro;
    while(jaFiz<3)
    {
        jaFiz++;
        zona++;
        andar++;
        area=area*pow(2,(jaFiz-1));
        printf("\n===================TESTE %i===================\nZona: %i\nAndares: %i\nArea: %.1fmetros quadrados.",jaFiz,zona,andar,area);
        if(zona==1||zona==2)
        {
            if(area<=20)
            {
                seguro=40;
            }
            else if(area<=50)
            {
                seguro=60;
            }
            else if(area<=100)
            {
                seguro=70;
            }
            else
            {
                seguro=80;
            }
        }
        else if(zona==4)
        {
            if(area<=20)
            {
                seguro=40;
            }
            else
            {
                seguro=75;
            }
        }
        else
        {
            if(area<=20)
            {
                seguro=40;
            }
            else 
            {
                if(andar<=5)
                {
                    seguro=92;
                }
                else
                {
                    seguro=85;
                }
            }
        }
        if(camera==2)
        {
            seguro=seguro*1.1;
        }
        printf("\nSeguro: %.2f",seguro);
    }
    return 0;
}