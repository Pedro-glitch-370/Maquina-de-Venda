#ifndef MAQUINA_DE_VENDA_MAQUINA_H
#define MAQUINA_DE_VENDA_MAQUINA_H

#include <iostream>
using namespace std;

class Maquina {
    private:
        // fazer um JSON com os produtos
        double saldo;
    public:
        //construtor
        explicit Maquina(double d_saldo);

        //setter
        void setSaldo();

        //getter
        double getSaldo() const;

        //metodo para adicionar quantia ao saldo
        void adicionarSaldo(double adicao);

        //metodo para remover quantia do saldo
        void subtrairSaldo(double remocao);
};

#endif //MAQUINA_DE_VENDA_MAQUINA_H