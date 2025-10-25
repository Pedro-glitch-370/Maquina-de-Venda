#ifndef MAQUINA_VENDA_PAGAMENTO_H
#define MAQUINA_VENDA_PAGAMENTO_H

#include <iostream>
using namespace std;

class pagamento {
protected:
    double valorpago; // valor registrado pelo metodo de pagamento

public:
    // construtores
    pagamento() noexcept : valorpago(0.0) {}
    explicit pagamento(double valor) noexcept : valorpago(valor) {} // recebe valor, e guarda

    // subclasse insere modo de pagamento
    virtual void inserirdinheiro(double valor) = 0;

    // devolve o valor para maquina, porque era protegido
    double getvalorpago() const noexcept { return valorPago; }

    // imprime o valor acumulado
    void mostrarvalorpago() const {
        std::cout << "Valor pago: R$ " << valorpago << std::endl;
    }

    // destrutor virtual (boa pratica)
    virtual ~pagamento() = default;
};


#endif //MAQUINA_VENDA_PAGAMENTO_H