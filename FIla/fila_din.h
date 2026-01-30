#ifndef FILA_DIN_H_INCLUDED
#define FILA_DIN_H_INCLUDED

#include <iostream>

using namespace std; // Adicionei para evitar erros com cout/cin

template <typename T>
struct Nodo{
   T dado;
   Nodo<T>* prox;
};

template <typename T>
struct Fila{
   Nodo<T>* inicio;
   Nodo<T>* fim;
   int card;
};

template <typename T>
void cria(Fila<T>& fila){
   fila.inicio = NULL;
   fila.fim = NULL;
   fila.card = 0;
}

template <typename T>
bool ehvazia(Fila<T> fila){
   return fila.card == 0;
}

// CORREÇÃO: Retorno deve ser int, não bool
template <typename T>
int numElementos(Fila<T> fila){
   return fila.card;
}

template <typename T>
bool existeElemento(Fila<T> fila, T elemento){
   Nodo<T>* atual = fila.inicio;
   while(atual != NULL){
      if(atual->dado == elemento)
         return true;
      atual = atual->prox;
   }
   return false;
}

template <typename T>
bool existePosi(Fila<T> fila, int posicao){
   return (posicao >= 1) && (posicao <= fila.card);
}

template <typename T>
T umElemento(Fila<T> fila, int posicao){
   if(!existePosi(fila, posicao)){
      throw "POSICAO INVALIDA";
   }
   Nodo<T>* atual = fila.inicio;
   // CORREÇÃO: Ajuste no loop para pegar a posição correta (base 1)
   for(int i = 1; i < posicao; i++){
      atual = atual->prox;
   }
   return atual->dado;
}

template <typename T>
int getPosicao(Fila<T> fila, T elemento){
   Nodo<T>* atual = fila.inicio;
   int i = 1;
   while(atual != NULL){
      if(atual->dado == elemento){
         return i;
      }
      atual = atual->prox;
      i++; // CORREÇÃO: Faltava ponto e vírgula
   }
   throw "ELEMENTO NAO TA NA FILA";
}

template <typename T>
T getPrimeiro(Fila<T> fila){
   if(ehvazia(fila)){
      throw "FILA VAZIA";
   }
   return fila.inicio->dado;
}

template <typename T>
T getUltimo(Fila<T> fila){
   if(ehvazia(fila)){
      throw "FILA VAZIA";
   }
   return fila.fim->dado;
}

template <typename T>
void insere(Fila<T>& fila, T elemento){
   Nodo<T>* novo = new Nodo<T>;
   novo->dado = elemento;
   novo->prox = NULL;

   if(ehvazia(fila)){
      fila.inicio = novo;
   }else{
      fila.fim->prox = novo;
   }
   fila.fim = novo;
   fila.card++; // CORREÇÃO: Faltava ponto e vírgula
}

template <typename T>
void retira(Fila<T>& fila){
   if(ehvazia(fila)){
      throw "UNDERFLOW";
   }
   Nodo<T>* temp = fila.inicio;
   fila.inicio = fila.inicio->prox;
   if(fila.inicio == NULL){
      fila.fim = NULL;
   }
   delete temp;
   fila.card--;
}

template <typename T>
void mostra(Fila<T> fila){
   Nodo<T>* atual = fila.inicio;
   while(atual != NULL){
      cout << atual->dado << " ";
      atual = atual->prox; // CORREÇÃO: Faltava ponto e vírgula
   }
   cout << endl;
}

template <typename T>
void destroi(Fila<T> fila){
   while(!ehvazia(fila)){
      retira(fila);
   }
}

#endif // FILA_DIN_H_INCLUDED
