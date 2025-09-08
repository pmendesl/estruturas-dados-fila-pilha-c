#include <stdio.h>
#include <stdlib.h>
#include "main.c" // Inclui a implementação da pilha

// Função para testar a pilha
void testarPilha() {
    Pilha historicoDeTestes = criarPilha();

    printf("\n--- Testes de Pilha ---\n");

    // Teste 1: Push e mostrar histórico
    push(&historicoDeTestes, "Ação A");
    push(&historicoDeTestes, "Ação B");
    mostrarHistorico(historicoDeTestes);

    // Teste 2: Pop e mostrar histórico
    char* acaoDesfeita = pop(&historicoDeTestes);
    if (acaoDesfeita != NULL) {
        printf("Ação desfeita: %s\n", acaoDesfeita);
        free(acaoDesfeita);
    }
    mostrarHistorico(historicoDeTestes);

    // Teste 3: Pop até a pilha ficar vazia
    acaoDesfeita = pop(&historicoDeTestes);
    if (acaoDesfeita != NULL) {
        printf("Ação desfeita: %s\n", acaoDesfeita);
        free(acaoDesfeita);
    }
    mostrarHistorico(historicoDeTestes);

    // Teste 4: Pop em pilha vazia
    acaoDesfeita = pop(&historicoDeTestes);
    if (acaoDesfeita != NULL) {
        printf("Ação desfeita: %s\n", acaoDesfeita);
        free(acaoDesfeita);
    }
    mostrarHistorico(historicoDeTestes);

    // Teste 5: Adicionar mais elementos após esvaziar
    push(&historicoDeTestes, "Ação C");
    push(&historicoDeTestes, "Ação D");
    mostrarHistorico(historicoDeTestes);

    // Liberando a pilha restante
    while(historicoDeTestes != NULL) {
        acaoDesfeita = pop(&historicoDeTestes);
        free(acaoDesfeita);
    }

    printf("--- Fim dos Testes de Pilha ---\n");
}

int main() {
    testarPilha();
    return 0;
}
