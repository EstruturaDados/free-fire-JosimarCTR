#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// -----------------------------
// Estrutura do item do inventário
// -----------------------------
typedef struct {
    char nome[30];   // Nome do item
    char tipo[20];   // Tipo (arma, munição, cura, ferramenta...)
    int quantidade;  // Quantidade disponível
} Item;

// -----------------------------
// Vetor que armazenará os itens
// -----------------------------
Item mochila[MAX_ITENS];
int qtdItens = 0; // Controla quantos itens já foram cadastrados

// -----------------------------
// Funções do sistema
// -----------------------------

// Inserir novo item na mochila
void inserirItem() {
    if (qtdItens >= MAX_ITENS) {
        printf("\n⚠ A mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\nDigite o nome do item: ");
    scanf(" %[^\n]", novo.nome);  // lê string com espaços

    printf("Digite o tipo do item (arma, munição, cura...): ");
    scanf(" %[^\n]", novo.tipo);

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[qtdItens] = novo;
    qtdItens++;

    printf("\n✅ Item adicionado com sucesso!\n");
}

// Remover item da mochila pelo nome
void removerItem() {
    char nome[30];
    printf("\nDigite o nome do item a ser removido: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            // Desloca os itens para "fechar o buraco"
            for (int j = i; j < qtdItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            qtdItens--;
            printf("\n✅ Item '%s' removido com sucesso!\n", nome);
            return;
        }
    }
    printf("\n⚠ Item não encontrado na mochila.\n");
}

// Listar todos os itens da mochila
void listarItens() {
    printf("\n--- Itens na mochila (%d/%d) ---\n", qtdItens, MAX_ITENS);
    if (qtdItens == 0) {
        printf("A mochila está vazia!\n");
    } else {
        for (int i = 0; i < qtdItens; i++) {
            printf("%d) Nome: %s | Tipo: %s | Quantidade: %d\n",
                   i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
        }
    }
}

// Buscar item pelo nome (busca sequencial)
void buscarItem() {
    char nome[30];
    printf("\nDigite o nome do item que deseja buscar: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("\n🔎 Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }
    printf("\n⚠ Item não encontrado.\n");
}

// -----------------------------
// Função principal (menu do jogo)
// -----------------------------
int main() {
    int opcao;

    do {
        printf("\n===== SISTEMA DE INVENTÁRIO =====\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;
            case 2:
                removerItem();
                listarItens();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf("\n👋 Saindo do sistema... Até a próxima partida!\n");
                break;
            default:
                printf("\n⚠ Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
