#include "produto.h"
#include <iostream>
using namespace std;

int main() {
    Produto refri(1, "Refri", 5.00, 6);
    Produto cheetos(2, "Cheetos", 6.75, 6);
    Produto agua(1, "Agua", 2.35, 6);
    Produto fini(1, "Fini", 2.55, 6);
    
    int resposta, saldo;
    bool ativo = true;

    cout << "Bem-vindos a Maquina do Mettaton!!" << endl;
    cout << "Quanto voce deseja adicionar ao saldo?" << endl;
    cin >> saldo;

    cout << "Seu saldo atual: " << saldo << "." << endl;
    cout << "Pressione 1 para ver Refri, 2 para ver Cheetos, 3 para ver Agua, 4 para ver Fini, 5 para acessar o saldo 6 para sair." << endl;
    
    while (ativo) {
        cin >> resposta;
        switch (resposta) {
            case 1:
                refri.mostrarDetalhes();
                break;
            case 2:
                cheetos.mostrarDetalhes();
                break;
            case 3:
                agua.mostrarDetalhes();
                break;
            case 4:
                fini.mostrarDetalhes();
                break;
            case 5:
                cout << "Seu saldo atual: " << saldo << "." << endl;

                bool vendo_saldo = true;
                while (vendo_saldo) {
                    cout << "Pressione 1 para adicionar, 2 para retirar e 3 para voltar." << endl;
                    cin >> resposta;
                    switch (resposta) {
                        case 1:
                            int adicao;
                            cout << "Quanto voce deseja adicionar?" << endl;
                            cin >> adicao;
                            saldo += adicao;
                            cout << "Seu saldo atual: " << saldo << endl;
                            break;
                        case 2:
                            int remocao;
                            cout << "Quanto voce deseja retirar?" << endl;
                            cin >> remocao;
                            saldo -= remocao;
                            cout << "Seu saldo atual: " << saldo << endl;
                            break;
                        case 3:
                            vendo_saldo = false;
                            break;
                        default:
                            cout << "Numero invalido. Digite novamente." << endl;
                    }
                }
            break;

            case 6:
                ativo = false;
                break;
            default:
                cout << "Numero invalido. Digite novamente." << endl;
    }}

    return 0;
}