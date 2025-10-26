#ifndef MAQUINA_DE_VENDA_MAQUINA_H
#define MAQUINA_DE_VENDA_MAQUINA_H

#include <iostream>
using namespace std;

class Maquina {
private:
    double saldo; // fluxo de caixa da maquina - adm

public:
    // construtor
    explicit Maquina(double d_saldo);

    // setter
    void setSaldo(double novoSaldo);

    // getter
    double getSaldo() const;

    // metodo para adicionar quantia ao saldo
    void adicionarSaldo(double adicao);

    // metodo para remover quantia do saldo
    void subtrairSaldo(double remocao);

    // metodo para devolver troco ao cliente
    void devolverTroco(double valorCompra, double valorPago);
};

#endif //MAQUINA_DE_VENDA_MAQUINA_H
