#include "../inc/produtos.h"
#include <iostream>
using namespace std;

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
void Produto::mostrarDetalhes() const {
    cout << "------------------------------------" << endl;
    cout << "ID: " << id << "        | Nome: " << nome << endl;
    cout << "Preco: " << preco << "  | Quantidade: " << qnt << endl;
    cout << "Pressione qualquer tecla para voltar." << endl;
    cin.get();
}

//metodo para retirar um produto do estoque
bool Produto::reduzirEstoque() {
    if (qnt > 0) {
        qnt--;
        return true;
    }
    return false;
}
