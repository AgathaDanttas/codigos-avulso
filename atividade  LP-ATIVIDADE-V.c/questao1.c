/*
Crie uma struct Contato para representar informações de contatos, 
incluindo nome, número de telefone e email.
Solicite que o usuário cadastre 3 contatos. Escreva uma função que recebe um nome como parâmetro, 
e retorna o número de telefone correspondente a esse nome. 
Em seguida, implemente um programa que utiliza essa função para buscar e imprimir o número de telefone de um contato específico.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ficha_contato
{
    char nome[200];
    char telefone[200];
    char email[200];
};

#define TAM 3

char *buscar_telefone(struct ficha_contato contatos[], int numContatos, const char *nome)
{
    for (int contador = 0; contador < numContatos; contador++)
    {
        if (strcmp(contatos[contador].nome, nome) == 0)
        {
            return contatos[contador].telefone;
        }
    }

}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct ficha_contato contatos[TAM];

    printf("Cadastro de Contatos:\n");

    for (int contador = 0; contador < TAM; contador++)
    {
        printf("Contato %d:\n", contador + 1);
        printf("Nome: ");
        scanf("%s", contatos[contador].nome);
        printf("Telefone: ");
        scanf("%s", contatos[contador].telefone);
        printf("Email: ");
        scanf("%s", contatos[contador].email);
    }

    char nome_busca[200];
    printf("\nDigite o nome para buscar o telefone: ");
    scanf("%s", nome_busca);

    char *telefoneEncontrado;
    telefoneEncontrado = buscar_telefone(contatos, TAM, nome_busca);

    if (telefoneEncontrado != 0)
    {
        printf("Telefone encontrado: %s\n", telefoneEncontrado);
    }
    else
    {
        printf("Contato não encontrado.\n");
    }

    return 0;
}