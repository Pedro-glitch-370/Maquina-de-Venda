#ifndef MAQUINA_DE_VENDA_ADM_H
#define MAQUINA_DE_VENDA_ADM_H

#include "../inc/usuarios.h" //inclui base usuario
#include <iostream>
using namespace std;

class Adm : public Usuario { //classe adm herda da classe usuario
public:
    // construtor
    Adm(const string &login, const string &senha);

    // metodo para criar e adicionar um produto
    static void adicionarProduto(int id, const string &nome, double preco, int qnt);

    // metodo para remover um produto existente
    static void retirarProduto();
};

#endif // MAQUINA_DE_VENDA_ADM_H
