#ifndef MAQUINA_VENDA_PAGAMENTO_H
#define MAQUINA_VENDA_PAGAMENTO_H

#include <iostream>
using namespace std;

// classe base que representa um pagamento
class Pagamento { 
private:
    double valorPago; //iserido pelo cliente

public:
    // construtor default (sem argumentos)
    Pagamento();

    // construtor com parâmetro que inicializa valorPago
    explicit Pagamento(double valor);

    // metodo virtual que será implementado pelas classes derivadas
    virtual void inserirDinheiro(double valor) = 0;

    // getter
    double getValorPago() const;

    // metodo para imprimir o valor acumulado
    void mostrarValorPago() const;

    // metodo para adicionar quantia em valorPago
    void adicionarValor(double valor);

    // destrutor virtual
    virtual ~Pagamento() = default;
};

#endif //MAQUINA_VENDA_PAGAMENTO_H
