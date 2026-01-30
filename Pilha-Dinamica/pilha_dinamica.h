#ifndef PILHA_DINAMICA_H_INCLUDED
#define PILHA_DINAMICA_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
   T elemento;
   Nodo<T>* ant; // Ponteiro para o elemento anterior (abaixo na pilha)
};

template<typename T>
struct Pilha{
   int card; // Cardinalidade (tamanho atual)
   Nodo<T>* topo; // Ponteiro para o topo
};

// Cria a pilha
template<typename T>
void cria(Pilha<T>& pilha){
   pilha.card = 0;
   pilha.topo = NULL;
}

// Destroi a pilha liberando memória
template<typename T>
void destroi(Pilha<T> &pilha){
   while(pilha.topo != NULL){
      Nodo<T>* temp = pilha.topo; // Guarda o topo atual
      pilha.topo = pilha.topo->ant; // O topo desce um nível
      delete temp; // Apaga o antigo topo
   }
   pilha.card = 0;
}

template<typename T>
bool ehvazia(Pilha<T> pilha){
   return pilha.card == 0;
}

template<typename T>
int numElementos(Pilha<T> pilha){
   return pilha.card;
}

// Verifica se existe o elemento (busca sequencial)
template<typename T>
bool existeElemento(Pilha<T> pilha, T elemento){
   for(Nodo<T>* p = pilha.topo; p != NULL; p = p->ant){
      if(p->elemento == elemento)
         return true;
   }
   return false;
}

// Verifica se a posição é válida
template<typename T>
bool existePosicao(Pilha<T> pilha, int posicao){
   return (posicao >= 1) && (posicao <= pilha.card);
}

// Recupera elemento de uma posição (Obs: em pilhas, geralmente só olhamos o topo)
template<typename T>
T umElemento(Pilha<T> pilha, int posicao){
   if(!existePosicao(pilha, posicao)){
      throw "POSICAO INVALIDA";
   }
   // O topo é a posição 'card', a base é 1.
   // Vamos percorrer do topo para baixo.
   int atualPos = pilha.card;
   Nodo<T>* p = pilha.topo;
   
   while(atualPos > posicao){
      p = p->ant; // Erro corrigido: era p->topo, mas Nodo tem 'ant'
      atualPos--;
   }
   return p->elemento;
}

// Recupera o topo da pilha (Peek)
template<typename T>
T getTopo(Pilha<T> pilha){
   if(ehvazia(pilha)){
      throw "PILHA VAZIA";
   }
   return pilha.topo->elemento;
}

// Empilha (Push)
template<typename T>
void empilha(Pilha<T>& pilha, T elemento){
   Nodo<T>* novo = new Nodo<T>;
   novo->elemento = elemento;
   novo->ant = pilha.topo; // O anterior do novo é o antigo topo
   pilha.topo = novo; // O topo agora é o novo
   pilha.card++;
}

// Desempilha (Pop)
template<typename T>
void desempilha(Pilha<T>& pilha){
   if(ehvazia(pilha)){
      throw "UNDERFLOW"; // Pilha vazia
   }
   Nodo<T>* p = pilha.topo;
   pilha.topo = pilha.topo->ant;
   delete p;
   pilha.card--;
}

// Mostra a pilha (do topo para a base)
template<typename T>
void mostra(Pilha<T> pilha){
   for(Nodo<T>* p = pilha.topo; p != NULL; p = p->ant){
      cout << p->elemento << " ";
   }
   cout << endl;
}

#endif // PILHA_DINAMICA_H_INCLUDED
