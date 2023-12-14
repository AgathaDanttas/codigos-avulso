/*
Crie uma struct Contato para representar informações de contatos, incluindo nome,
número de telefone e email. Solicite que o usuário cadastre 3 contatos.
Escreva uma função que recebe um nome como parâmetro,
e retorna o número de telefone correspondente a esse nome.
Em seguida, implemente um programa que utiliza essa função para buscar e imprimir o número de telefone de um contato específico.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct ficha_contato
{
    char nome[200];
    char telefone[200];
    char email[200];
};

#define TAM 3

char buscar_telefone(struct ficha_contato contatos[], int numContatos, char nome)
{
    for (int contador = 0; contador < TAM; contador++)
    {
        if (strcmp(contatos[contador].nome, nome) == 0)
        {
            return contatos[contador].telefone;
        }
    }
}

int main()
{
    struct ficha_contato contatos[TAM];

    setlocale(LC_ALL, "portuguese");

    printf("Cadastrando contato: \n");

    for (int contador = 0; contador < TAM; contador++)
    {
        printf("Contato %d:\n", i + 1);
        printf("Nome: ");
        gets(contatos[i].nome);
        printf("Telefone: ");
        gets(contatos[i].telefone);
        printf("Email: ");
        gets(contatos[i].email);
    }

    char nome_busca[50];
    printf("Digite o nome para buscar telefone: \n");
    gets(nome_busca);
    char telefone_busca = buscar_telefone(contatos, TAM, nome_busca);

    if (telefone_busca != 0)
    {
        printf("Telefone encontrado: %s\n", telefone_busca);
    }
    else
    {
        printf("Contato não encontrado!\n");
    }

    return 0;
}
