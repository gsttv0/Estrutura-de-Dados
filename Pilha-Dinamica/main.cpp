#include <iostream>
#include "pilha_dinamica.h" 

using namespace std;

int main()
{
    Pilha<int> pilha1, pilha2;

    cria(pilha1);
    cria(pilha2);

    cout << "Empilhando na Pilha 1: 22, 33, 11" << endl;
    empilha(pilha1, 22);
    empilha(pilha1, 33);
    empilha(pilha1, 11);

    cout << "Empilhando na Pilha 2: 9, 10, 11" << endl;
    empilha(pilha2, 9);
    empilha(pilha2, 10);
    empilha(pilha2, 11);

    cout << "Pilha 1: "; mostra(pilha1);
    cout << "Pilha 2: "; mostra(pilha2);

    if(!ehvazia(pilha1) && !ehvazia(pilha2)){
      if(getTopo(pilha1) == getTopo(pilha2)){
         cout << "Os topos sao iguais (" << getTopo(pilha1) << ")" << endl;
      }else{
         cout << "Os topos sao diferentes" << endl;
      }
    }else{
      cout << "Alguma pilha esta vazia" << endl;
    }
    
    // Boa prática: limpar a memória ao sair
    destroi(pilha1);
    destroi(pilha2);

    return 0;
}
