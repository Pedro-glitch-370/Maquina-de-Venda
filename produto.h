#ifndef _PRODUTO_H
#define _PRODUTO_H
#include <iostream>
using namespace std;

class Produto {
    private:
        int id;
        string nome;
        double preco;
        int qnt;

    public:
        Produto(int i_id, string i_nome, double i_preco, int i_qnt);

        void setId(int id);
        void setNome(string nome);
        void setPreco(double preco);
        void setQnt(int qnt);

        int getId(int qnt);
        string getNome(string nome);
        double getPreco(double preco);
        int getQnt(int qnt);

        void mostrarDetalhes();
};

#endif