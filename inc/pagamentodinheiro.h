#ifndef MAQUINA_VENDA_PAGAMENTODINHEIRO_H
#define MAQUINA_VENDA_PAGAMENTODINHEIRO_H

#include "pagamento.h" //base pagamento

class pagamentodinheiro : public pagamento { // herda de pagamento
public:
    // implementa dinheiro sobrescrevendo a bse
    void inserirdinheiro(double valor) override;
};

#endif //MAQUINA_VENDA_PAGAMENTODINHEIRO_H