#include "../inc/usuarios.h"
#include "../inc/produtos.h"
#include "../json/json.hpp"
#include <fstream>
#include <iostream>
using namespace std;
using json = nlohmann::json;

//construtor
Usuario::Usuario(const string &, const string &) {}

//setters
void Usuario::setLogin() {
    this->login = login;
}

void Usuario::setSenha() {
    this->senha = senha;
}

//getters
string Usuario::getLogin() const{
    return login;
}

string Usuario::getSenha() const{
    return senha;
}

void Usuario::listarProdutos() {
    ifstream leitura("../db/produtos.json");
    json j;

    if (!leitura.is_open()) {
        cout << "Erro ao abrir o arquivo de produtos." << endl;
        return;
    }

    leitura >> j;
    leitura.close();

    if (!j.contains("produtos") || !j["produtos"].is_array()) {
        cout << "Nenhum produto disponível." << endl;
        return;
    }

    //a listagem propriamente dita
    cout << "\n=== Produtos Disponiveis ===\n" << endl;

    for (const auto& item : j["produtos"]) {
        Produto produto(
            item["id"],
            item["nome"],
            item["preco"],
            item["quantidade"]
        );
        produto.mostrarDetalhes();
    }

    //size() retorna o numero de elementos do json
    cout << "\nTotal de produtos: " << j["produtos"].size() << endl;
}