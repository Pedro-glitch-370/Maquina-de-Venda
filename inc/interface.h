#ifndef MAQUINA_DE_VENDA_INTERFACE_H
#define MAQUINA_DE_VENDA_INTERFACE_H
#include "../inc/caixa.h"
#include "../inc/conta.h"
#include "../inc/pagamentocartao.h"
#include <string>
#include <iostream>
using namespace std;

//metodo unico para simular a fala da Mettatton
void falar(const string& texto, int delay_caractere, int delay_final);

//mensagens predefinidas
void mensagemInicial();
void primeiraMsgADM();
void primeiraMsgUser();
void interfaceADM(const Caixa& fluxoDeCaixa);
void interfaceUser(const Conta& contaUsuario);
void formaPagamento();
void pagarComOuro();
void pagarComCartao();
void explicar1();
void explicar2();

#endif //MAQUINA_DE_VENDA_INTERFACE_H