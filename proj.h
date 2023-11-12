#ifndef PROJ_H
#define PROJ_H

#define MAX_TAREFAS 100
#define MAX_DESCRICAO 300
#define MAX_CATEGORIA 100

// Enumeração para representar o estado da tarefa
enum Estado {
    NAO_INICIADO,
    EM_ANDAMENTO,
    COMPLETO
};

// Estrutura que representa uma tarefa
struct Tarefa {
    int prioridade;
    char descricao[MAX_DESCRICAO];
    char categoria[MAX_CATEGORIA];
    enum Estado estado;
};


void cadastrarTarefa(struct Tarefa tarefas[], int *numTarefas);

