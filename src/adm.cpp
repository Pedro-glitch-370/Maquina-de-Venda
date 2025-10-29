#include "../inc/adm.h"
#include "../inc/produtos.h"
#include "../json/json.hpp"
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

//construtor
Adm::Adm(const string &login, const string &senha) : Usuario(login, senha) {}

//metodo para manter os ID's dos produtos organizados
int Adm::gerarNovoId() {
    int ultimoId = 0;
    ifstream leitura("../db/id_contador.txt");

    if (leitura.is_open()) {
        leitura >> ultimoId;
        leitura.close();
    }

    int novoId = ultimoId + 1;

    ofstream escrita("../db/id_contador.txt");
    if (escrita.is_open()) {
        escrita << novoId;
        escrita.close();
    }

    return novoId;
}

//metodo para criar um produto e adicionar
void Adm::adicionarProduto(const string &nome, const double preco, const int qnt) {
    //cria um var do tipo ifstream que vai ler e guardar o que tá no arquivo
    ifstream leitura("../db/produtos.json");

    json j;
    if (leitura.is_open()) {
        leitura >> j; //agora joga dentro de j e automaticamente transforma em json
    }
    leitura.close();

    int id = gerarNovoId();
    Produto produto(id, nome, preco, qnt);

    //adiciona o novo produto em na variavel json
    j["produtos"].push_back({
        {"id", id},
        {"nome", nome},
        {"preco",preco},
        {"quantidade", qnt}
    });

    //cria uma variavel de escrita do tipo ofstream
    ofstream escrita("../db/produtos.json");
    escrita << j.dump(4); //pra pular as linhas e deixar tudo organizadinho
    escrita.close();

    cout << produto.getNome() + " foi adicionado(a) com ID " << id << "|" << endl;
}

//metodo para remover um produto existente
void Adm::retirarProduto(const string &nome) {
    //um objeto para ler produtos.json e outro para guardar o conteudo do arquivo
    ifstream leitura("../db/produtos.json");
    json j;

    //se abrir normal, carrega os dados de leitura em j e fecha leitura
    if (leitura.is_open()) {
        leitura >> j;
        leitura.close();
    } else {
        cout << "Erro ao abrir o arquivo de produtos." << endl;
        return;
    }

    bool encontrado = false;

    //checa se a chave "produtos" existe e se ela é um array
    if (j.contains("produtos") && j["produtos"].is_array()) {
        //cria um novo array sem o produto que vai ser retirado
        json novosProdutos = json::array();

        //procura o produto a ser retirado
        for (const auto& produto : j["produtos"]) {
            if (produto["nome"] == nome) {
                encontrado = true;
                cout << "Produto \"" << nome << "\" removido com sucesso!" << endl;
                continue; //para pular esse produto
            }
            novosProdutos.push_back(produto); //push_back adiciona objetos em um array
        }

        //se o produto nao for encontrado
        if (!encontrado) {
            cout << "Produto com ID " << nome << " não encontrado." << endl;
            return;
        }

        //se o produto for encontrado, ocorre a substituicao dos arrays
        j["produtos"] = novosProdutos;

        ofstream escrita("../db/produtos.json");
        if (escrita.is_open()) {
            escrita << j.dump(4); //aqui serve para identacao
            escrita.close();
        } else {
            cout << "Erro ao salvar o arquivo de produtos." << endl;
        }
    } else {
        cout << "Formato inválido no arquivo JSON." << endl;
    }
}