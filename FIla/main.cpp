#include "fila_din.h"
#include <iostream>
using namespace std;

int main() {
    Fila<int> fila; // fila para armazenar a quantidade de litros que cada carro vai abastecer
    cria(fila);

    int hora = 8 * 60; // 08:00h em minutos
    int litrosTotal = 0; // total de litros que cada carro abasteceu
    int carroCounter = 1; // contador para simular quantidade fixa de litros

    // Simula��o das 08:00h �s 12:00h
    while (hora <= 12 * 60) {
        // Per�odo das 08:00 �s 10:30 - Chegam de 1 a 4 carros a cada 7 minutos
        if (hora >= 8 * 60 && hora <= 10 * 60 + 30) {
            int carrosChegando = 2 + carroCounter % 3; // alterna a chegada de 1 a 4 carros
            for (int i = 0; i < carrosChegando; i++) {
                int litros = 5 * carroCounter; // cada carro abastece uma quantidade crescente
                insere(fila, litros);
                carroCounter++;
            }
            hora += 7; // Avan�a 7 minutos
        }
        // Per�odo das 10:31 �s 12:00 - Chegam de 0 a 2 carros a cada 4 minutos
        else if (hora >= 10 * 60 + 31 && hora <= 12 * 60) {
            int carrosChegando = carroCounter % 2; // alterna a chegada de 0 a 2 carros
            for (int i = 0; i < carrosChegando; i++) {
                int litros = 5 * carroCounter; // cada carro abastece uma quantidade crescente
                insere(fila, litros);
                carroCounter++;
            }
            hora += 4; // Avan�a 4 minutos
        }

        // Frentista atende os carros a cada 2 minutos
        if (!ehvazia(fila)) {
            retira(fila); // remove o primeiro carro (simulando o abastecimento)
            hora += 2; // Abastecimento de um carro leva 2 minutos
        }

        // Verificar quantos carros aguardam �s 09:00h e �s 11:00h
        if (hora == 9 * 60 || hora == 11 * 60) {
            cout << "Carros aguardando na fila �s " << hora / 60 << ":00h: " << numElementos(fila) << endl;
        }
    }

    // Exibir quantidade de combust�vel que cada carro colocou ao final da simula��o
    cout << "Carros atendidos e quantidade de litros colocados: " << endl;
    while (!ehvazia(fila)) {
        int litros = getPrimeiro(fila); // obt�m o primeiro carro da fila
        cout << litros << " litros." << endl;
        retira(fila); // remove o carro ap�s exibir
    }

    return 0;
}
