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

    ifstream leitura("../db/fluxoCaixa.json");
    json j;
    leitura >> j;
    leitura.close();

    double saldoAtual = j["cliente"]["Valor Cliente"];

    if (remocao > saldoAtual) {
        cout << "Saldo insuficiente para realizar a compra!" << endl;
        return;
    }

    j["cliente"]["Valor Cliente"] = saldoAtual - remocao;

    ofstream escrita("../db/fluxoCaixa.json");
    escrita << j.dump(4);
    escrita.close();

    saldo = saldoAtual - remocao;
}

//metodo para mostrar a quantia do usuario
void Conta::mostrarSaldoConta() { cout << "Seu Saldo atual: " << getSaldo() << " G" << endl; }

//metodo para devolver saldo do cliente para o "mundo real"
double Conta::devolverSaldoConta() {

    ifstream leitura("../db/fluxoCaixa.json");
    json j;
    leitura >> j;
    leitura.close();

    //se tiver valor sobrando, devolve para o cliente
    if (double saldoCliente = j["cliente"]["Valor Cliente"]; saldoCliente > 0) {
        j["cliente"]["Valor Cliente"] = 0.0;

        ofstream escrita("../db/fluxoCaixa.json");
        escrita << j.dump(4);
        escrita.close();

        saldo = 0.0;
        return saldoCliente;
    }
    return 0.0;
}