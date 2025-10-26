#ifndef MAQUINA_VENDA_PAGAMENTOCARTAO_H
#define MAQUINA_VENDA_PAGAMENTOCARTAO_H

#include "pagamento.h"
#include <iostream>
#include <string>
using namespace std;

class PagamentoCartao final : public Pagamento {
private:
    int numeroCartao;
    string nomeTitular;

public:
    // construtor
    PagamentoCartao(const int& numero, const string& nome);

    // sobrescreve inserirDinheiro
    void inserirDinheiro(double valor) override;
};

#endif //MAQUINA_VENDA_PAGAMENTOCARTAO_H
