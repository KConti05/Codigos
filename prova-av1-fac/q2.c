#include <stdio.h>

int eHorarioComercial(float hora)
{
  if(hora>=8&&hora<=18)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
float calculaTempoDescanso(int nViagens,float pesoTransp)
{
  float horas,tempDescanso;
  if(nViagens>6)
  {
    tempDescanso=9;
  }
  else if(pesoTransp<15)
  {
    tempDescanso=2;
  }
  else if(nViagens<=3)
  {
    printf("Hora Trabalhada: ");scanf("%f",&horas);
    if(eHorarioComercial(horas)==0)
    {
      tempDescanso=5;
    }
    else //era pra ser um else if
    {
      tempDescanso=4;
    }
    else //não fechei a chaves
    {
     tempDescanso=pesoTransp/nViagens;
     if(tempDescanso>7)
     {
       tempDescanso=7;
     }
  }
  return tempDescanso;
}
int main()
{
  printf("Teste 1:\nPeso Transportado: 15 toneladas;\nNº de Viagens: 9\nDescanso: %.1f horas",calculaTempoDescanso(9,15));
  printf("Teste 2:\nPeso Transportado: 2 toneladas;\nNº de Viagens: 1\nDescanso: %.1f horas",calculaTempoDescanso(1,2));
  return 0;
}
