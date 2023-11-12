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
