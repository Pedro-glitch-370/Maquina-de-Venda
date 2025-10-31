#include "../inc/produtos.h"
#include "../json/json.hpp"
#include <iomanip> //para deixar a listagem de produtos bonita
#include <fstream>
#include <iostream>
using namespace std;
using json = nlohmann::json;

//construtor
Produto::Produto(const string &nome, const double preco, const int qnt) : nome(nome), preco(preco), qnt(qnt) {}

//setters
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
    cout << "Produto: " << setw(35) << left << nome << endl;
    cout << "Preco: " << fixed << setprecision(2) << preco << " G"
         << "   Estoque: " << setw(5) << qnt << endl;
    cout << "==============================================" << endl;
}

//metodo para comprar um produto
bool Produto::comprarProduto(string &nomeProduto, Conta &contaUsuario, Caixa &fluxoDeCaixa) {

    ifstream leitura("../db/produtos.json");
    json j;
    leitura >> j;
    leitura.close();

    //precaucao
    if (!j.contains("produtos") || !j["produtos"].is_array()) {
        cout << "Operacao invalida." << endl;
        return false;
    }

    //procura pelo produto desejado
    for (auto& item : j["produtos"]) {
        if (item["nome"] == nomeProduto) {
            int estoque = item["quantidade"];
            double preco = item["preco"];

            //caso nao tenha mais unidade do produto (nao ocorre, mas so por precaucao)
            if (estoque <= 0) {
                cout << "Produto sem estoque!" << endl;
                return false;
            }

            //caso o cliente nao tenha dinheiro suficiente
            if (contaUsuario.getSaldo() < preco) {
                cout << "Saldo insuficiente para comprar " << nomeProduto << "." << endl;
                return false;
            }

            item["quantidade"] = estoque - 1;

            ofstream escrita("../db/produtos.json");
            escrita << j.dump(4);
            escrita.close();

            //atualiza o saldo de conta do cliente e o saldo do fluxo de caixa
            contaUsuario.subtrairSaldo(preco);
            fluxoDeCaixa.adicionarSaldo(preco);

            //caso chegue ate aqui, deu tudo certo
            cout << "Compra de " << nomeProduto << " feita com sucesso!!!" << endl;
            return true;
        }
    }

    cout << "Esse produto nao existe." << endl;
    return false;
}

//metodo para checar se a quantidade de um produto chegou a 0
void Produto::tirarSeEsgotado(string &nomeProduto) {

    ifstream leitura("../db/produtos.json");
    json j;
    leitura >> j;
    leitura.close();

    if (!j.contains("produtos") || !j["produtos"].is_array()) {
        return;
    }

    //um for each aqui nao funcionaria porque ele nao da a posicao do elemento
    //por isso, indice aqui eh um iterador que vai apontar para cada produto
    //erase() funciona apenas com um iterador, apagando o apontado
    for (auto indice = j["produtos"].begin(); indice != j["produtos"].end(); ++indice) {
        if ((*indice)["nome"] == nomeProduto && (*indice)["quantidade"] == 0) {
            j["produtos"].erase(indice);
            cout << "Produto '" << nomeProduto << "' removido do estoque por estar esgotado." << endl;
            break;
        }
    }

    ofstream escrita("../db/produtos.json");
    escrita << j.dump(4);
    escrita.close();
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

void Produto::listarProdutos() {
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
    cout << "\n============ Produtos Disponiveis ============" << endl;

    for (const auto& item : j["produtos"]) {
        Produto produto(
            item["nome"],
            item["preco"],
            item["quantidade"]
        );
        produto.mostrarDetalhes();
    }

    //size() retorna o numero de elementos do json
    cout << "Total de produtos: " << j["produtos"].size() << endl;
}
