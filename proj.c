#include "proj.h"
#include <stdio.h>
#include <string.h>

void cadastrarTarefa(struct Tarefa tarefas[], int *numTarefas) {
    if (*numTarefas >= MAX_TAREFAS) {
        printf("A lista de tarefas esta cheia. Nao e possivel adicionar mais tarefas.\n");
        return;
    }

    struct Tarefa novaTarefa;

    printf("Cite a urgencia da tarefa (0 a 10): ");
    scanf("%d", &novaTarefa.prioridade);

    printf("Qual a tarefa: ");
    getchar(); // Limpa o buffer do teclado

    // Descricao da tarefa
    int i = 0;
    char c;
    printf("Digite a descricao da tarefa: ");
    while (i < MAX_DESCRICAO - 1 && (c = getchar()) != '\n') {
        novaTarefa.descricao[i++] = c;
    }
    novaTarefa.descricao[i] = '\0';

    printf("Cite quando sera realizada: ");

    // Leitura da categoria da tarefa
    i = 0;
    printf("Digite a categoria da tarefa: ");
    while (i < MAX_CATEGORIA - 1 && (c = getchar()) != '\n') {
        novaTarefa.categoria[i++] = c;
    }
    novaTarefa.categoria[i] = '\0';

    // Inicializa o estado da tarefa como Nao Iniciado (0)
    novaTarefa.estado = NAO_INICIADO;

    tarefas[*numTarefas] = novaTarefa;
    (*numTarefas)++;

    printf("Tarefa cadastrada com sucesso!\n");
}
void listarTarefas(struct Tarefa tarefas[], int numTarefas) {
    if (numTarefas == 0) {
        printf("A lista de tarefas esta vazia.\n");
        return;
    }

    printf("Lista de Tarefas:\n");
    for (int i = 0; i < numTarefas; i++) {
        printf("Tarefa %d:\n", i + 1);
        printf("Prioridade: %d\n", tarefas[i].prioridade);
        printf("Descricao: %s\n", tarefas[i].descricao);
        printf("Categoria: %s\n", tarefas[i].categoria);

        // Adiciona o estado da tarefa
        switch (tarefas[i].estado) {
            case NAO_INICIADO:
                printf("Estado: Nao Iniciado\n");
                break;
            case EM_ANDAMENTO:
                printf("Estado: Em Andamento\n");
                break;
            case COMPLETO:
                printf("Estado: Completo\n");
                break;
            default:
                printf("Estado: Desconhecido\n");
        }

        printf("\n");
    }
}
void deletarTarefa(struct Tarefa tarefas[], int *numTarefas) {
    if (*numTarefas == 0) {
        printf("A lista de tarefas esta vazia. Nao ha tarefas para deletar.\n");
        return;
    }

    int indice;
    printf("Informe a tarefa que deseja deletar (1 a %d): ", *numTarefas);
    scanf("%d", &indice);

    if (indice < 1 || indice > *numTarefas) {
        printf("Indice invalido. Informe um indice valido.\n");
        return;
    }

    for (int i = indice - 1; i < *numTarefas - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*numTarefas)--;
    printf("Tarefa deletada com sucesso!\n");
}
