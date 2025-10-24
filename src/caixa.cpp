#include "../inc/caixa.h"
#include <iostream>
using namespace std;

Caixa::Caixa(const double d_saldo) : Maquina(d_saldo) {}

void Caixa::mostrarFluxoCaixa() const {
    cout << "Fluxo de Caixa atual: " << getSaldo() << endl;
}
