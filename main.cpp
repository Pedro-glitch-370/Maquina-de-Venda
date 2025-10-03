#include "produto.h"
#include <iostream>
using namespace std;

int main() {
    Produto refri(1, "Refri", 5.0, 6);
    refri.mostrarDetalhes();

    cout << "O nome do produto e " << refri.getNome() << endl;
    refri.setNome("Coca");
    cout << "Mas agora eu quero que ele vire " << refri.getNome() << endl;

    return 0;
}