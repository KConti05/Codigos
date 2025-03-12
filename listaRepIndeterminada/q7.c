#include <stdio.h>

int totalizaHorasVariaveis(int dias)
{
    int jaFiz=0,horas,horasTotais=0;
    while(jaFiz<dias)
    {
        jaFiz++;
        printf("\n========DIA %i========\n",jaFiz);
        printf("Quantas horas no %i dia: ",jaFiz);scanf("%i",&horas);
        horasTotais=horasTotais+horas;
    }
    return horasTotais;
}
int main()
{
    int codFuncionairo,maiorFuncionario,tipo,jaFiz=1,dias,horaPorDia,horasTotais,qtdVale;
    float salario,maiorSalario=0,valorVale;
    printf("=====================Funcionario 1=====================");
    printf("\nCodigo do primeiro funcionario(0 para encerrar): ");scanf("%i",&codFuncionairo);
    while(codFuncionairo>0)
    {
        printf("\nTipo(1-Fixo,2-Variavel): ");scanf("%i",&tipo);
        while(tipo!=1&&tipo!=2)
        {
            printf("Tipo invalido! Digite um tipo valido(1-Fixo,2-Variavel): ");scanf("%i",&tipo);
        }
        printf("\nQuantos dias? ");scanf("%i",&dias);
        while(dias>20)
        {
            printf("Numero invalido, um funcionario nao pode trabalhar mais de 20 dias. Digite um valor valido: ");scanf("%i",&dias);
        }
        if(tipo==1)
        {
            printf("\nQuantas horas por dia? ");scanf("%i",&horaPorDia);
            horasTotais=horaPorDia*dias;
        }
        else
        {
            horasTotais=totalizaHorasVariaveis(dias);
        }
        printf("\nQuantos Vales: ");scanf("%i",&qtdVale);
        printf("\nPreco de cada vale: ");scanf("%f",&valorVale);
        valorVale=valorVale*qtdVale;
        salario=horasTotais*30.0-valorVale;
        if(salario>maiorSalario)
        {
            maiorFuncionario=codFuncionairo;
        }
        printf("Salario: R$%.2f",salario);
        jaFiz++;
        printf("\n=====================Funcionario %i=====================\n",jaFiz);
        printf("Codigo do proximo funcionario(0 para encerrar): ");scanf("%i",&codFuncionairo);
    }
    printf("Funcionario com maior salario: %i",maiorFuncionario);
    return 0;
}