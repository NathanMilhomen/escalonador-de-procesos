#include "escalonador.h"

int main()
{

    Escalonador *escalonador = new Escalonador();
    Fila *fila1 = criarFila(1);
    Fila *fila2 = criarFila(2);
    Fila *fila3 = criarFila(3);
    Fila *fila4 = criarFila(4);
    Fila *fila5 = criarFila(5);

    adicionarFila(escalonador, fila2);
    adicionarFila(escalonador, fila4);
    adicionarFila(escalonador, fila1);
    adicionarFila(escalonador, fila3);
    adicionarFila(escalonador, fila5);

    imprimirEscalonador(escalonador);

    Processo *processo1 = criarProcesso(1, "VSCode");
    Processo *processo2 = criarProcesso(2, "Discord");
    Processo *processo3 = criarProcesso(3, "Spotify");
    Processo *processo4 = criarProcesso(4, "Chrome");
    Processo *processo5 = criarProcesso(5, "Paint");
    Processo *processo6 = criarProcesso(6, "Email");
    Processo *processo7 = criarProcesso(7, "Explorer");
    Processo *processo8 = criarProcesso(8, "CS");
    Processo *processo9 = criarProcesso(9, "Firefox");

    adicionarProcesso(escalonador, processo9, fila5);
    adicionarProcesso(escalonador, processo3, NULL);
    adicionarProcesso(escalonador, processo1, NULL);
    adicionarProcesso(escalonador, processo2, fila2);
    adicionarProcesso(escalonador, processo4, fila3);
    adicionarProcesso(escalonador, processo5, fila2);
    adicionarProcesso(escalonador, processo6, fila4);
    adicionarProcesso(escalonador, processo7, fila1);
    adicionarProcesso(escalonador, processo8, fila5);

    imprimirEscalonador(escalonador);

    executarProcesso(escalonador);

    imprimirEscalonador(escalonador);

    finalizarProcessoPorPID(escalonador, 4);
    imprimirEscalonador(escalonador);
    finalizarProcesso(escalonador);
    imprimirEscalonador(escalonador);
    moverProcessoFilaPorPid(fila4, fila2, 6);

    imprimirEscalonador(escalonador);

    executarProcesso(escalonador);
    executarProcesso(escalonador);
    executarProcesso(escalonador);

    imprimirEscalonador(escalonador);
}