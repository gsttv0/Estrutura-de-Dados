#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H
#include "FilaDuplamenteEncadeada.h"
#include <iostream>

using namespace std;

struct Paciente{
    string nome;
    string condicao;
    int prio;
};

void menu() {
    cout << "----- ATENDIMENTO EMERGENCIA -----" << endl;
    cout << "1. Adicionar paciente a fila" << endl;
    cout << "2. Processar atendimento" << endl;
    cout << "3. Estado da fila" << endl;
    cout << "4. Cancelar um atendimento" << endl;
    cout << "5. Encerrar" << endl << endl;
}

void addPaciente(FilaDup<Paciente>& fila, string nome, string condicao, int prio) {
    Paciente pac;
    pac.nome = nome;
    pac.condicao = condicao;
    pac.prio = prio;
    addFila(fila, pac, prio);
    cout << endl << "Paciente: " << nome << endl;
    cout << "Prioridade: " << prio << endl;
    system("pause");
    system("cls");
}

void mostraEstado(FilaDup<Paciente>& fila) {
    if(ehvazia(fila)) {
        system("cls");
        cout << "Fila ta vazia VIVA O SUS!" << endl;
        system("pause");
        system("cls");
        return;
    }
    system("cls");
    cout << " ---- Pacientes na fila de atendimento: -----" << endl << endl;
    mostraFilaPrioStruct(fila);
    cout << "Tamanho da fila: " << retornaCard(fila) << " pacientes" << endl;
    try {
        cout << "Proximo atendimento: " << retornaProx(fila).nome << endl;
    } catch(...) {}
    
    system("pause");
    system("cls");
}

void procAtend(FilaDup<Paciente>& fila) {
    Paciente pac;
    try{
        pac = retornaProx(fila);
        retiraFila(fila);
    }catch(const char* msg){
        system("cls");
        cout << msg << endl;
        system("pause");
        system("cls");
        return;
    }
    
    int tempAtend;
    switch (pac.prio) {
        case 1: tempAtend = 60; break; // vermelho
        case 2: tempAtend = 45; break; // laranja
        case 3: tempAtend = 30; break; // amarelo
        case 4: tempAtend = 15; break; // verde
        case 5: tempAtend = 5;  break; // azul
        default: tempAtend = 10; break;
    }

    cout << "Atendendo paciente: " << pac.nome << " - (Condicao: " << pac.condicao << ")" << endl;
    cout << "Tempo estimado de atendimento: " << tempAtend << " minutos" << endl << endl;
    cout << "Atendimento de " << pac.nome << " CONCLUIDO!" << endl;
    system("pause");
    system("cls");
}

void executaOp(int op, FilaDup<Paciente>& fila) {
    switch(op) {
        case 1: {
            system("cls");
            string nome, cond;
            int prio;

            cout << "Digite o nome do paciente: " << endl;
            nome = validaString();
            cout << endl;
            cout << "Digite a condicao de saude (doenca): " << endl;
            cond = validaString();
            cout << endl;

            cout << "--Descricao de Riscos--" << endl;
            cout << "1. Vermelho - Grave" << endl;
            cout << "2. Laranja - Levemente Grave" << endl;
            cout << "3. Amarelo - Moderado" << endl;
            cout << "4. Verde - Leve" << endl;
            cout << "5. Azul - Sem Risco" << endl << endl;
            cout << "Digite a prioridade: " << endl;

            do {
                prio = validaInt();
                if (prio < 1 || prio > 5) {
                    cout << "Prioridade invalida! Digite um valor entre 1 e 5." << endl;
                }
            } while (prio < 1 || prio > 5);

            addPaciente(fila,nome,cond,prio);
            break;
        }
        case 2: {
            system("cls");
            procAtend(fila);
            break;
        }
        case 3: {
            system("cls");
            mostraEstado(fila);
            break;
        }
        case 4: {
            system("cls");
            if(ehvazia(fila)){
                cout << "A FILA ESTA VAZIA" << endl;
                system("pause");
                system("cls");
                break;
            }
            string elem;
            cout << "-- REMOCAO DE PACIENTE --" << endl;
            cout << "Digite o nome: ";
            elem = validaString();
            Paciente aux;
            aux.nome = elem;
            try{
                RemovefilaStruct(fila,aux);
                cout << "Paciente " << elem << " REMOVIDO!" << endl;
            }catch(const char* msg){
                cout << msg << endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 5:
            system("cls");
            cout << "SAINDO DO SISTEMA" << endl;
            break;
        default:
            system("cls");
            cout << "Opcao invalida! Tente novamente" << endl;
            system("pause");
            system("cls");
            break;
    }
}

#endif // ATENDIMENTO_H
