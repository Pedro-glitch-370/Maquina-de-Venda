#include "../inc/caixa.h"
#include "../inc/interface.h"
#include "../inc/entradaAdm.h"
#include "../inc/entradaUser.h"
using namespace std;

int main() {
    //selecao do usuario
    Caixa fluxoDeCaixa = Caixa::carregarDoJSON();
    msgInicial();
    const int tipoUsuario = invalidoUmOuDois(lerOpcao({1, 2}));

    //duas rotas possiveis
    if (tipoUsuario == 1) {
        loginADM();
        menuADM(fluxoDeCaixa);
    } else {
        const double valorInicial = instrucoes();
        menuUser(fluxoDeCaixa, valorInicial);
    }
    return 0;
}