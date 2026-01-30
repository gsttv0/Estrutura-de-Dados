#include <iostream>
#include "funcoes.h"

using namespace std;

int main() {
    TipoSort heap = cria();
    TipoSort shell = cria();
    TipoSort merge = cria();
    
    // Inicia a bateria de testes e gera o relatório
    printTabela(heap, shell, merge);
    
    return 0;
}
