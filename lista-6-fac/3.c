#include <stdio.h>

int main()
{
    int qtdAlunos,jaFiz=0,jaFizTurma=0,qtdMenos2l=0;
    float peso,agua,percentualMenos2l,somaAguaIngerida,mediaAguaAluno,somaPesoMais3l,qtdMais3l=0,mediaPesoMais3l,somaAguaTurmas;
    
    while(jaFizTurma<3)
    {
        jaFizTurma++;
        printf("\nTURMA %i\n",jaFizTurma);
        printf("Quantos alunos na turma? ");scanf("%i",&qtdAlunos);
        while(jaFiz<qtdAlunos)
        {
            jaFiz++;
            printf("\n===========Aluno %i===========",jaFiz);
            printf("\nQual o peso do aluno? ");scanf("%f",&peso);
            agua=35*peso/1000;
            somaAguaIngerida=agua+somaAguaIngerida;
            if(agua<2)
            {
                qtdMenos2l++;
            }
            if(agua>=3)
            {
                somaPesoMais3l=peso+somaPesoMais3l;
                qtdMais3l++;
            }
            printf("O aluno deve beber %.1fL de agua por dia.",agua);
        }
        percentualMenos2l=qtdMenos2l*100/qtdAlunos;
        mediaAguaAluno=somaAguaIngerida/qtdAlunos;
        mediaPesoMais3l=somaPesoMais3l/qtdMais3l;
        somaAguaTurmas=somaAguaIngerida+somaAguaTurmas;
        printf("\n%i alunos ingerem menos de 2 litros de agua por dia, isso equivale a %.2f %% da turma.\nNo total, a turma ingere %.1fL de agua por dia, dando uma media de %.1fL de agua por aluno.\nA media de pesos dos alunos que consomem mais do que 3L de agua e %.2fKg.",qtdMenos2l,percentualMenos2l,somaAguaIngerida,mediaAguaAluno,mediaPesoMais3l);
        jaFiz=0;
    }
    printf("\nAs 3 turmas consomem, num total, %.2fL de agua.",somaAguaTurmas);
    return 0;
}