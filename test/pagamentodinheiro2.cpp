#include "../inc/pagamentodinheiro.h"
#include "../inc/interface.h"
#include <iostream>
using namespace std;

// sobrescreve inserirDinheiro
void PagamentoDinheiro::inserirDinheiro(const double valor) {
    //verifica se o valor eh positivo
    if (valor <= 0) {
        falar("Oooops! Valor invalido!! Deve ser uma quantia positiva, meu bem!", 30, 15);
        return;
    }

    //adicionar o valor ao total pago
    adicionarValor(valor);

    //mensagem de pagamento
    cout << "Voce inseriu " << valor << " G em ouro.\n";
}
