#include "../inc/conta.h"
#include <iostream>
using namespace std;

Conta::Conta(const double d_saldo) : Maquina(d_saldo) {}

void Conta::mostrarSaldoConta() const {
    cout << "Seu Saldo atual: " << getSaldo() << endl;
}

void Conta::comprarProduto(Produto& produto) {
    if (produto.reduzirEstoque()) {
        const double remocao = produto.getPreco();
        subSaldo(remocao);
    }
}