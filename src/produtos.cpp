#include "../inc/produtos.h"
#include "../json/json.hpp"
#include <iomanip> //para deixar a listagem de produtos bonita
#include <fstream>
#include <iostream>
using namespace std;
using json = nlohmann::json;

//construtor
Produto::Produto(const int id, const string &nome, const double preco, const int qnt) : id(id), nome(nome), preco(preco), qnt(qnt) {}

//setters
void Produto::setId() {
    this->id = id;
}

void Produto::setNome() {
    this->nome = nome;
}

void Produto::setPreco() {
    this->preco = preco;
}

void Produto::setQnt() {
    this->qnt = qnt;
}

//getters
int Produto::getId() const {
    return id;
}

string Produto::getNome() const {
    return nome;
}

double Produto::getPreco() const {
    return preco;
}

int Produto::getQnt() const {
    return qnt;
}

//metodo para mostrar atributos do produto
//left: alinha o texto pela esquerda; setw: define o tamanho mínimo de largura; fixed: define as casas decimais
void Produto::mostrarDetalhes() const {
    cout << left << setw(6) << "ID:" << id
         << " | " << setw(10) << "Nome:" << nome << endl;
    cout << left << setw(6) << "Preco:" << fixed << setprecision(2) << preco
         << " | " << setw(12) << "Quantidade:" << qnt << endl;
    cout << "------------------------------------" << endl;
}

//metodo para retirar um produto do estoque
bool Produto::reduzirEstoque() {
    if (qnt > 0) {
        qnt--;
        return true;
    }
    return false;
}

//metodo para checar se ja existe um produto de nome igual
bool Produto::checarProdutoIgual(const string &nome) {
    ifstream leitura("../db/produtos.json");
    json j;

    if (leitura.is_open()) {
        leitura >> j;
    }
    leitura.close();

    if (j.contains("produtos") && j["produtos"].is_array()) {
        for (const auto& produto : j["produtos"]) {
            if (produto["nome"] == nome) {
                return true;
            }
        }
    }
    return false;
}
