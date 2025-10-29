#ifndef MAQUINA_VENDA_CAIXA_H
#define MAQUINA_VENDA_CAIXA_H

#include "../inc/maquina.h"
#include <iostream>
using namespace std;

class Caixa : public Maquina {
    private:
        string senha = "aa";

    public:
        //construtor
        explicit Caixa(double saldo);

        //metodo para imprimir a quantia de ouro na maquina
        void mostrarFluxoCaixa() const;

        //setter
        void setSenha();

        //getter
        string getSenha() const;

        //void mudarSenha(string novaSenha);
};

#endif //MAQUINA_VENDA_CAIXA_H