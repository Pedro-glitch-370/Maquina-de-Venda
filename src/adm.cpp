#include "../inc/adm.h"
#include "../inc/produtos.h"
#include <iostream>

using namespace std;

//construtor
Adm::Adm(const string &login, const string &senha) : Usuario(login, senha) {}

//metodo para criar um produto e adicionar
void Adm::adicionarProduto(const int id, const string &nome, const double preco, const int qnt) {
    const auto *produto = new Produto(id, nome, preco, qnt);

    cout << produto->getNome() + " foi adicionado(a)!" <<endl;
}

//metodo para remover um produto existente
void Adm::retirarProduto() {
    cout << "Produto era pra ser retirado. Infelizmente, nao ta implementado ainda." << endl;
}