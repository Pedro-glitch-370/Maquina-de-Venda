#ifndef MAQUINA_DE_VENDA_PRODUTOS_H
#define MAQUINA_DE_VENDA_PRODUTOS_H
#include "../inc/conta.h"
#include "../inc/caixa.h"
#include <iostream>
using namespace std;

class Produto {
    private:
        string nome;
        double preco;
        int qnt;

    public:
        //construtor
        Produto(const string &nome, double preco, int qnt);

        //setters
        void setNome();
        void setPreco();
        void setQnt();

        //getters
        string getNome() const;
        double getPreco() const;
        int getQnt() const;

        //metodo para mostrar atributos do produto
        void mostrarDetalhes() const;

        //metodo para comprar um produto
        static bool comprarProduto(string &nomeProduto, Conta &contaUsuario, Caixa &fluxoDeCaixa);

        //metodo para checar se a quantidade de um produto chegou a 0
        static void tirarSeEsgotado(string &nomeProduto);

        //metodo para checar se ja existe um produto de nome igual
        static bool checarProdutoIgual(const string &nome);

        //metodo para ver produtos
        static void listarProdutos();
};

#endif //MAQUINA_DE_VENDA_PRODUTOS_H