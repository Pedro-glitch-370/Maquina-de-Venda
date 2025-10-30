#ifndef MAQUINA_DE_VENDA_INTERFACE_H
#define MAQUINA_DE_VENDA_INTERFACE_H
#include "../inc/caixa.h"
#include "../inc/conta.h"
#include <string>
#include <iostream>
using namespace std;

//metodo unico para simular a fala da Mettatton
void falar(const string& texto, int delay_caractere, int delay_final);

//mensagens predefinidas
void msgInicial();
int invalidoUmOuDois(int entrada);
void primeiraMsgADM();
void segundaMsgADM(int seletor);
void primeiraMsgUser();
void interfaceADM(Caixa &fluxoDeCaixa);
void interfaceUser(Conta &contaUsuario);
void msgExplicar1();
void msgExplicar2();
void msgInvalido(int seletor);
void msgAddSaldo(int seletor);
void msgAddProduto(int seletor);
void msgTirarProduto();
void msgAddOuro();
void msgTirarOuro();
void msgComprarProduto();
void msgDefault();
void msgDevolverSaldo(Conta &contaUsuario);
void msgAteMais();
void msgPedirSenha();

#endif //MAQUINA_DE_VENDA_INTERFACE_H