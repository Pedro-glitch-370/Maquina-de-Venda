#include "../inc/maquina.h"
#include <iostream>
using namespace std;

//construtor
Maquina::Maquina(const double d_saldo) : saldo(d_saldo) {}

//setter
void Maquina::setSaldo() {
    this->saldo = saldo;
}