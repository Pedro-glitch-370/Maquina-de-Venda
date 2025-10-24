#include "../inc/maquina.h"
#include <iostream>
using namespace std;

Maquina::Maquina(const double d_saldo) : saldo(d_saldo) {}

void Maquina::setSaldo() {
    this->saldo = saldo;
};

double Maquina::getSaldo() const {
    return saldo;
}

void Maquina::addSaldo(const double adicao) {
    saldo += adicao;
}

void Maquina::subSaldo(const double remocao) {
    saldo -= remocao;
}