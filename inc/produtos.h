#ifndef MAQUINA_DE_VENDA_PRODUTOS_H
#define MAQUINA_DE_VENDA_PRODUTOS_H
#include "conta.h"
#include <iostream>
using namespace std;

class Produto {
    private:
        int id;
        string nome;
        double preco;
        int qnt;

    public:
        //construtor
        Produto(int id, const string &nome, double preco, int qnt);

        //setters
        void setId();
        void setNome();
        void setPreco();
        void setQnt();

        //getters
        int getId() const;
        string getNome() const;
        double getPreco() const;
        int getQnt() const;

        //metodo para mostrar atributos do produto
        void mostrarDetalhes() const;

        //metodo para comprar um produto
        static bool comprarProduto(string &nomeProduto, Conta &contaUsuario);

        //metodo para checar se a quantidade de um produto chegou a 0
        static void tirarSeEsgotado(string &nomeProduto);

        //metodo para checar se ja existe um produto de nome igual
        static bool checarProdutoIgual(const string &nome);
};

#endif //MAQUINA_DE_VENDA_PRODUTOS_H