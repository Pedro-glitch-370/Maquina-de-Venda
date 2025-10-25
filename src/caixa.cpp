#include "../inc/caixa.h"
#include <iostream>
using namespace std;

//construtor
Caixa::Caixa(const double saldo) : Maquina(saldo) {}

//metodo para imprimir a quantia de ouro na maquina
void Caixa::mostrarFluxoCaixa() const {
    cout << "Fluxo de Caixa atual: " << getSaldo() << endl;
}

//setter
void Caixa::setSenha() {
    this->senha = senha;
}

//getter
string Caixa::getSenha() const {
    return senha;
}

/*void mudarSenha(string novaSenha) {
    senha = novaSenha;
}*/