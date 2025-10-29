#include "../inc/adm.h"
#include "../inc/produtos.h"
#include "../json/json.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

//construtor
Adm::Adm(const string &login, const string &senha) : Usuario(login, senha) {}

//metodo para criar um produto e adicionar
void Adm::adicionarProduto(const int id, const string &nome, const double preco, const int qnt) {
    const auto *produto = new Produto(id, nome, preco, qnt);

    ifstream leitura("../db/produtos.json"); //cria um var do tipo ifstream q vai ler e guardar oq ta no arquivo

    json j;
    if (leitura.is_open()) {
        leitura >> j; //agr joga dentro de j e automaticamente transforma em json
    }
    leitura.close();

    j["produtos"].push_back({ //adiciona o novo produto em na variavel json
        {"id", id},
        {"nome", nome},
        {"preco",preco},
        {"quantidade", qnt}
    });

    ofstream escrita("../db/produtos.json"); // cria uma variavel de escrita do tipo ofstream
    escrita << j.dump(4); // pra pular as linhas e deixar tudo organizadinho
    escrita.close();

    cout << produto->getNome() + " foi adicionado(a)!" <<endl;
}

//metodo para remover um produto existente
void Adm::retirarProduto() {
    cout << "Produto era pra ser retirado. Infelizmente, nao ta implementado ainda." << endl;
}