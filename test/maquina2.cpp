#include "../inc/maquina.h"
#include <iostream>
using namespace std;

// construtor
Maquina::Maquina(const double d_saldo) : saldo(d_saldo) {}

// muda o valor do saldo
void Maquina::setSaldo(double novoSaldo) {
    this->saldo = novoSaldo;
}

// getter
double Maquina::getSaldo() const {
    return saldo;
}

// metodo para adicionar quantia ao saldo
void Maquina::adicionarSaldo(const double adicao) {
    saldo += adicao;
}

// metodo para remover quantia do saldo
void Maquina::subtrairSaldo(const double remocao) {
    saldo -= remocao;
}

// calcula e devolve troco ao cliente
void Maquina::devolverTroco(double valorCompra, double valorPago) {
    double troco = valorPago - valorCompra; // diferença entre o que pagou e o preço

    if (troco > 0) {
        if (saldo >= troco) {
            subtrairSaldo(troco); // tira o troco do caixa
            cout << "Devolvendo troco de " << troco << " G ao cliente.\n";
        } else {
            cout << "Erro: Caixa da maquina nao possui troco suficiente!\n";
        }
    } else {
        cout << "Nenhum troco a devolver.\n";
    }
}
