//Kauã Contiero Duarte de Oliveira
#include <stdio.h>
#include <math.h>

float calcUfirs(int zona, int camera, float area)
{
    int andar;
    float seguro;
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
            printf("Quantos andares o apartamento tem? 5\n");
            andar=5;
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
    return seguro;
}
int main()
{
    float ufirs1,ufirs2,ufirs3;
    ufirs1=calcUfirs(2,1,19);
    ufirs2=calcUfirs(3,2,52);
    ufirs3=calcUfirs(4,2,120);
    printf("Seguro 1: %.2f\nSeguro 2: %.2f\nSeguro 3: %.2f",ufirs1,ufirs2,ufirs3);
    return 0;
}