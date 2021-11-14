#include "escalonador.h"

int main()
{

    Escalonador *escalonador = new Escalonador();
    Fila *fila1 = criarFila(1);
    Fila *fila2 = criarFila(2);
    Fila *fila3 = criarFila(3);

    adicionarFila(escalonador, fila2);
    adicionarFila(escalonador, fila1);
    adicionarFila(escalonador, fila3);

    imprimirEscalonador(escalonador);

    Processo *processo1 = criarProcesso(1, "VSCode");
    Processo *processo2 = criarProcesso(2, "Discord");
    Processo *processo3 = criarProcesso(3, "Mir4");

    adicionarProcesso(escalonador, processo3, NULL);
    adicionarProcesso(escalonador, processo1, NULL);
    adicionarProcesso(escalonador, processo2, fila2);

    imprimirEscalonador(escalonador);

    executarProcesso(escalonador);

    imprimirEscalonador(escalonador);

    finalizarProcessoPorPID(escalonador, 2);
    finalizarProcesso(escalonador);

    imprimirEscalonador(escalonador);
}