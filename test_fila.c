#include <stdio.h>
#include <stdlib.h>
#include "main.c" // Inclui a implementação da fila

// Função para testar a fila
void testarFila() {
    Fila* filaDeTestes = criarFila();

    printf("\n--- Testes de Fila ---\n");

    // Teste 1: Enqueue e mostrar fila
    enqueue(filaDeTestes, 10);
    enqueue(filaDeTestes, 20);
    mostrarFila(filaDeTestes);

    // Teste 2: Dequeue e mostrar fila
    int atendido = dequeue(filaDeTestes);
    printf("Atendido: %d\n", atendido);
    mostrarFila(filaDeTestes);

    // Teste 3: Dequeue até a fila ficar vazia
    atendido = dequeue(filaDeTestes);
    printf("Atendido: %d\n", atendido);
    mostrarFila(filaDeTestes);

    // Teste 4: Dequeue em fila vazia
    atendido = dequeue(filaDeTestes);
    printf("Atendido: %d\n", atendido);
    mostrarFila(filaDeTestes);

    // Teste 5: Adicionar mais elementos após esvaziar
    enqueue(filaDeTestes, 30);
    enqueue(filaDeTestes, 40);
    mostrarFila(filaDeTestes);

    free(filaDeTestes);
    printf("--- Fim dos Testes de Fila ---\n");
}

int main() {
    testarFila();
    return 0;
}
