#ifndef ARVOREBINARIABUSCA_H_INCLUDED
#define ARVOREBINARIABUSCA_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T>
struct Nodo{
    T elemento;
    Nodo* subArvEsq;
    Nodo* subArvDir;
};

template<typename T>
struct ArvoreBinariaBusca{
    int card;
    Nodo<T>* raiz;
};

template<typename T>
void cria(ArvoreBinariaBusca<T> &arvore){
    arvore.card = 0;
    arvore.raiz = NULL;
}

template<typename T>
void destroiArvore(Nodo<T>* &raiz){
    if(raiz != NULL){
        destroiArvore(raiz->subArvEsq);
        destroiArvore(raiz->subArvDir);
        delete(raiz);
    }
}

template<typename T>
void destroi(ArvoreBinariaBusca<T> &arvore){
    destroiArvore(arvore.raiz);
    arvore.card = 0;
}

template<typename T>
bool ehVazia(ArvoreBinariaBusca<T> arvore){
    return arvore.card == 0;
}

template<typename T>
int numElementos(ArvoreBinariaBusca<T> arvore, T elemento){
    Nodo<T>* p = arvore.raiz;
    while(p != NULL){
        if(elemento == p->elemento)
            return true;
        else{
            if (elemento < p->elemento)
                p = p->subArvEsq;
            else
                p = p->subArvDir;
        }
    }
    return false;
}

template<typename T>
void insereNaArvore(Nodo<T>* &raiz, T elemento){
    if(raiz == NULL){
        raiz = new Nodo<T>;
        raiz->elemento = elemento;
        raiz->subArvEsq = NULL;
        raiz->subArvDir = NULL;
    }
    else if(elemento < raiz->elemento)
        insereNaArvore(raiz->subArvEsq, elemento);
    else
        insereNaArvore(raiz->subArvDir, elemento);
}

template<typename T>
void insere(ArvoreBinariaBusca<T> &arvore, T elemento){
    insereNaArvore(arvore.raiz, elemento);
    arvore.card++;
}

//implementar retira

template<typename T>
void mostraArvore(Nodo<T>* raiz){
    if(raiz != NULL){
        mostraArvore(raiz->subArvEsq);
        cout << raiz->elemento << " -- ";
        mostraArvore(raiz->subArvDir);
    }
}

template<typename T>
void mostra(ArvoreBinariaBusca<T> arvore){
    mostraArvore(arvore.raiz);
    cout << endl;
}

template<typename T>
int nivelArvore(Nodo<T>* raiz) {
    //se a arvore tiver vazia, o nível é -1 pq não tem nodo
    if(raiz == NULL)
        return -1;

    //calcula o maior nível entre as subarvores, somado com 1
    int nivelEsq = nivelArvore(raiz->subArvEsq);
    int nivelDir = nivelArvore(raiz->subArvDir);

    //retorna o maior nivel entre as subarvores, somado com 1
    if(nivelEsq > nivelDir) //retorna 1 + nivel do lado maior
        return 1 + nivelEsq;
    else
        return 1 + nivelDir;
}

template<typename T>
T somaElementos(Nodo<T>* raiz) {
    //se tiver vazia retorna 0 pra soma
    if(raiz == NULL)
        return 0;

    //soma o elemento atual e chama a func recursivamente nas subarvores
    return raiz->elemento + somaElementos(raiz->subArvEsq) + somaElementos(raiz->subArvDir);
}

//func pra acessar a soma dos elementos a partir da estrutura arvoreBinariaBusca
template<typename T>
T soma(ArvoreBinariaBusca<T> arvore) {
    return somaElementos(arvore.raiz);
}

template<typename T>
void multElementos(Nodo<T>* raiz, int fator) {
    //se for vazia não faz nada
    if(raiz == NULL)
        return;

    //multiplica o elemento atual pelo fator
    raiz->elemento *= fator;

    //chama a função recursivamento nas subarvores
    multElementos(raiz->subArvEsq, fator);
    multElementos(raiz->subArvDir, fator);
}

template<typename T>
void mult(ArvoreBinariaBusca<T> &arvore, int fator) {
    multElementos(arvore.raiz, fator);
}

template<typename T>
Nodo<T>* buscaNodo(Nodo<T>* raiz, T elemento) {
    //se tiver vazia ou o elemento for encontrado
    if(raiz == NULL || raiz->elemento == elemento)
        return raiz;

    //busca recursiva a esquerda se o elemento é menot
    if(elemento < raiz->elemento)
        return buscaNodo(raiz->subArvEsq, elemento);
    else //busca recursiva a direita se o elemento eh maior
        return buscaNodo(raiz->subArvDir, elemento);
}

template<typename T>
int contaSubArv(ArvoreBinariaBusca<T> arvore, T elemento) {
    //busca o nodo com o valor do elemento
    Nodo<T>* nodo = buscaNodo(arvore.raiz, elemento);

    //se o nodo nao for encontrado retorna -1(elemento nao existe)
    if(nodo == NULL)
        return -1;

    //conta as subarvores: 1 se existir uma subarvore, 0 caso contrario
    int numSubs = 0
    if(nodo->subArvEsq != NULL)
        numSubs++;
    if(nodo->subArvDir != NULL)
        numSubs++;
    return numSubs;
}

template<typename T>
T multImpar(Nodo<T>* raiz) {
    //caso esteja vazia, o produto neutro para multi é 1
    if(raiz == NULL)
        return 1;

    //variavel pra armazenar o produto dos valores impares
    T prod = 1;

    //verifica se o elemento atual é impar
    if(raiz->elemento % 2 != 0)
        prod *= raiz->elemento;

    //multiplica os valores impares nas subarvores
    prod *= multImpar(raiz->subArvEsq);
    prod *= multImpar(raiz->subArvDir);

    return prod;
}

template<typename T>
T multImparArv(ArvoreBinariaBusca<T> arvore) {
    return multImpar(arvore.raiz);
}


template<typename T>
void mostraSomenteDireita(Nodo<T>* raiz) {
    //se ta vazia nao faz nada
    if(raiz == NULL)
        return;

    //verifica se o nodo possui apenas a sub direita
    if(raiz->subArvEsq == NULL && raiz->subArvDir != NULL) {
        cout << raiz->elemento << " - ";
    }

    //chama recursica para as subs
    mostraSomenteDireita(raiz->subArvEsq);
    mostraSomenteDireita(raiz->subArvDir);
}

template<typename T>
void mostraNodosSomenteDireia(ArvoreBinariaBusca<T> arvore) {
    mostraSomenteDireita(arvore.raiz);
    cout << endl;
}

#endif //
