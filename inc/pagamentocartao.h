#ifndef PAGAMENTO_CARTAO //evita que seja incluido mais de uma vez
#define PAGAMENTO_CARTAO

#include "pagamento.h"
#include <string>

//declara pagamentocartao, herda de pagamento
class pagamentocartao : public pagamento {
private:
    std::string numerocartao; //armazena numero e titular
    std::string nometitular;

public:
//construtor, recebe numero e nome
    pagamentocartao(const std::string& numero, const std::string& nome);
// implementa pagamento por cartao
    void inserirdinheiro(double valor) override;
};

#endif //fim da inclusao
