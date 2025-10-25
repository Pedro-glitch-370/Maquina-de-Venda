#include "pagamentocartao.h"
#include <iostream>

//construtor da classe
pagamentocartao::pagamentocartao(const std::string& numero, const std::string& nome)
    : numerocartao(numero), nometitular(nome) {}
// metodo inserir dinheiro
void pagamentocartao::inserirdinheiro(double valor) {
    if (valor <= 0) { //verifica se o valor e positivo
        std::cout << "Valor inválido! O valor deve ser positivo.\n";
        return;
    }

    valorpago += valor; //adiciona o valor ao total pago
    //msg de pagamento
    std::cout << "Pagamento de R$ " << valor << " via cartão.\n"
              << "Titular: " << nometitular << "\n";
}
