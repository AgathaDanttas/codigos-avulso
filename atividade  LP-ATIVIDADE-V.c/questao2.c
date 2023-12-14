/*
Crie uma função chamada "calcularMedia" que recebe como parâmetro uma struct "Aluno",
esta struct terá informações como: nome, data de nascimento, duas notas e média e retorna a média das notas.
Em seguida, crie um programa que declare um array de 5 alunos
e utilize a função "calcularMedia" para imprimir a média de cada aluno.
Também crie uma função para verificar se um aluno está aprovado ou reprovado
sendo necessário média maior ou igual a 7,0 para aprovação
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno
{
    char nome[30];
    int dia, mes, ano;
    float nota1, nota2;
    float media;
};

float calcular_media(struct Aluno aluno)
{
    float media = (aluno.nota1 + aluno.nota2) / 2;
    return media;
}

#define TAM 3

void verificarAprovacao(struct Aluno aluno) {
    if (aluno.media >= 7.0) {
        printf("%s está APROVADO!\n", aluno.nome);
    } else {
        printf("%s está REPROVADO.\n", aluno.nome);
    }
}

int main()
{
    struct Aluno alunos[TAM];
    float media;
    int contador;
    for (contador = 0; contador < TAM; contador++)
    {
        printf("Digite o nome do aluno %d: ", contador + 1);
        scanf("%s", alunos[contador].nome);
        printf("Digite a data de nascimento do aluno %d: ", contador + 1);
        scanf("%d/%d/%d", &alunos[contador].dia, &alunos[contador].mes, &alunos[contador].ano);
        printf("Digite a primeira nota do aluno %d: ", contador + 1);
        scanf("%f", &alunos[contador].nota1);
        printf("Digite a segunda nota do aluno %d: ", contador + 1);
        scanf("%f", &alunos[contador].nota2);

        alunos[contador].media = calcular_media(alunos[contador]);
    }

    for (contador = 0; contador < TAM; contador++)
    {
    printf("Aluno %d: %s\n", contador + 1, alunos[contador].nome);
    printf("Data de nascimento: %d/%d/%d\n", alunos[contador].dia, alunos[contador].mes, alunos[contador].ano);
    printf("Primeira nota: %.2f\n", alunos[contador].nota1);
    printf("Segunda nota: %.2f\n", alunos[contador].nota2);
    printf("Média: %.2f\n", alunos[contador].media);
    verificarAprovacao(alunos[contador]);
    }
    
return 0;    
}