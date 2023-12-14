/*
Crie uma struct "Funcionario" com membros para nome, cargo e salário.
Escreva uma função que recebe um array de funcionários e um cargo como parâmetro, 
e retorna a média salarial dos funcionários com esse cargo. Em seguida, 
implemente um programa que utiliza essa função para calcular e 
imprimir a média salarial dos programadores em uma empresa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Funcionario {
    char nome[200];
    char cargo[200];
    float salario;
};

float calcular_media_salarial(struct Funcionario funcionarios[], int numero_funcionarios, const char cargoBuscado[]) {
    float somaSalarios = 0.0;
    int contador = 0;

    for (int contador = 0; contador < numero_funcionarios; contador++) {
        if (strcmp(funcionarios[contador].cargo, cargoBuscado) == 0) {
            somaSalarios += funcionarios[contador].salario;
            contador++;
        }
    }

    if (contador == 0) {
        return 0.0; 
    }

    return somaSalarios / contador;
}

int main() {
    struct Funcionario funcionarios[100];
    int numero_funcionarios = 0;
    char cargos[100][100];

    printf("Para encerrar o cadastro, digite 'fim' como cargo.\n");

    int TAM = 0;
    while (1) {
        printf("\nDigite o nome do cargo ou 'fim' para encerrar: ");
        scanf("%s", cargos[TAM]);

        if (strcmp(cargos[TAM], "fim") == 0 || TAM >= 100) {
            break;
        }

        printf("Cadastro de funcionarios para o cargo de %s\n", cargos[TAM]);

        while (1) {
            printf("\nNome do funcionario (ou 'fim' para encerrar o cadastro de %s): ", cargos[TAM]);
            scanf("%s", funcionarios[numero_funcionarios].nome);

            if (strcmp(funcionarios[numero_funcionarios].nome, "fim") == 0) {
                break;
            }

            strcpy(funcionarios[numero_funcionarios].cargo, cargos[TAM]);
            printf("Salario: ");
            scanf("%f", &funcionarios[numero_funcionarios].salario);

            numero_funcionarios++;

            if (numero_funcionarios >= 100) {
                printf("Limite de funcionarios atingido.\n");
                break;
            }
        }

        TAM++;
    }

    for (int contador = 0; contador < TAM; contador++) {
        float media_salarial = calcular_media_salarial(funcionarios, numero_funcionarios, cargos[contador]);

        if (media_salarial == 0.0) {
            printf("\nNenhum funcionario com o cargo de %s encontrado ou nenhum salario cadastrado para esse cargo.\n", cargos[contador]);
        } else {
            printf("\nA media salarial dos %s e: %.2f\n", cargos[contador], media_salarial);
        }
    }

    return 0;
}