#include "../inc/maquina.h"
#include <iostream>
using namespace std;

//construtor
Maquina::Maquina(const double d_saldo) : saldo(d_saldo) {}

//setter
void Maquina::setSaldo() {
    this->saldo = saldo;
};

//getter
double Maquina::getSaldo() const {
    return saldo;
}

//metodo para adicionar quantia ao saldo
void Maquina::adicionarSaldo(const double adicao) {
    saldo += adicao;
}

//metodo para remover quantia do saldo
void Maquina::subtrairSaldo(const double remocao) {
    saldo -= remocao;
}