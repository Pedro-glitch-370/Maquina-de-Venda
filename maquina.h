#ifndef _MAQUINA_
#define _MAQUINA_
#include "produto.h"
#include <iostream>
using namespace std;

class Maquina {
    private:
        // fazer um JSON com os produtos 
        double saldo;
    public:
        Maquina(double i_saldo);

        void setSaldo();
        double getSaldo() const;
        void addSaldo(double adicao);
        void subSaldo(double remocao);

        bool comprarProduto(Produto& produto);
};

#endif