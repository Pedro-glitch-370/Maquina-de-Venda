#include "../inc/pagamentodinheiro.h"
#include <iostream>
using namespace std;

// p registrar pagamento
void pagamentodinheiro::inserirdinheiro(double valor) {
    if (valor <= 0) {
        std::cout << "Valor inválido! Insira um valor positivo.\n";
        return; //sai do metodo sem adicionar
    }

    valorpago += valor; //adiona valor
    std::cout << "Você inseriu R$ " << valor << " em dinheiro.\n"
              << "Total inserido: R$ " << valorpago << "\n";
}