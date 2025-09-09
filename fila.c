#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da fila (cada paciente)
typedef struct No {
    int senha;
    struct No* proximo;
} No;

// Estrutura da Fila (controla o início e o fim)
typedef struct Fila {
    No* inicio;
    No* fim;
} Fila;

// Função para criar uma fila vazia
Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Função para adicionar um paciente ao fim da fila (enqueue)
void enqueue(Fila* f, int senha) {
    No* novo = (No*)malloc(sizeof(No));
    novo->senha = senha;
    novo->proximo = NULL;

    if (f->fim == NULL) { // Fila está vazia
        f->inicio = novo;
        f->fim = novo;
    } else { // Adiciona no final
        f->fim->proximo = novo;
        f->fim = novo;
    }
    printf("Paciente com senha %d entrou na fila.\n", senha);
}

// Função para atender um paciente do início da fila (dequeue)
int dequeue(Fila* f) {
    if (f->inicio == NULL) {
        printf("A fila de atendimento está vazia.\n");
        return -1; // Retorna -1 para indicar fila vazia
    }

    No* temp = f->inicio;
    int senhaAtendida = temp->senha;

    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL) { // Se a fila ficou vazia
        f->fim = NULL;
    }

    free(temp); // Libera a memória do paciente atendido
    return senhaAtendida;
}

// Função para mostrar o estado atual da fila
void mostrarFila(Fila* f) {
    if (f->inicio == NULL) {
        printf("Fila de Atendimento: [VAZIA]\n");
        return;
    }

    printf("Fila de Atendimento Atual: ");
    No* atual = f->inicio;
    while (atual != NULL) {
        printf("[%d] ", atual->senha);
        atual = atual->proximo;
    }
    printf("\n");
}

// Função principal para simular o atendimento
int main() {
    Fila* filaDeAtendimento = criarFila();
    int senhaAtual = 101; // Começa com a senha 101

    printf("--- Simulação de Fila de Clínica ---\n");

    // Adicionando os primeiros pacientes
    enqueue(filaDeAtendimento, senhaAtual++);
    enqueue(filaDeAtendimento, senhaAtual++);
    enqueue(filaDeAtendimento, senhaAtual++);
    mostrarFila(filaDeAtendimento);
    printf("\n");

    // Atendendo o primeiro paciente
    printf("Chamando próximo paciente...\n");
    int pacienteAtendido = dequeue(filaDeAtendimento);
    if (pacienteAtendido != -1) {
        printf("Paciente com senha %d foi atendido.\n", pacienteAtendido);
    }
    mostrarFila(filaDeAtendimento);
    printf("\n");

    // Adicionando mais um paciente
    enqueue(filaDeAtendimento, senhaAtual++);
    mostrarFila(filaDeAtendimento);
    printf("\n");

    // Atendendo mais dois pacientes
    printf("Chamando próximo paciente...\n");
    pacienteAtendido = dequeue(filaDeAtendimento);
     if (pacienteAtendido != -1) {
        printf("Paciente com senha %d foi atendido.\n", pacienteAtendido);
    }
    mostrarFila(filaDeAtendimento);

    printf("\nChamando próximo paciente...\n");
    pacienteAtendido = dequeue(filaDeAtendimento);
     if (pacienteAtendido != -1) {
        printf("Paciente com senha %d foi atendido.\n", pacienteAtendido);
    }
    mostrarFila(filaDeAtendimento);

    free(filaDeAtendimento); // Libera a memória da fila
    return 0;
}
