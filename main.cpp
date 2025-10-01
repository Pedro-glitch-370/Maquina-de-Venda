#include "produto.h"
#include <iostream>
using namespace std;

int main() {
    Produto refri(1, "Refri", 5.0, 6);
    refri.mostrarDetalhes();
    Produto cheetos(2, "Cheetos", 6.7, 3);
    cheetos.mostrarDetalhes();

    return 0;
}
