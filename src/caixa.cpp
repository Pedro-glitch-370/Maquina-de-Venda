#include "../inc/caixa.h"
#include "../json/json.hpp"
#include "../inc/interface.h"
#include <fstream>
#include <iostream>
using namespace std;
using json = nlohmann::json;

//construtor
Caixa::Caixa(const double saldo) : Maquina(saldo) {}

//getter
double Caixa::getSaldo() {
    ifstream leitura("../db/fluxoCaixa.json");
    json j;

    leitura >> j;
    leitura.close();

    return j["caixa"]["Valor"];
}

//metodo para adicionar valor ao fluxo de caixa
void Caixa::adicionarSaldo(const double adicao) {

    ifstream leitura("../db/fluxoCaixa.json");
    json j;

    leitura >> j;
    leitura.close();

    double valorAtual = j["caixa"]["Valor"];
    j["caixa"]["Valor"] = valorAtual + adicao;

    ofstream escrita("../db/fluxoCaixa.json");
    escrita << j.dump(4);

    escrita.close();

    saldo = valorAtual + adicao;

    cout << adicao << " de ouro adicionado ao caixa!" << endl;
}

//metodo para retirar valor do fluxo de caixa
void Caixa::subtrairSaldo(const double remocao) {

    ifstream leitura("../db/fluxoCaixa.json");
    json j;

    leitura >> j;
    leitura.close();

    double valorAtual = j["caixa"]["Valor"];

    if (valorAtual - remocao < 0) {
        falar("Vai me deixar sem dinheirinho nenhum??? Nao aceito isso!!!", 30, 15);
        return;
    }

    j["caixa"]["Valor"] = valorAtual - remocao;

    ofstream escrita("../db/fluxoCaixa.json");
    escrita << j.dump(4);

    escrita.close();

    cout << "No caixa tem " << valorAtual - remocao << "G" << endl;

    saldo = valorAtual - remocao;
}

//metodo para imprimir a quantia de ouro na maquina
void Caixa::mostrarFluxoCaixa() {
    cout << "Fluxo de Caixa atual: " << getSaldo() << " G" << endl;
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