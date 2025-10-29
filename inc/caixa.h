#ifndef MAQUINA_VENDA_CAIXA_H
#define MAQUINA_VENDA_CAIXA_H

#include "../inc/maquina.h"
#include <iostream>
using namespace std;

class Caixa final : public Maquina {
    private:
        string senha = "aa";

    public:
        //construtor
        explicit Caixa(double saldo);

        //getter
        double getSaldo() override;

        //metodo para adicionar valor ao fluxo de caixa
        void adicionarSaldo(double adicao) override;

        //metodo para retirar valor do fluxo de caixa
        void subtrairSaldo(double remocao) override;

        //metodo para imprimir a quantia de ouro na maquina
        void mostrarFluxoCaixa();

        //setter
        void setSenha();

        //getter
        string getSenha() const;

        //void mudarSenha(string novaSenha);
};

#endif //MAQUINA_VENDA_CAIXA_H