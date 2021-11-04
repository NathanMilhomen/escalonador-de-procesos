#include "fila.h"
#include <cstdlib>

int main()
{

    Fila *fila = criarFila(1);
    Processo *processo1 = criarProcesso(1, "VSCode");
    Processo *processo2 = criarProcesso(2, "Discord");
    Processo *processo3 = criarProcesso(3, "Mir4");

    adicionarProcessoAFila(processo1, fila);
    adicionarProcessoAFila(processo2, fila);
    adicionarProcessoAFila(processo3, fila);

    imprimirFila(fila);

    removerProcessoFila(fila);

    imprimirFila(fila);
}
