#include "../inc/pagamentodinheiro.h"
#include <iostream>
using namespace std;

//sobrescreve inserirDinheiro
void PagamentoDinheiro::inserirDinheiro(double valor) {
    //verifica se o valor eh positivo
    if (valor <= 0) {
        cout << "Valor inválido! Insira um valor positivo.\n";
        return;
    }

    //adicionar o valor ao total pago
    adicionarValor(valor);

    //mensagem de pagamento
    cout << "Você inseriu " << valor << " em ouro.\n"
              << "Total inserido: " << getValorPago() << " G\n";
}