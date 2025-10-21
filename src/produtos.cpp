#include "../inc/produtos.h"
#include <iostream>
using namespace std;

Produto::Produto(int i_id, const string &i_nome, double i_preco, int i_qnt) : id(i_id), nome(i_nome), preco(i_preco), qnt(i_qnt) {}

void Produto::setId(int id) {
    this->id = id;
}

void Produto::setNome(string nome) {
    this->nome = nome;
}

void Produto::setPreco(double preco) {
    this->preco = preco;
}

void Produto::setQnt(int qnt) {
    this->qnt = qnt;
}

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

void Produto::mostrarDetalhes() {
    cout << "------------------------------------" << endl;
    cout << "O produto chama-se " << nome << endl;
    cout << "Seu ID configura-se como " << id << endl;
    cout << "Seu preço possui o valor de " << preco << endl;
    cout << "Restam " << qnt << " para compra" << endl;
    cout << "------------------------------------" << endl;
    cin.get();
}

void Produto::reduzirEstoque() {
    if (qnt > 0) {
        qnt--;
    }
}