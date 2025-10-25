#ifndef MAQUINA_DE_VENDA_ADM_H
#define MAQUINA_DE_VENDA_ADM_H

#include "../inc/usuarios.h"
#include <iostream>
using namespace std;

class Adm : public Usuario {
    public:
        //construtor
        Adm(const string &login, const string &senha);

        //metodo para criar um produto e adicionar
        static void adicionarProduto(int id, const string &nome, double preco, int qnt);

        //metodo para remover um produto existente
        static void retirarProduto();
};

#endif //MAQUINA_DE_VENDA_ADM_H