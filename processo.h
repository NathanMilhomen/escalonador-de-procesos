#include <stdio.h>
#include <cstring>

typedef struct processo Processo;

struct processo
{
    int pid;
    char nome[20];
    Processo *next;
};

Processo *criarProcesso(int pid, char nome[20])
{
    Processo *processo = new Processo;
    processo->pid = pid;
    strcpy(processo->nome, nome);

    return processo;
};

void imprimir(Processo *processo);