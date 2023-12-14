#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_pedidos 200
#define tam_clientes 100

struct dados_clientes
{
    char nome[200];
    char cpf[20];
    unsigned int idade;
    char data_nascimento[20];
    int id;
};

struct dados_pedidos
{
    char produto[200];
    int id;
    float valor;
};

void realizar_pagamento()
{
    int forma_pagamento;
    printf("1. À vista\n");
    printf("2. À prazo\n");
    printf("Informe a forma de pagamento: ");
    scanf("%d", &forma_pagamento);
    // Lógica para o pagamento aqui
}

void cadastrarCliente(struct dados_clientes *cliente)
{
    printf("Digite o nome do cliente: ");
    scanf("%s", cliente->nome);
    printf("Digite o CPF do cliente: ");
    scanf("%s", cliente->cpf);
    printf("Digite a idade do cliente: ");
    scanf("%u", &cliente->idade);
    printf("Digite a data de nascimento do cliente (DD/MM/AAAA): ");
    scanf("%s", cliente->data_nascimento);
    printf("Digite o ID do cliente: ");
    scanf("%d", &cliente->id);
}

void realizar_compras(struct dados_pedidos *pedidos, int *contador_pedidos)
{
    if (*contador_pedidos < tam_pedidos)
    {
        printf("Digite o produto: ");
        scanf("%s", pedidos[*contador_pedidos].produto);
        printf("Digite o ID do produto: ");
        scanf("%d", &pedidos[*contador_pedidos].id);
        printf("Digite o valor do produto: ");
        scanf("%f", &pedidos[*contador_pedidos].valor);

        (*contador_pedidos)++;

        printf("Compra realizada com sucesso!\n");
    }
    else
    {
        printf("Limite de pedidos atingido.\n");
    }
}

void consultar_carrinho(struct dados_pedidos *pedidos, int contador_pedidos)
{
    if (contador_pedidos > 0)
    {
        printf("Carrinho de Compras:\n");
        for (int i = 0; i < contador_pedidos; i++)
        {
            printf("Produto: %s, ID: %d, Valor: %.2f\n", pedidos[i].produto, pedidos[i].id, pedidos[i].valor);
        }
    }
    else
    {
        printf("O carrinho de compras está vazio.\n");
    }
}

void acessar_dados_cadastro(struct dados_clientes *cliente)
{
    for (size_t i = 0; i < tam_clientes; i++)
    {
      printf("Dados do Cadastro:\n");
    printf("Nome: %s\n", cliente->nome);
    printf("CPF: %s\n", cliente->cpf);
    printf("Idade: %u\n", cliente->idade);
    printf("Data de Nascimento: %s\n", cliente->data_nascimento);
    printf("ID do Cliente: %d\n", cliente->id);
    }
}

void cabecalho()
{
    printf("*******************************************************************888**************\n");
    printf("*                                                SELLSMART                         *\n");
    printf("* 1. Cadastro                                                                      *\n");
    printf("* 2. Realizar uma Compra                                                           *\n");
    printf("* 3. Consultar Carrinho                                                            *\n");
    printf("* 4. Realizar Pagamento                                                            *\n");
    printf("* 5. Acessar Dados do Cadastro                                                     *\n");
    printf("* 6. Sair                                                                          *\n");
    printf("********************************************************************888*************\n");
}

int main()
{
    int codigo;
    struct dados_clientes cliente[tam_clientes];
    struct dados_pedidos pedidos[tam_pedidos];
    int contador_pedidos = 0;

    do
    {
        cabecalho();
        printf("Digite um numero: \n");
        scanf("%d", &codigo);

        switch (codigo)
        {
        case 1:
            cadastrarCliente(&cliente[0]);
            break;
        case 2:
            realizar_compras(pedidos, &contador_pedidos);
            break;
        case 3:
            // Adicione a lógica para o case 3 aqui
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (codigo != 6);

    return 0;
}
