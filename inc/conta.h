#ifndef MAQUINA_VENDA_CONTA_H
#define MAQUINA_VENDA_CONTA_H

#include "../inc/maquina.h"
#include "../inc/produtos.h"
#include <iostream>
using namespace std;

class Conta final : public Maquina {
    public:
        //construtor
        explicit Conta(double saldo);

        //getter
        double getSaldo() override;

        //metodo para adicionar valor ao saldo do cliente
        void adicionarSaldo(double adicao) override;

        //metodo para retirar valor do saldo do cliente
        void subtrairSaldo(double remocao) override;

        //metodo para mostrar a quantia do usuario
        void mostrarSaldoConta();

        //metodo para o usuario poder comprar um produto existente
        void comprarProduto(Produto& produto);
};

#endif //MAQUINA_VENDA_CONTA_H