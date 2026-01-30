# 📊 Benchmarking de Algoritmos de Ordenação

Este projeto realiza uma análise comparativa de desempenho entre três algoritmos clássicos de ordenação: **Shell Sort**, **Merge Sort** e **Heap Sort**.

O programa executa os algoritmos sobre conjuntos de dados de diferentes tamanhos (de 100 a 10.000 elementos) e gera métricas precisas sobre a eficiência de cada um.

## 🚀 Como Funciona

O sistema:
1.  Lê arquivos de texto contendo vetores de números inteiros aleatórios.
2.  Ordena esses vetores utilizando os três algoritmos.
3.  Contabiliza o número de **Comparações** e **Movimentações** realizadas.
4.  Gera um relatório percentual (`Resultados.txt`) indicando o "custo" de cada algoritmo em relação ao pior caso do teste atual.

## 🛠️ Tecnologias Utilizadas

* **Linguagem:** C++
* **Conceitos:** Análise de Complexidade, Manipulação de Arquivos, Structs, Vector e Iterators.

## 📋 Estrutura do Projeto

* `main.cpp`: Arquivo principal que inicia os testes.
* `funcoes.h`: Orquestrador dos testes e gerador de relatórios.
* `shellsort.h`, `mergesort.h`, `heapsort.h`: Implementações dos algoritmos.
* `FormattNumber.h`: Utilitário de formatação.
