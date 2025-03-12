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
            printf("Quantos andares o apartamento tem? ");scanf("%i",&andar);
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
    int zona,camera;
    float area,ufirs;
    printf("Qual a zona do apartamento?(1-norte,2-central,3-sul,4-oeste) ");scanf("%i",&zona);
    printf("Qual a área do imóvel(em metros quadrados)? ");scanf("%f",&area);
    printf("O prédio possui câmeras(1-sim, 2-não)? ");scanf("%i",&camera);
    ufirs=calcUfirs(zona,camera,area);
    printf("Seguro: %.2f",ufirs);
    return 0;
}