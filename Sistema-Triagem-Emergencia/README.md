# 🏥 Sistema de Triagem e Emergência Hospitalar

Este projeto implementa um sistema de gerenciamento de fila de emergência utilizando **Fila Duplamente Encadeada** e lógica de **Fila de Prioridade** em C++.

O sistema simula a triagem de pacientes baseada no **Protocolo de Manchester**, onde a gravidade do caso define a ordem de atendimento, não apenas a ordem de chegada.

## 🚀 Funcionalidades

* **Triagem de Pacientes:** Classificação por cores/prioridade (Vermelho, Laranja, Amarelo, Verde, Azul).
* **Fila de Prioridade:** O sistema processa automaticamente o paciente com maior gravidade (menor número de prioridade) presente na fila, independente de quando ele chegou.
* **Gerenciamento Dinâmico:** Inserção, remoção (desistência) e consulta de pacientes em tempo real.
* **Estimativa de Tempo:** Cálculo automático do tempo de atendimento baseado na gravidade.

## 🛠️ Estruturas de Dados Utilizadas

* **Lista Duplamente Encadeada (Doubly Linked List):** Permite inserção e remoção eficiente em qualquer ponto da estrutura.
* **Templates:** O núcleo da fila (`FilaDuplamenteEncadeada.h`) é genérico, podendo ser reutilizado para outros tipos de dados.
* **Algoritmo de Busca de Prioridade:** A remoção (`retiraFila`) percorre a lista para encontrar o elemento de maior prioridade (menor valor inteiro).

## 📋 Regras de Prioridade (Triagem)

1. **Vermelho (Prioridade 1):** Emergência - Atendimento Imediato (60 min).
2. **Laranja (Prioridade 2):** Muito Urgente (45 min).
3. **Amarelo (Prioridade 3):** Urgente (30 min).
4. **Verde (Prioridade 4):** Pouco Urgente (15 min).
5. **Azul (Prioridade 5):** Não Urgente (5 min).
