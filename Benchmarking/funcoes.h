#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
// Inclui os algoritmos
#include "shellsort.h"
#include "heapsort.h"
#include "mergesort.h"

using namespace std;

struct TipoSort{
    double comparacoes, movimentacoes;
    double porcentagemComparacoes, porcentagemMovimentacoes;
};

TipoSort cria(){
    TipoSort tipo;
    tipo.comparacoes = 0;
    tipo.movimentacoes = 0;
    tipo.porcentagemComparacoes = 0;
    tipo.porcentagemMovimentacoes = 0;
    return tipo;
}

// --- Funções de Leitura e Execução ---

void metodoShell(double &comparacoes, double &movimentacoes, string arq) {
    ifstream arquivo(arq);
    if (!arquivo.is_open()) {
        cout << "ERRO: Arquivo '" << arq << "' nao encontrado!" << endl;
        return;
    }
    vector<int> numeros;
    int numero;
    while (arquivo >> numero) {
        numeros.push_back(numero);
    }
    arquivo.close();

    shellSort(numeros, comparacoes, movimentacoes);
}

void metodoHeap(double &comparacoes, double &movimentacoes, string arq) {
    ifstream arquivo(arq);
    if (!arquivo.is_open()) {
        cout << "ERRO: Arquivo '" << arq << "' nao encontrado!" << endl;
        return;
    }
    vector<int> numeros;
    int numero;
    while (arquivo >> numero) {
        numeros.push_back(numero);
    }
    arquivo.close();

    heapSort(numeros, comparacoes, movimentacoes);
}

void metodoMerge(double &comparacoes, double &movimentacoes, string arq) {
    ifstream arquivo(arq);
    if (!arquivo.is_open()) {
        cout << "ERRO: Arquivo '" << arq << "' nao encontrado!" << endl;
        return;
    }
    vector<int> numeros;
    int numero;
    while (arquivo >> numero) {
        numeros.push_back(numero);
    }
    arquivo.close();

    // Merge Sort precisa de iteradores
    if(!numeros.empty()) {
        mergeSort(numeros, numeros.begin(), numeros.end() - 1, comparacoes, movimentacoes);
    }
}

// --- Funções de Cálculo ---

double comparaValores(double num1, double num2, double num3) {
    double maior = num1;
    if (num2 > maior) maior = num2;
    if (num3 > maior) maior = num3;
    return maior;
}

void calculaResultados(TipoSort &heap, TipoSort &shell, TipoSort &merge){
    double comparacoesMaior = comparaValores(heap.comparacoes, shell.comparacoes, merge.comparacoes);
    double movimentacoesMaior = comparaValores(heap.movimentacoes, shell.movimentacoes, merge.movimentacoes);

    if (comparacoesMaior == 0) comparacoesMaior = 1; // Evita divisão por zero
    if (movimentacoesMaior == 0) movimentacoesMaior = 1;

    heap.porcentagemComparacoes = (double(heap.comparacoes)/comparacoesMaior)*100;
    shell.porcentagemComparacoes = (double(shell.comparacoes)/comparacoesMaior)*100;
    merge.porcentagemComparacoes = (double(merge.comparacoes)/comparacoesMaior)*100;

    heap.porcentagemMovimentacoes = (double(heap.movimentacoes)/movimentacoesMaior)*100;
    shell.porcentagemMovimentacoes = (double(shell.movimentacoes)/movimentacoesMaior)*100;
    merge.porcentagemMovimentacoes = (double(merge.movimentacoes)/movimentacoesMaior)*100;
}

void zeraContadores(TipoSort &tipo){
    tipo.comparacoes = 0;
    tipo.movimentacoes = 0;
    tipo.porcentagemComparacoes = 0;
    tipo.porcentagemMovimentacoes = 0;
}

void printTabela(TipoSort &heap, TipoSort &shell, TipoSort &merge) {
    // ATENÇÃO: Estes arquivos devem existir na pasta do projeto!
    string arquivos[] = {"numeros_0_a_100.txt", "numeros_0_a_500.txt", "numeros_0_a_1000.txt", "numeros_0_a_5000.txt", "numeros_0_a_10000.txt"};
    
    ofstream resultados("Resultados.txt");

    resultados << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    resultados << "|                           |                              Comparacoes                              |                              Movimentacoes                            |" << endl;
    resultados << "|   Quantidade de dados     |-----------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    resultados << "|                           |      Shell Sort       |      Merge Sort       |       Heap Sort       |      Shell Sort       |      Merge Sort       |       Heap Sort       |" << endl;
    resultados << "|---------------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|-----------------------|" << endl;
    
    for (string n : arquivos) {
        zeraContadores(heap);
        zeraContadores(shell);
        zeraContadores(merge);
        
        cout << "Processando arquivo: " << n << "..." << endl;

        metodoHeap(heap.comparacoes, heap.movimentacoes, n);
        metodoMerge(merge.comparacoes, merge.movimentacoes, n);
        metodoShell(shell.comparacoes, shell.movimentacoes, n);
        
        calculaResultados(heap, shell, merge);

        resultados << "| "<< setw(25) << n << " | "
             << setw(20) << fixed << setprecision(2) << shell.porcentagemComparacoes << "% | "
             << setw(20) << fixed << setprecision(2) << merge.porcentagemComparacoes << "% | "
             << setw(20) << fixed << setprecision(2) << heap.porcentagemComparacoes << "% | "
             << setw(20) << fixed << setprecision(2) << shell.porcentagemMovimentacoes << "% | "
             << setw(20) << fixed << setprecision(2) << merge.porcentagemMovimentacoes << "% | "
             << setw(20) << fixed << setprecision(2) << heap.porcentagemMovimentacoes << "% | " << endl;
    }
    resultados << "|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|" << endl;
    
    cout << "\nSucesso! Verifique o arquivo 'Resultados.txt'." << endl;
    resultados.close();
}

#endif // FUNCOES_H_INCLUDED
