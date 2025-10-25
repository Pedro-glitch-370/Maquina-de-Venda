#ifndef MAQUINA_VENDA_PAGAMENTODINHEIRO_H
#define MAQUINA_VENDA_PAGAMENTODINHEIRO_H

#include "pagamento.h"

class PagamentoDinheiro final : public Pagamento {
    public:
        //sobrescreve inserirDinheiro
        void inserirDinheiro(double valor) override;
};

#endif //MAQUINA_VENDA_PAGAMENTODINHEIRO_H