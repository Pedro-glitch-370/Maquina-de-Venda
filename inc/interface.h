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
void mensagemInicial();
int invalidoUmOuDois(int entrada);
void primeiraMsgADM();
void segundaMsgADM(int seletor);
void primeiraMsgUser();
void interfaceADM(Caixa& fluxoDeCaixa);
void interfaceUser(Conta& contaUsuario);
void explicar1();
void explicar2();
void invalido(int seletor);
void msgAddProduto(int seletor);
void msgTirarProduto();
void msgAddOuro();
void msgTirarOuro();
void msgComprarProduto();
void msgDefault();
void ateMais();

#endif //MAQUINA_DE_VENDA_INTERFACE_H