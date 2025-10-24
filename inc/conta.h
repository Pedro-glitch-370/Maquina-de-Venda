#ifndef MAQUINA_VENDA_CONTA_H
#define MAQUINA_VENDA_CONTA_H

#include "../inc/maquina.h"
#include "../inc/produtos.h"
#include <iostream>
using namespace std;

class Conta : public Maquina {
    public:
        Conta(double d_saldo);
        void mostrarSaldoConta() const;
        void comprarProduto(Produto& produto);
};

#endif //MAQUINA_VENDA_CONTA_H