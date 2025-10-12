#include "maquina.h"
#include <iostream>
using namespace std;

Maquina::Maquina(double i_saldo) : saldo(i_saldo) {};

void Maquina::setSaldo() {
    this->saldo = saldo;
};

double Maquina::getSaldo() const {
    return saldo;
}

void Maquina::addSaldo(double adicao) {
    saldo += adicao;
}

void Maquina::subSaldo(double remocao) {
    saldo -= remocao;
}

bool Maquina::comprarProduto(Produto& produto){
    this->saldo -= produto.getPreco();
    produto.reduzirEstoque();
    return true;
}