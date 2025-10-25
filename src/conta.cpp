#include "../inc/conta.h"
#include <iostream>
using namespace std;

//construtor
Conta::Conta(const double saldo) : Maquina(saldo) {}

//metodo para mostrar a quantia do usuario
void Conta::mostrarSaldoConta() const {
    cout << "Seu Saldo atual: " << getSaldo() << " G" << endl;
}

//metodo para o usuario poder comprar um produto existente
void Conta::comprarProduto(Produto& produto) {
    if (produto.reduzirEstoque()) {
        const double remocao = produto.getPreco();
        subtrairSaldo(remocao);
    }
}