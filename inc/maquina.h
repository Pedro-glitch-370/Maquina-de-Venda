#ifndef MAQUINA_DE_VENDA_MAQUINA_H
#define MAQUINA_DE_VENDA_MAQUINA_H

#include <iostream>
using namespace std;

class Maquina {
    private:
        // fazer um JSON com os produtos
        double saldo;
    public:
        Maquina(double d_saldo);

        void setSaldo();
        double getSaldo() const;
        void addSaldo(double adicao);
        void subSaldo(double remocao);
};

#endif //MAQUINA_DE_VENDA_MAQUINA_H