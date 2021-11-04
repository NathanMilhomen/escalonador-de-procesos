#include "fila.h"

typedef struct escalonador Escalonador;

struct escalonador
{
    Fila *inicio;
    Fila *filaMaiorPrioridade;
};

void adicionarFila(Fila *fila)
{

    Escalonador *escalonador = new Escalonador;

    if (escalonador->inicio == NULL)
    {
        escalonador->inicio = fila;
        escalonador->filaMaiorPrioridade = fila;
    }
    else
    {
        if (fila->prioridade > escalonador->filaMaiorPrioridade->prioridade)
        {
            // Adicionar no começo
        }
        else
        {
            // Adicionar no final
        }
    }
}
void adicionarProcesso(Escalonador *escalonador, Processo *processo, Fila *fila)
{
    if (fila != NULL)
    {
        adicionarProcesso(fila, processo);
    }
    else
    {
        // adiciona a de menor, vulgo ultima fila do escalonador
    }
}
void executarProcesso(Escalonador *escalonador)
{
    // executa o primeiro da fila de maior prioridade, e deppois move ele pra proxima fila
    Fila *fila = escalonador->filaMaiorPrioridade;
    printf("Executando processo %d\n", fila->inicio->pid);
    adicionarProcessoFila(fila->next, fila->inicio);
    removerProcessoFila(fila, fila->inicio);
}
void moverProcessoEntreFilas()
{
    // Mover processo entre filas: transfere um processo de uma fila para outra.
    // O processo movido pode estar em qualquer posição da fila de origem e será colocado no final da fila de destino.
}
void encerrarProcesso(Escalonador *escalonador)
{
    removerProcessoFila(escalonador->filaMaiorPrioridade;, fila->inicio);
}
void encerrarProcessoPorPID()
{
    // Finalizar processo específico: Encerra um processo a partir do ID escolhido, removendo-o completamente do sistema.
    // O processo pode estar em qualquer fila no momento da remoção.
}
