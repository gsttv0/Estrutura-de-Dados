# ⛽ Simulação de Fila de Posto de Gasolina (Fila Dinâmica)

Este projeto implementa uma estrutura de dados de **Fila Dinâmica** (FIFO - First In, First Out) em C++ e a utiliza para simular o fluxo de atendimento em um posto de gasolina.

O objetivo é demonstrar o gerenciamento de memória dinâmica e a aplicação prática de estruturas de dados em simulações de eventos discretos.

## ⚙️ Estrutura do Projeto

* **`fila_din.h`**: Biblioteca (Header) contendo a implementação da Fila genérica utilizando Templates e alocação dinâmica (ponteiros).
* **`main.cpp`**: Algoritmo de simulação que gerencia a chegada de carros, abastecimento e cálculo de litros vendidos.

## 🚀 Funcionalidades da Fila

A estrutura `Fila<T>` suporta operações clássicas:
* `insere()`: Adiciona elemento no fim (Enqueue).
* `retira()`: Remove elemento do início (Dequeue).
* `getPrimeiro()` / `getUltimo()`: Acesso aos dados das extremidades.
* `getPosicao()` / `umElemento()`: Busca e acesso posicional.
* `destroi()`: Limpeza completa da memória.

## 📊 Sobre a Simulação

O programa simula um período de funcionamento (das 08:00 às 12:00) onde:
1.  **Fluxo variável:** A frequência de chegada de carros muda dependendo do horário (pico vs. horário calmo).
2.  **Abastecimento:** Cada carro solicita uma quantidade variável de combustível.
3.  **Processamento:** O sistema atende os carros sequencialmente (Lógica FIFO), removendo-os da fila após o "tempo" de atendimento.
4.  **Relatórios:** Exibe o tamanho da fila em horários chave (09:00 e 11:00) e o total abastecido por carro ao final.
