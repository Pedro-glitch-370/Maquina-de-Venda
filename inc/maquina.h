#ifndef MAQUINA_DE_VENDA_MAQUINA_H
#define MAQUINA_DE_VENDA_MAQUINA_H

#include <iostream>
using namespace std;

class Maquina {
protected:
    // fazer um JSON com os produtos
    double saldo;
public:
    //construtor
    explicit Maquina(double d_saldo);

    //setter
    void setSaldo();

    //getter virtual
    virtual double getSaldo() = 0;

    //metodo virtual para adicionar quantia ao saldo
    virtual void adicionarSaldo(double) = 0;

    //metodo virtual para remover quantia do saldo
    virtual void subtrairSaldo(double) = 0;

    //destrutor
    virtual ~Maquina() = default;
};

#endif //MAQUINA_DE_VENDA_MAQUINA_H