#include "../inc/pagamento.h"
#include <iostream>
using namespace std;

//construtor default (sem argumentos)
Pagamento::Pagamento() : valorPago(0.0) {}

//construtor com parâmetro que inicializa valorPago
Pagamento::Pagamento(const double valor) : valorPago(valor) {}

//getter
double Pagamento::getValorPago() const {
    return valorPago;
}

//metodo para imprimir o valor acumulado
void Pagamento::mostrarValorPago() const {
    cout << "Valor pago: " << valorPago << " G" << endl;
}

void Pagamento::adicionarValor(const double valor) {
    if (valor > 0) {
        valorPago += valor;
    }
}