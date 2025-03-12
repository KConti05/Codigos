#include <stdio.h>

int main()
{
    int nAlunos,jaFiz=0,aprovados=0,reprovados=0,qtdMaiorNota=1,qtdMenorNota=1;
    float prova,trabalho,mediaFinal,mediaTotal,somatorioMedias=0,maiorNota=-1,menorNota=11;

    printf("Qual a quantidade de alunos? ");scanf("%d",&nAlunos);
    while(jaFiz<nAlunos)
    {
        jaFiz++;
        printf("==============Aluno %i=============\n",jaFiz);
        printf("Qual a nota dele na prova? ");scanf("%f",&prova);
        printf("Qual a media dos trabalhos? ");scanf("%f",&trabalho);
        mediaFinal=0.85*prova+0.15*trabalho;
        printf("\nMedia do aluno: %.2f.\n", mediaFinal);
        somatorioMedias=mediaFinal+somatorioMedias;

        if(prova>maiorNota)
        {
            qtdMaiorNota=1;
            maiorNota=prova;
        }
        else if(prova==maiorNota)
        {
            qtdMaiorNota++;
        }
        if(prova<menorNota)
        {
            qtdMenorNota=1;
            menorNota=prova;
        }
        else if(prova==menorNota)
        {
            qtdMenorNota++;
        }

        if(prova>=7)
        {
            aprovados++;
        }
        else if(prova<=3)
        {
            reprovados++;
        }
    }
    mediaTotal=somatorioMedias/nAlunos;
    printf("\nAprovados(7 ou mais): %i\nReprovados(3 ou menos): %i\nMedia da Turma: %.2f\nMaior nota: %.2f\nQuantidade de Maior Nota: %i\nMenor nota: %.2f\nQuantidade de Menor Nota: %i",aprovados,reprovados,mediaTotal,maiorNota,qtdMaiorNota,menorNota,qtdMenorNota);
    return 0;
}    