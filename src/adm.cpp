#include "../inc/adm.h"
#include "../inc/produtos.h"
#include <iostream>

using namespace std;

Adm::Adm(const string &login, const string &senha) : Usuario(login, senha) {}

void Adm::adicionarProduto(const int id, const string &nome, const double preco, const int qnt) {
    const auto *produto = new Produto(id, nome, preco, qnt);

    cout << produto->getNome() + " foi adicionado" <<endl;
}

void Adm::retirarProduto() {
    cout << "Produto era pra ser retirado. Infelizmente, nao ta implementado ainda." << endl;
}