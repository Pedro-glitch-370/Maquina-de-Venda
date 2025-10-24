#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <iostream>

class Pagamento {
protected:
    double valorPago; // valor registrado pelo método de pagamento

public:
    // construtores
    Pagamento() noexcept : valorPago(0.0) {}
    explicit Pagamento(double valor) noexcept : valorPago(valor) {} // recebe valor, e guarda

    // subclasse insere modo de pagamento
    virtual void inserirDinheiro(double valor) = 0;

    // devolve o valor para maquina, pq era protegido
    double getValorPago() const noexcept { return valorPago; }

    // imprime o valor acumulado
    void mostrarValorPago() const {
        std::cout << "Valor pago: R$ " << valorPago << std::endl;
    }

    // destrutor virtual (boa pratica)
    virtual ~Pagamento() = default;
};

#endif // PAGAMENTO_H
