#include "fila.h"

typedef struct escalonador Escalonador;

struct escalonador
{
    Fila *inicio;
    Fila *filaMaiorPrioridade;
};

void adicionarFila(Escalonador *escalonador, Fila *fila)
{

    if (escalonador->inicio == NULL)
    {
        escalonador->inicio = fila;
        escalonador->filaMaiorPrioridade = fila;
    }
    else
    {
        Fila *atual = escalonador->filaMaiorPrioridade;

        if (fila->prioridade > escalonador->filaMaiorPrioridade->prioridade)
        {
            // Adicionar no começo

            fila->next = atual;

            escalonador->filaMaiorPrioridade = fila;
        }
        else
        {
            // Adicionar no final
            while (atual->next != NULL)
            {
                atual = atual->next;
            }

            atual->next = fila;
        }
    }
}
void adicionarProcesso(Escalonador *escalonador, Processo *processo, Fila *fila)
{
    if (fila != NULL)
    {
        adicionarProcessoAFila(processo, fila);
    }
    else
    {
        // adiciona a de menor, vulgo ultima fila do escalonador
        Fila *atual = escalonador->filaMaiorPrioridade;
        while (atual->next != NULL)
        {
            atual = atual->next;
        }
        adicionarProcessoAFila(processo, atual);
    }
}
Fila *getPrimeiraListaNaoVazia(Escalonador *escalonador)
{
    Fila *fila = escalonador->filaMaiorPrioridade;
    while (fila->tamanho <= 0 && fila->next != NULL)
    {
        fila = fila->next;
    }

    return fila;
}
void executarProcesso(Escalonador *escalonador)
{
    // executa o primeiro da fila de maior prioridade, e deppois move ele pra proxima fila
    Fila *fila = getPrimeiraListaNaoVazia(escalonador);

    if (fila->tamanho > 0)
    {
        printf("Executando processo %d na fila de prioridade %d\n", fila->inicio->pid, fila->prioridade);
        adicionarProcessoAFila(fila->inicio, fila->next);
        removerProcessoFila(fila);
    }
    else
    {
        printf("Nenhum processo para ser executado");
    }
}
void moverProcessoEntreFilas()
{
    // Mover processo entre filas: transfere um processo de uma fila para outra.
    // O processo movido pode estar em qualquer posição da fila de origem e será colocado no final da fila de destino.
}
void finalizarProcesso(Escalonador *escalonador)
{
    Fila *fila = getPrimeiraListaNaoVazia(escalonador);
    excluirProcesso(fila);
}
void finalizarProcessoPorPID(Escalonador *escalonador, int pid)
{
    // Finalizar processo específico: Encerra um processo a partir do ID escolhido, removendo-o completamente do sistema.
    // O processo pode estar em qualquer fila no momento da remoção.
    Fila *filaAtual = getPrimeiraListaNaoVazia(escalonador);
    removerProcessoFilaPorPid(filaAtual, pid);
}

void imprimirEscalonador(Escalonador *escalonador)
{
    printf("\n");
    Fila *atual = escalonador->filaMaiorPrioridade;
    while (atual != NULL)
    {
        printf("Fila de prioridade %d | %d elementos\n", atual->prioridade, atual->tamanho);
        atual = atual->next;
    }
    printf("\n");
}
