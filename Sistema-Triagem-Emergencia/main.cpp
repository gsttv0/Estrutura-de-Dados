#include <iostream>
#include "FilaDuplamenteEncadeada.h"
#include "Atendimento.h"

using namespace std;

int main()
{
    FilaDup<Paciente> fila; // Cria a fila de prioridade
    Criafila(fila); // Inicializa

    int op;

    do{
        menu(); // Chama o menu
        op = validaInt();
        executaOp(op, fila);
    }while (op != 5);

    deletaFila(fila); // Limpa a memória antes de sair

    return 0;
}
