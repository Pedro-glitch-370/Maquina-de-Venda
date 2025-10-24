#ifndef MAQUINA_VENDA_CAIXA_H
#define MAQUINA_VENDA_CAIXA_H

#include "../inc/maquina.h"
#include <iostream>
using namespace std;

class Caixa : public Maquina {
    public:
        Caixa(double d_saldo);
        void mostrarFluxoCaixa() const;
};

#endif //MAQUINA_VENDA_CAIXA_H