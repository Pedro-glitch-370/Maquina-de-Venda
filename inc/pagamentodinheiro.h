#ifndef PAGAMENTO_DINHEIRO //evita mais de uma inclusao
#define PAGAMENTO_DINHEIRO

#include "pagamento.h" //base pagamento

class pagamentodinheiro : public pagamento { // herda de pagamento
public:
// implementa dinheiro sobrescrevendo a bse
    void inserirdinheiro(double valor) override;
};

#endif
