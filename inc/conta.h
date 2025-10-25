#ifndef MAQUINA_VENDA_CONTA_H
#define MAQUINA_VENDA_CONTA_H

#include "../inc/maquina.h"
#include "../inc/produtos.h"
#include <iostream>
using namespace std;

class Conta : public Maquina {
    public:
        //construtor
        explicit Conta(double saldo);

        //metodo para mostrar a quantia do usuario
        void mostrarSaldoConta() const;

        //metodo para o usuario poder comprar um produto existente
        void comprarProduto(Produto& produto);
};

#endif //MAQUINA_VENDA_CONTA_H