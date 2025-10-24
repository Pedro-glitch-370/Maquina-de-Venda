#include "../inc/caixa.h"
#include <iostream>
using namespace std;

Caixa::Caixa(const double saldo) : Maquina(saldo) {}

void Caixa::mostrarFluxoCaixa() const {
    cout << "Fluxo de Caixa atual: " << getSaldo() << endl;
}

void Caixa::setSenha() {
    this->senha = senha;
}

string Caixa::getSenha() const {
    return senha;
}

/*void mudarSenha(string novaSenha) {
    senha = novaSenha;
}*/