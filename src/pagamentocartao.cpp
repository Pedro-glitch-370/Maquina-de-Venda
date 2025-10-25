#include "../inc/pagamentocartao.h"
#include <iostream>
using namespace std;

//construtor
PagamentoCartao::PagamentoCartao(const string& numero, const string& nome) : numeroCartao(numero), nomeTitular(nome) {}

//sobrescreve inserirDinheiro
void PagamentoCartao::inserirDinheiro(const double valor) {
    //verifica se o valor eh positivo
    if (valor <= 0) {
        cout << "Valor inválido! O valor deve ser positivo.\n";
        return;
    }

    //adicionar o valor ao total pago
    adicionarValor(valor);

    //mensagem de pagamento
    cout << "Pagamento de " << valor << " G via MettaCard.\n"
              << "Titular: " << nomeTitular << "\n";
}