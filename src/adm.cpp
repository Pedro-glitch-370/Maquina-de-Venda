#include "../inc/adm.h"
#include "../inc/produtos.h"
#include "../json/json.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

//construtor
Adm::Adm(const string &login) : login(login) {}

//setters
void Adm::setLogin() {
    this->login = login;
}

//getters
string Adm::getLogin() const {
    return login;
}

//metodo para criar um produto e adicionar
void Adm::adicionarProduto(const string &nome, const double preco, const int qnt) {
    //cria um var do tipo ifstream que vai ler e guardar o que tá no arquivo
    ifstream leitura("../db/produtos.json");
    json j;

    if (leitura.is_open()) {
        leitura >> j; //joga leitura dentro de j e automaticamente transforma em json
    }
    leitura.close();

    Produto produto(nome, preco, qnt);

    //adiciona o novo produto em na variavel json
    j["produtos"].push_back({
        {"nome", nome},
        {"preco",preco},
        {"quantidade", qnt}
    });

    //cria uma variavel de escrita do tipo ofstream
    ofstream escrita("../db/produtos.json");
    escrita << j.dump(4); //pra pular as linhas e deixar tudo organizadinho
    escrita.close();

    cout << produto.getNome() + " foi adicionado(a)!" << endl;
}

//metodo para remover um produto existente
bool Adm::retirarProduto(const string &nome) {
    //um objeto para ler produtos.json e outro para guardar o conteudo do arquivo
    ifstream leitura("../db/produtos.json");
    json j;

    //se abrir normal, carrega os dados de leitura em j e fecha leitura
    if (leitura.is_open()) {
        leitura >> j;
        leitura.close();
    } else {
        cout << "Erro ao abrir o arquivo de produtos." << endl;
        return false;
    }

    //checa se a chave "produtos" existe e se ela é um array
    if (j.contains("produtos") && j["produtos"].is_array()) {
        bool encontrado = false;
        //cria um novo array sem o produto que vai ser retirado
        json novosProdutos = json::array();

        //procura o produto a ser retirado
        //eh um for each que passeia por cada produto
        for (const auto& produto : j["produtos"]) {
            if (produto["nome"] == nome) {
                encontrado = true;
                cout << "Produto " << nome << " removido com sucesso!" << endl;
                continue; //para pular esse produto
            }
            novosProdutos.push_back(produto); //push_back adiciona objetos em um array
        }

        //se o produto nao for encontrado
        if (!encontrado) {
            cout << "Produto " << nome << " nao encontrado." << endl;
            return false;
        }

        //se o produto for encontrado, ocorre a substituicao dos arrays
        j["produtos"] = novosProdutos;

        ofstream escrita("../db/produtos.json");
        if (escrita.is_open()) {
            escrita << j.dump(4); //aqui serve para identacao
            escrita.close();
            return true;
        }

        //manter esses casos de erro caso, bem, aconteca um erro ne
        cout << "Erro ao salvar o arquivo de produtos." << endl;
        return false;

    }

    cout << "Formato invalido no arquivo JSON." << endl;
    return false;

}

//metodo para checar o login
bool Adm::checarLogin(const string &login) {
    ifstream leitura("../db/admExistentes.json");
    json j;
    leitura >> j;
    leitura.close();

    if (!j.contains("adm") || !j["adm"].is_array()) {
        return false;
    }

    for (const auto& item : j["adm"]) {
        if (item.contains("login") && item["login"] == login) {
            return true;
        }
    }

    return false;
}

//metodo para checar a senha
bool Adm::checarSenha(const string &senha) {

    ifstream leitura("../db/admExistentes.json");
    json j;
    leitura >> j;
    leitura.close();

    return j.contains("senha") && j["senha"] == senha;
}

//metodo para alterar senha
void Adm::alterarSenha(const string &novaSenha) {

    ifstream leitura("../db/admExistentes.json");
    json j;
    leitura >> j;
    leitura.close();

    j["senha"] = novaSenha;
    ofstream escrita("../db/admExistentes.json");
    escrita << j.dump(4);
    escrita.close();
    cout << "Senha alterada com sucesso!" << endl;
}