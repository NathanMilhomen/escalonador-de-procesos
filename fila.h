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

// Remove o processo da fila porém não limpa da memoria
Processo *removerProcessoFila(Fila *fila)
{
    Processo *elemento = fila->inicio;

    fila->inicio = elemento->next;
    fila->tamanho -= 1;

    return elemento;
}
// Remove o processo da fila e limpa da memoria
void excluirProcesso(Fila *fila)
{
    Processo *processoRemovido = removerProcessoFila(fila);
    if (processoRemovido != NULL)
    {
        printf("Removendo processo de PID %d\n", processoRemovido->pid);
        free(processoRemovido);
    }
}
// Remove o processo da fila porém não limpa da memoria
Processo *removerProcessoFilaPorPid(Fila *fila, int pid, bool procurarEmTodasFilas)
{

    Processo *processoAtual = fila->inicio;
    Processo *processoAnterior = NULL;

    while (processoAtual != NULL)
    {
        if (processoAtual->pid == pid)
        {
            if (processoAnterior == NULL)
            {
                fila->inicio = processoAtual->next;
            }
            else
            {
                processoAnterior = processoAtual->next;
            }
            fila->tamanho -= 1;
            return processoAtual;
        }
        else
        {
            processoAnterior = processoAtual;
            processoAtual = processoAtual->next;
        }
    }

    if (fila->next != NULL && procurarEmTodasFilas)
    {
        removerProcessoFilaPorPid(fila->next, pid, procurarEmTodasFilas);
    }
    else
    {
        printf("Nenhum processo com o PID '%d' foi encontrado\n", pid);
        return NULL;
    }
}
// Remove o processo da fila e limpa da memoria
void excluirProcessoPorPID(Fila *fila, int pid)
{
    Processo *processoExcluido = removerProcessoFilaPorPid(fila, pid, true);
    if (processoExcluido != NULL)
    {
        printf("Removendo o processo de pid %d\n", processoExcluido->pid);
        free(processoExcluido);
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
void moverProcessoFilaPorPid(Fila *filaOrigem, Fila *filaDestino, int pid)
{
    Processo *processoASerMovido = removerProcessoFilaPorPid(filaOrigem, pid, false);
    if (processoASerMovido != NULL)
    {
        printf("Movendo processo de PID %d\n", processoASerMovido->pid);
        adicionarProcessoAFila(processoASerMovido, filaDestino);
    }
}
