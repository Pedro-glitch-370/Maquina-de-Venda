#include "../inc/conta.h"
#include "../json/json.hpp"
#include <fstream>
#include <iostream>
using namespace std;
using json = nlohmann::json;

//construtor
Conta::Conta(const double saldo) : Maquina(saldo) {}

//getter
double Conta::getSaldo() {
    ifstream leitura("../db/fluxoCaixa.json");
    json j;

    leitura >> j;
    leitura.close();

    return j["cliente"]["Valor Cliente"];
}

//metodo para adicionar valor ao saldo do cliente
void Conta::adicionarSaldo(const double adicao) {
    ifstream leitura("../db/fluxoCaixa.json");
    json j;
    leitura >> j;
    leitura.close();

    double valorAtual = j["cliente"]["Valor Cliente"];
    j["cliente"]["Valor Cliente"] = valorAtual + adicao;

    ofstream escrita("../db/fluxoCaixa.json");
    escrita << j.dump(4);
    escrita.close();

    saldo = valorAtual + adicao;
    cout << adicao << " de ouro foi adicionado no seu saldo!" << endl;
}

//metodo para retirar valor do saldo do cliente
void Conta::subtrairSaldo(const double remocao) {
    cout << "Ainda nao implementado!\n";
}

//metodo para mostrar a quantia do usuario
void Conta::mostrarSaldoConta() {
    cout << "Seu Saldo atual: " << getSaldo() << " G" << endl;
}

//metodo para o usuario poder comprar um produto existente
void Conta::comprarProduto(Produto& produto) {
    if (produto.reduzirEstoque()) {
        const double remocao = produto.getPreco();
        subtrairSaldo(remocao);
    }
}