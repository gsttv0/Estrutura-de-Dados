#ifndef FILADUPLAMENTEENCADEADA_H
#define FILADUPLAMENTEENCADEADA_H

#include <iostream>
#include <string> // Necessário para string
#include <cstdlib> // Necessário para atoi
#include <cctype> // Necessário para isdigit, isalpha

using namespace std;

// Funções auxiliares (Adicionei 'inline' para evitar erro de definição múltipla)
inline int validaInt(){
    string info;
    int x;
    unsigned int i;
    bool validada;
    do {
        validada = true;
        getline(cin, info);
        if (info == "")
            validada = false;
        else if (!isdigit(info[0]))
            validada = false;
        else
            for (i = 1; i < info.length(); i++)
                if (!isdigit(info[i])) {
                    validada = false;
                    break;
                }
        if (!validada)
            cout << "Numero invalido, digite novamente." << endl;
    } while (!validada);
    x = atoi(info.c_str());
    return x;
}

inline string validaString() {
    string info, nome;
    bool validada;
    unsigned int i;
    do {
        validada=true;
        getline(cin,info);
        if(info=="")
            validada= false;
        for(i=0; i<info.length(); i++)
            if(not isalpha(info[i]) and info[i]!=' ')
                validada= false;
        if(not validada)
            cout <<"Entrada invalida, digite novamente"<< endl;
    } while(not validada);
    nome = info;
    for(unsigned int i = 0; i < info.size(); i++){
        nome[i] = toupper(nome[i]);
    }
    return nome;
}

template<typename T>
struct Nodo{
    int prio;
    T elem;
    Nodo *prox;
    Nodo *ant;
};

template<typename T>
struct FilaDup{
    int card;
    Nodo<T>* inicio;
    Nodo<T>* fim;
};

template<typename T>
void Criafila(FilaDup<T> &fila){
    fila.card = 0;
    fila.fim = nullptr;
    fila.inicio = nullptr;
}

template<typename T>
int retornaCard(FilaDup<T> fila){
    return fila.card;
}

template<typename T>
Nodo<T>* retornaInicio(FilaDup<T> fila){
    return fila.inicio;
}

template<typename T>
Nodo<T>* retornaFim(FilaDup<T> fila){
    return fila.fim;
}

template<typename T>
bool ehvazia(FilaDup<T> fila){
    return fila.card == 0;
}

template<typename T>
void addFila(FilaDup<T> &fila, T elemento, int prioridade){
    Nodo<T> *aux = new Nodo<T>;
    aux->elem = elemento;
    aux->prio = prioridade;
    aux->prox = nullptr;
    
    if(fila.inicio == nullptr){ 
        aux->ant = nullptr;
        fila.inicio = aux;
        fila.fim = aux;
    } else {
        Nodo<T> *p = fila.fim;
        aux->ant = p;
        p->prox = aux;
        fila.fim = aux;
    }
    fila.card++;
}

template<typename T>
void retiraFila(FilaDup<T> &fila){
    if(ehvazia(fila)){
        throw("A FILA ESTA VAZIA");
    }

    Nodo<T> *maiorPrio = fila.inicio; 
    Nodo<T> *atual = fila.inicio->prox; 
    
    // Busca o elemento com MENOR valor de prioridade (1 é maior que 5 na triagem)
    while(atual != nullptr) {
        if(atual->prio < maiorPrio->prio) { 
            maiorPrio = atual;
        }
        atual = atual->prox; 
    }

    if(maiorPrio == fila.inicio){ 
        fila.inicio = maiorPrio->prox;
        if(fila.inicio != nullptr){
            fila.inicio->ant = nullptr; 
        } else {
            fila.fim = nullptr; // Se era o único, o fim também vira null
        }
    } else if (maiorPrio == fila.fim){ 
        fila.fim = maiorPrio->ant; 
        fila.fim->prox = nullptr; 
    } else { 
        maiorPrio->ant->prox = maiorPrio->prox;
        maiorPrio->prox->ant = maiorPrio->ant;
    }
    
    delete maiorPrio;
    fila.card--;
}

template<typename T>
bool existeElem(FilaDup<T> fila, T elem){
    if(!ehvazia(fila)){
        Nodo<T>* aux = fila.inicio;
        while(aux != nullptr){
            if(aux->elem == elem){
                return true;
            }
            aux = aux->prox;
        }
    }
    return false;
}

template<typename T>
bool existeElemStruct(FilaDup<T> fila, T elem){
    if(!ehvazia(fila)){
        Nodo<T>* aux = fila.inicio;
        while(aux != nullptr){
            if(aux->elem.nome == elem.nome){
                return true;
            }
            aux = aux->prox;
        }
    }
    return false;
}

template<typename T>
void deletaFila(FilaDup<T> &fila){
    Nodo<T>* aux1 = fila.inicio;
    while(aux1 != nullptr){
        Nodo<T>* aux2 = aux1->prox;
        delete aux1;
        aux1 = aux2;
    }
    fila.card = 0;
    fila.inicio = nullptr;
    fila.fim = nullptr;
}

// Nota: Essa função é custosa O(N^2), ideal seria usar uma estrutura ordenada.
template<typename T>
void mostraFilaPrioStruct(FilaDup<T> fila){
    if(ehvazia(fila)){
         cout << "Fila Vazia." << endl;
         return;
    }
    FilaDup<T> filaAux; 
    Criafila(filaAux);
    
    // Copia superficial para não estragar a fila original
    // (Lógica simplificada para visualização)
    // Para evitar complexidade, vamos apenas percorrer e imprimir por ordem de prioridade (1 a 5)
    
    for(int p = 1; p <= 5; p++) {
        Nodo<T>* aux = fila.inicio;
        while(aux != nullptr) {
            if(aux->prio == p) {
                cout << "Nome: " << aux->elem.nome 
                     << " | Condicao: " << aux->elem.condicao 
                     << " | Prioridade: " << aux->prio << endl;
            }
            aux = aux->prox;
        }
    }
}

template<typename T>
void RemovefilaStruct(FilaDup<T>& fila, T elem) {
    if(ehvazia(fila)){
        throw("A FILA ESTA VAZIA");
    }
    if(!existeElemStruct(fila, elem)) { 
       throw("ESTE ELEMENTO NAO EXISTE NA FILA");
    }
    Nodo<T>* atual = fila.inicio; 
    while(atual != nullptr) { 
        if(atual->elem.nome == elem.nome) { 
            if(atual == fila.inicio) { 
                fila.inicio = atual->prox; 
                if(fila.inicio != nullptr) { 
                    fila.inicio->ant = nullptr;
                } else {
                    fila.fim = nullptr; // Importante
                }
            } else if(atual == fila.fim) { 
                fila.fim = atual->ant;
                fila.fim->prox = nullptr;
            } else {
                atual->ant->prox = atual->prox;
                atual->prox->ant = atual->ant;
            }
            delete atual;
            fila.card--;
            return;
        }
        atual = atual->prox;
    }
}

template<typename T>
T retornaProx(FilaDup<T> fila){
    if(ehvazia(fila)){
        throw("FILA VAZIA");
    }
    Nodo<T> *maiorPrio = fila.inicio; 
    Nodo<T> *atual = fila.inicio->prox; 
    while(atual != nullptr) {
        if(atual->prio < maiorPrio->prio) { 
            maiorPrio = atual;
        }
        atual = atual->prox; 
    }
    return maiorPrio->elem;
}

#endif // FILADUPLAMENTEENCADEADA_H
