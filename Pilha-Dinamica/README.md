# 📚 Pilha Dinâmica (Stack) em C++

Este repositório contém uma implementação de **Pilha Dinâmica** (Dynamic Stack) utilizando C++.

A estrutura segue o princípio **LIFO** (Last In, First Out), onde o último elemento a entrar é o primeiro a sair. Diferente de uma pilha estática (vetor), esta implementação utiliza alocação dinâmica de memória, permitindo que a pilha cresça conforme a necessidade.

## 🚀 Funcionalidades

A biblioteca `pilha_dinamica.h` oferece as seguintes operações:

* **`empilha(elemento)`**: Adiciona um item ao topo (Push).
* **`desempilha()`**: Remove o item do topo (Pop).
* **`getTopo()`**: Retorna o valor do elemento no topo sem remover (Peek).
* **`ehvazia()`**: Verifica se a pilha está vazia.
* **`destroi()`**: Limpa toda a memória alocada para a pilha.
* **Templates:** A estrutura é genérica, aceitando `int`, `float`, `string` ou classes customizadas.

## 🛠️ Tecnologias e Conceitos

* **C++**
* **Templates (Generics):** Reutilização de código para diferentes tipos de dados.
* **Ponteiros:** Manipulação direta de memória para encadear os nós.
* **Alocação Dinâmica (`new`/`delete`):** Gerenciamento manual de memória.
