#ifndef MAQUINA_DE_VENDA_ADM_H
#define MAQUINA_DE_VENDA_ADM_H

#include "usuarios.h"

#include <iostream>
using namespace std;

class Adm : public Usuario{
    public:
        Adm(const string &login, const string &senha);

        void adicionarProduto(int i_id, const string &i_nome, double i_preco, int i_qnt);
};

#endif //MAQUINA_DE_VENDA_ADM_H