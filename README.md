# 📚 Estruturas de Dados e Algoritmos em C++

Este repositório reúne implementações práticas de estruturas de dados fundamentais e algoritmos de ordenação, desenvolvidos durante minha graduação em Ciência da Computação. O objetivo é demonstrar domínio sobre gerenciamento de memória, ponteiros, templates e lógica de programação.

## 📂 Projetos Incluídos

### 1. 🏥 Sistema de Triagem Hospitalar (Fila de Prioridade)
Simulação de um pronto-socorro utilizando o **Protocolo de Manchester**.
* **Estrutura:** Fila Duplamente Encadeada.
* **Destaque:** Lógica de prioridade onde casos graves (Vermelho) furam a fila de casos leves (Azul), independente da ordem de chegada.

### 2. 📊 Benchmark de Ordenação (Sorting)
Ferramenta de análise que compara o desempenho de **Shell Sort**, **Merge Sort** e **Heap Sort**.
* **Funcionalidade:** Lê arquivos com milhares de números e gera um relatório comparando a quantidade de comparações e movimentações de cada algoritmo.

### 3. ⛽ Simulação de Posto de Gasolina (Fila Dinâmica)
Simulação de fluxo de atendimento com regras de negócio variáveis.
* **Estrutura:** Fila Dinâmica (FIFO).
* **Destaque:** Uso de templates (`template <typename T>`) para criar estruturas genéricas.

### 4. 🌳 Árvore Binária de Busca (BST)
Implementação clássica de uma árvore binária.
* **Operações:** Inserção, remoção, busca, cálculo de altura e percursos recursivos.

### 5. 📚 Pilha Dinâmica
Implementação de estrutura LIFO (Last In, First Out) com alocação dinâmica de memória.

## 🛠️ Tecnologias e Conceitos

* **Linguagem:** C++ (Standard 11+)
* **Gerenciamento de Memória:** Uso intensivo de ponteiros, alocação dinâmica (`new`/`delete`) e destrutores.
* **Generics:** Uso de Templates para flexibilidade de tipos.
* **Complexidade:** Análise de Big O aplicada na prática.
