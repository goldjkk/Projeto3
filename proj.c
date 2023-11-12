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

void alterarTarefa(struct Tarefa tarefas[], int numTarefas) {
    int indice;
    printf("Informe a tarefa que deseja alterar (1 a %d): ", numTarefas);
    scanf("%d", &indice);

    if (indice < 1 || indice > numTarefas) {
        printf("Indice invalido. Informe um indice valido.\n");
        return;
    }

    printf("Escolha o campo a ser alterado:\n");
    printf("1. Prioridade\n");
    printf("2. Descricao\n");
    printf("3. Categoria\n");
    printf("4. Estado\n");

    int opcao;
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Nova prioridade: ");
            scanf("%d", &tarefas[indice - 1].prioridade);
            break;
        case 2:
            printf("Nova descricao: ");
            getchar(); // Limpa o buffer do teclado
            fgets(tarefas[indice - 1].descricao, sizeof(tarefas[indice - 1].descricao), stdin);
            tarefas[indice - 1].descricao[strcspn(tarefas[indice - 1].descricao, "\n")] = '\0'; // Remove a quebra de linha do fgets
            break;
        case 3:
            printf("Nova categoria: ");
            getchar(); // Limpa o buffer do teclado
            fgets(tarefas[indice - 1].categoria, sizeof(tarefas[indice - 1].categoria), stdin);
            tarefas[indice - 1].categoria[strcspn(tarefas[indice - 1].categoria, "\n")] = '\0'; // Remove a quebra de linha do fgets
            break;
        case 4:
            printf("Novo estado (0 - Nao Iniciado, 1 - Em Andamento, 2 - Completo): ");
            scanf("%d", (int*)&tarefas[indice - 1].estado);
            break;
        default:
            printf("Opcao invalida.\n");
    }
}

void filtrarPorPrioridade(struct Tarefa tarefas[], int numTarefas) {
    int prioridadeFiltro;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridadeFiltro);

    printf("Tarefas com prioridade %d:\n", prioridadeFiltro);
    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeFiltro) {
            printf("Descricao: %s, Categoria: %s, Estado: %d\n", tarefas[i].descricao, tarefas[i].categoria, tarefas[i].estado);
        }
    }
}

void filtrarPorEstado(struct Tarefa tarefas[], int numTarefas) {
    int estadoFiltro;
    printf("Digite o estado desejado (0 - Nao Iniciado, 1 - Em Andamento, 2 - Completo): ");
    scanf("%d", &estadoFiltro);

    printf("Tarefas com estado %d:\n", estadoFiltro);
    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].estado == estadoFiltro) {
            printf("Descricao: %s, Categoria: %s, Prioridade: %d\n", tarefas[i].descricao, tarefas[i].categoria, tarefas[i].prioridade);
        }
    }
}

void filtrarPorCategoria(struct Tarefa tarefas[], int numTarefas) {
    char categoriaFiltro[MAX_CATEGORIA];
    printf("Digite a categoria desejada: ");
    getchar(); // Limpa o buffer do teclado
    fgets(categoriaFiltro, sizeof(categoriaFiltro), stdin);
    categoriaFiltro[strcspn(categoriaFiltro, "\n")] = '\0'; // Remove a quebra de linha do fgets

    printf("Tarefas com categoria %s:\n", categoriaFiltro);
    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoriaFiltro) == 0) {
            printf("Descricao: %s, Prioridade: %d, Estado: %d\n", tarefas[i].descricao, tarefas[i].prioridade, tarefas[i].estado);
        }
    }
}

void filtrarPorPrioridadeECategoria(struct Tarefa tarefas[], int numTarefas) {
    int prioridadeFiltro;
    printf("Digite a prioridade desejada: ");
    scanf("%d", &prioridadeFiltro);

    char categoriaFiltro[MAX_CATEGORIA];
    printf("Digite a categoria desejada: ");
    getchar(); // Limpa o buffer do teclado
    fgets(categoriaFiltro, sizeof(categoriaFiltro), stdin);
    categoriaFiltro[strcspn(categoriaFiltro, "\n")] = '\0'; // Remove a quebra de linha do fgets

    printf("Tarefas com prioridade %d e categoria %s:\n", prioridadeFiltro, categoriaFiltro);
    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeFiltro && strcmp(tarefas[i].categoria, categoriaFiltro) == 0) {
            printf("Descricao: %s, Estado: %d\n", tarefas[i].descricao, tarefas[i].estado);
        }
    }
}

void exportarPorPrioridade(struct Tarefa tarefas[], int numTarefas) {
    int prioridadeExportar;
    printf("Digite a prioridade desejada para exportar: ");
    scanf("%d", &prioridadeExportar);

    FILE *arquivo = fopen("tarefas_por_prioridade.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportacao.\n");
        return;
    }

    fprintf(arquivo, "Tarefas com prioridade %d:\n", prioridadeExportar);
    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeExportar) {
            fprintf(arquivo, "Descricao: %s, Categoria: %s, Estado: %d\n", tarefas[i].descricao, tarefas[i].categoria, tarefas[i].estado);
        }
    }

    fclose(arquivo);
    printf("Tarefas exportadas com sucesso!\n");
}

void exportarPorCategoria(struct Tarefa tarefas[], int numTarefas) {
    char categoriaExportar[MAX_CATEGORIA];
    printf("Digite a categoria desejada para exportar: ");
    getchar(); // Limpa o buffer do teclado
    fgets(categoriaExportar, sizeof(categoriaExportar), stdin);
    categoriaExportar[strcspn(categoriaExportar, "\n")] = '\0'; // Remove a quebra de linha do fgets

    FILE *arquivo = fopen("tarefas_por_categoria.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportacao.\n");
        return;
    }

    fprintf(arquivo, "Tarefas com categoria %s:\n", categoriaExportar);
    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoriaExportar) == 0) {
            fprintf(arquivo, "Descricao: %s, Prioridade: %d, Estado: %d\n", tarefas[i].descricao, tarefas[i].prioridade, tarefas[i].estado);
        }
    }

    fclose(arquivo);
    printf("Tarefas exportadas com sucesso!\n");
}

void exportarPorPrioridadeECategoria(struct Tarefa tarefas[], int numTarefas) {
    int prioridadeExportar;
    printf("Digite a prioridade desejada para exportar: ");
    scanf("%d", &prioridadeExportar);

    char categoriaExportar[MAX_CATEGORIA];
    printf("Digite a categoria desejada para exportar: ");
    getchar(); // Limpa o buffer do teclado
    fgets(categoriaExportar, sizeof(categoriaExportar), stdin);
    categoriaExportar[strcspn(categoriaExportar, "\n")] = '\0'; // Remove a quebra de linha do fgets

    FILE *arquivo = fopen("tarefas_por_prioridade_e_categoria.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de exportacao.\n");
        return;
    }

    fprintf(arquivo, "Tarefas com prioridade %d e categoria %s:\n", prioridadeExportar, categoriaExportar);
    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridadeExportar && strcmp(tarefas[i].categoria, categoriaExportar) == 0) {
            fprintf(arquivo, "Descricao: %s, Estado: %d\n", tarefas[i].descricao, tarefas[i].estado);
        }
    }

    fclose(arquivo);
    printf("Tarefas exportadas com sucesso!\n");
}
