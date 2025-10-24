#ifndef MAQUINA_VENDA_CAIXA_H
#define MAQUINA_VENDA_CAIXA_H

#include "../inc/maquina.h"
#include <iostream>
using namespace std;

class Caixa : public Maquina {
    private:
        string senha = "ohyeah";
    public:
        Caixa(double saldo);
        void mostrarFluxoCaixa() const;

        void setSenha();
        string getSenha() const;
        //void mudarSenha(string novaSenha);
};

#endif //MAQUINA_VENDA_CAIXA_H