#ifndef MAQUINA_VENDA_ENTRADAUSER_H
#define MAQUINA_VENDA_ENTRADAUSER_H
#include "../inc/caixa.h"
#include "../inc/conta.h"

double instrucoes();
void menuUser(Caixa& fluxoDeCaixa, double valorInicial);
void verProdutos();
void comprarProduto(Conta& contaUsuario, Caixa& fluxoDeCaixa);
void verSaldo(Conta& contaUsuario);
void adicionarNoSaldo(Conta& contaUsuario);
void removerDoSaldo(Conta& contaUsuario);

#endif //MAQUINA_VENDA_ENTRADAUSER_H