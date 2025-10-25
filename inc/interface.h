#ifndef MAQUINA_DE_VENDA_INTERFACE_H
#define MAQUINA_DE_VENDA_INTERFACE_H
#include <string>
#include <iostream>
using namespace std;

//metodo unico para simular a fala da Mettatton
void falar(const string& texto, int totalDeBips, int delay, int delay_final = 1000);

#endif //MAQUINA_DE_VENDA_INTERFACE_H