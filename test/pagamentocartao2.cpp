#include "../inc/pagamentocartao.h"
#include "../inc/interface.h"
#include <iostream>
using namespace std;

// construtor
PagamentoCartao::PagamentoCartao(const int& numero, const string& nome) : numeroCartao(numero), nomeTitular(nome) {}

// sobrescreve inserirDinheiro
void PagamentoCartao::inserirDinheiro(const double valor) {
    //verifica se o valor e positivo
    if (valor <= 0) {
        falar("Oooops! Valor invalido!! Deve ser uma quantia positiva, meu bem!", 30, 15);
        return;
    }

    adicionarValor(valor);

    cout << "Pagamento de " << valor << " G via MettaCard.\n"
         << "Titular: " << nomeTitular << "\n";
}
