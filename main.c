
#include "proj.h"
#include <stdio.h>

int main() {
    struct Tarefa tarefas[MAX_TAREFAS];
    int numTarefas = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Deletar Tarefa\n");
        printf("4. Alterar Tarefa\n");
        printf("5. Filtrar Tarefas por Prioridade\n");
        printf("6. Filtrar Tarefas por Estado\n");
        printf("7. Filtrar Tarefas por Categoria\n");
        printf("8. Filtrar Tarefas por Prioridade e Categoria\n");
        printf("9. Exportar Tarefas por Prioridade\n");
        printf("10. Exportar Tarefas por Categoria\n");
        printf("11. Exportar Tarefas por Prioridade e Categoria\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarTarefa(tarefas, &numTarefas);
                break;
            case 2:
                listarTarefas(tarefas, numTarefas);
                break;
            case 3:
                deletarTarefa(tarefas, &numTarefas);
                break;
            case 4:
                alterarTarefa(tarefas, numTarefas);
                break;
            case 5:
                filtrarPorPrioridade(tarefas, numTarefas);
                break;
            case 6:
                filtrarPorEstado(tarefas, numTarefas);
                break;
            case 7:
                filtrarPorCategoria(tarefas, numTarefas);
                break;
            case 8:
                filtrarPorPrioridadeECategoria(tarefas, numTarefas);
                break;
            case 9:
                exportarPorPrioridade(tarefas, numTarefas);
                break;
            case 10:
                exportarPorCategoria(tarefas, numTarefas);
                break;
            case 11:
                exportarPorPrioridadeECategoria(tarefas, numTarefas);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
