#ifndef MAQUINA_VENDA_PAGAMENTOCARTAO_H
#define MAQUINA_VENDA_PAGAMENTOCARTAO_H

#include "pagamento.h"
#include <iostream>
#include <string>
using namespace std;

//declara pagamentocartao, herda de pagamento
class pagamentocartao : public pagamento {
private:
    std::string numerocartao; //armazena numero e titular
    std::string nometitular;

public:
    //construtor, recebe numero e nome
    pagamentocartao(const string& numero, const string& nome);
    // implementa pagamento por cartao
    void inserirdinheiro(double valor) override;
};

#endif //MAQUINA_VENDA_PAGAMENTOCARTAO_H