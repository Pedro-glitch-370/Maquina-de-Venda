#ifndef MAQUINA_DE_VENDA_PRODUTOS_H
#define MAQUINA_DE_VENDA_PRODUTOS_H

#include <iostream>
using namespace std;

class Produto {
    private:
        int id;
        string nome;
        double preco;
        int qnt;

    public:
        Produto(int i_id, const string &i_nome, double i_preco, int i_qnt);

        void setId(int id);
        void setNome(string nome);
        void setPreco(double preco);
        void setQnt(int qnt);

        int getId() const;
        string getNome() const;
        double getPreco() const;
        int getQnt() const;

        void mostrarDetalhes();
};

#endif //MAQUINA_DE_VENDA_PRODUTOS_H