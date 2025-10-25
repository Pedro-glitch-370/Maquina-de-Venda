#ifndef MAQUINA_VENDA_PAGAMENTOCARTAO_H
#define MAQUINA_VENDA_PAGAMENTOCARTAO_H

#include "pagamento.h"
#include <iostream>
#include <string>
using namespace std;

class PagamentoCartao : public Pagamento {
    private:
        string numeroCartao;
        string nomeTitular;

    public:
        //construtor
        PagamentoCartao(const string& numero, const string& nome);

        //sobrescreve inserirDinheiro
        void inserirDinheiro(double valor) override;
};

#endif //MAQUINA_VENDA_PAGAMENTOCARTAO_H