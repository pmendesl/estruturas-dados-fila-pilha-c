#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRICAO 100

// Estrutura do nó da pilha (cada operação)
typedef struct No {
    char descricao[MAX_DESCRICAO];
    struct No* proximo;
} No;

// A Pilha é apenas um ponteiro para o topo
typedef No* Pilha;

// Função para criar uma pilha vazia (retorna NULL)
Pilha criarPilha() {
    return NULL;
}

// Função para adicionar uma operação no topo da pilha (push)
void push(Pilha* topo, const char* descricao) {
    No* novo = (No*)malloc(sizeof(No));
    strncpy(novo->descricao, descricao, MAX_DESCRICAO);
    novo->proximo = *topo;
    *topo = novo;
    printf("Ação realizada: \"%s\"\n", descricao);
}

// Função para remover a última operação do topo (pop/desfazer)
char* pop(Pilha* topo) {
    if (*topo == NULL) {
        printf("Não há ações para desfazer.\n");
        return NULL;
    }

    No* temp = *topo;
    *topo = (*topo)->proximo;

    // Aloca memória para retornar a descrição da ação desfeita
    char* descricaoDesfeita = (char*)malloc(MAX_DESCRICAO * sizeof(char));
    strncpy(descricaoDesfeita, temp->descricao, MAX_DESCRICAO);

    free(temp); // Libera o nó removido
    return descricaoDesfeita;
}

// Função para mostrar o histórico de operações na pilha
void mostrarHistorico(Pilha topo) {
    if (topo == NULL) {
        printf("Histórico de Ações: [VAZIO]\n");
        return;
    }

    printf("--- Histórico de Ações (do mais recente ao mais antigo) ---\n");
    No* atual = topo;
    while (atual != NULL) {
        printf("- %s\n", atual->descricao);
        atual = atual->proximo;
    }
    printf("----------------------------------------------------------\n");
}

// Função principal para simular o editor de texto
int main() {
    Pilha historico = criarPilha();

    printf("--- Simulação de Desfazer Ações ---\n\n");

    // Realizando algumas ações
    push(&historico, "Escreveu a palavra 'Estruturas'");
    push(&historico, "Adicionou a palavra 'de'");
    push(&historico, "Escreveu 'Dados'");
    push(&historico, "Aplicou negrito no título");
    mostrarHistorico(historico);
    printf("\n");

    // Desfazendo a última ação
    printf("Chamando 'desfazer'...\n");
    char* acaoDesfeita = pop(&historico);
    if (acaoDesfeita != NULL) {
        printf("Ação desfeita: \"%s\"\n", acaoDesfeita);
        free(acaoDesfeita); // Libera a memória da string retornada
    }
    mostrarHistorico(historico);
    printf("\n");

    // Desfazendo outra ação
    printf("Chamando 'desfazer'...\n");
    acaoDesfeita = pop(&historico);
    if (acaoDesfeita != NULL) {
        printf("Ação desfeita: \"%s\"\n", acaoDesfeita);
        free(acaoDesfeita);
    }
    mostrarHistorico(historico);

    // Liberando a pilha restante
    while(historico != NULL) {
        acaoDesfeita = pop(&historico);
        free(acaoDesfeita);
    }

    return 0;
}
