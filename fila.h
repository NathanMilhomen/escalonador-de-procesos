#include "processo.h"
#include <cstdlib>

typedef struct fila Fila;

struct fila
{
    int tamanho;
    Processo *inicio;
    Processo *ultimo;

    int prioridade;

    Fila *next;
};

bool estaVazia(Fila *fila)
{
    if (fila->inicio == NULL || fila->ultimo == NULL || fila->tamanho == 0)
    {
        return true;
    }

    return false;
}

void imprimirFila(Fila *fila)
{
    Processo *atual = fila->inicio;
    while (atual != NULL)
    {
        printf("PID: %d | NOME: %s\n", atual->pid, atual->nome);
        atual = atual->next;
    }
    printf("\n");
}

Fila *criarFila(int prioridade)
{
    Fila *fila = new Fila();
    fila->prioridade = prioridade;
    return fila;
}
Processo *removerProcessoFila(Fila *fila)
{
    Processo *elemento = fila->inicio;

    fila->inicio = elemento->next;
    fila->tamanho -= 1;

    return elemento;
}
void excluirProcesso(Fila *fila)
{
    Processo *processoRemovido = removerProcessoFila(fila);
    free(processoRemovido);
}
bool removerProcessoFilaPorPid(Fila *fila, int pid)
{

    Processo *processoAtual = fila->inicio;
    Processo *processoAnterior = NULL;

    while (processoAtual != NULL)
    {
        if (processoAtual->pid == pid)
        {
            printf("Removendo o processo de pid %d\n", processoAtual->pid);
            if (processoAnterior == NULL)
            {
                fila->inicio = processoAtual->next;
            }
            else
            {
                processoAnterior = processoAtual->next;
            }
            fila->tamanho -= 1;
            free(processoAtual);
            return true;
        }
        else
        {
            processoAnterior = processoAtual;
            processoAtual = processoAtual->next;
        }
    }

    if (fila->next != NULL)
    {
        removerProcessoFilaPorPid(fila->next, pid);
    }
    else
    {
        printf("Nenhum processo com o PID '%d' foi encontrado\n", pid);
        return false;
    }
}
void adicionarProcessoAFila(Processo *novoProcesso, Fila *fila)
{
    if (estaVazia(fila))
    {
        fila->inicio = novoProcesso;
        fila->ultimo = novoProcesso;
    }
    else
    {
        Processo *atual = fila->inicio;
        while (atual->next != NULL)
        {
            atual = atual->next;
        }
        atual->next = novoProcesso;
        fila->ultimo = novoProcesso;
    }
    fila->tamanho += 1;
}
