/*
Desenvolva uma struct "Produto" que contenha informações como nome, preço e quantidade em estoque.
Em seguida, desenvolva um menu para facilitar a escolha das opções:
1 - Realizar uma compra
2 - Consultar estoque
3 - Sair do programa.

Escreva funções necessárias para calcular o valor total em estoque do produto
e para atualizar a quantidade em estoque com base em uma compra.
Crie um programa que utiliza essas funções para um produto.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};


void realizar_compra(struct Produto *produto) {
    int quantidade_compra;
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidade_compra);

    if (quantidade_compra <= produto->quantidade && quantidade_compra > 0) {
        float valor_total = quantidade_compra * produto->preco;
        produto->quantidade -= quantidade_compra;

        printf("Compra realizada com sucesso!\n");
        printf("Quantidade subtraída do estoque: %d\n", quantidade_compra);
        printf("Valor total da compra: %.2f\n", valor_total);
    } else {
        printf("Quantidade inválida ou insuficiente em estoque.\n");
    }
}


void consultar_estoque(struct Produto produto) {
    printf("\nProduto: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
    printf("Preço unitário: %.2f\n\n", produto.preco);
}

int main() {

    struct Produto produto = {"Garrafa", 15.00, 30};

    int opcao;
    do {
        printf("Escolha uma opção:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizar_compra(&produto);
                break;
            case 2:
                consultar_estoque(produto);
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}