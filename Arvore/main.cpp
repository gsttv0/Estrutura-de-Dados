#include <iostream>
#include "arvoreBinariaBusca.h"

using namespace std;

int main() {
    ArvoreBinariaBusca<int> av1, av2;
    int n, elemento;

    cria(av1);
    cria(av2);

    cin >> n;

    for(int i=1; i<=n; i++) {
        do {
            cin >> elemento;
        }while((elemento < 10) || (elemento > 80));
        if(elemento % 2 == 0)
            insere(av1, elemento);
        else
            insere(av2, elemento);
        mostra(av1);
        cout << endl;
        mostra(av2);
        cout << endl;
    }

    destroi(av1); destroi(av2);

    return 0;
}
