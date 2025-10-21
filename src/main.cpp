#include "../inc/produtos/produtos.h"
#include "../inc/maquina/maquina.h"
#include "../inc/interface/interface.h"
#include <iostream>
#include <map> //pra std::map
#include <limits> //para limpar o buffer de entrada
using namespace std;

void limparBufferEntrada(); //tentando decifrar isso daqui

int main() {
    const int TOTAL_BIPS_METTATON = 9;

    Produto refri(1, "Refri", 5.00, 6);
    Produto cheetos(2, "Cheetos", 6.75, 6);
    Produto agua(3, "Agua", 2.35, 6);
    Produto fini(4, "Fini", 2.55, 6);

    falar("Bem-vindos, queridas, a maquina de vendas mais glamourosa de todo o subsolo!", TOTAL_BIPS_METTATON, 50);

    //colocar saldo inicial
    double valorInicial;
    cout << "\nQuanto voce deseja adicionar ao saldo inicial?" << endl;
    cin >> valorInicial;

    //garantir que a entrada tá certa (além de tirar a entrada errada)
    while(cin.fail()) {
        cout << "Entrada invalida. Por favor, insira um numero." << endl;
        limparBufferEntrada();
        cin >> valorInicial;
    }
    Maquina saldo(valorInicial);

    int resposta;
    bool ativo = true;

    while (ativo) {
        cout << "\n------------------------------------" << endl;
        falar("O que deseja fazer, estrela?", TOTAL_BIPS_METTATON, 40);
        cout << "Saldo atual: " << saldo.getSaldo() << endl;
        cout << "Pressione 1 pra ver Refri" << endl;
        cout << "Pressione 2 pra ver Cheetos" << endl;
        cout << "Pressione 3 pra ver Agua" << endl;
        cout << "Pressione 4 pra ver Fini" << endl;
        cout << "------------------------------------" << endl;
        cout << "Pressione 9 pra acessar o saldo" << endl;
        cout << "Pressione 0 pra sair" << endl;
        cout << "------------------------------------" << endl;

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
            case 9: {
                    cout << "Seu saldo atual: " << saldo.getSaldo() << "." << endl;

                    bool vendo_saldo = true;
                    while (vendo_saldo) {
                        falar("Deseja adicionar (1) saldo, retirar (2) saldo ou retornar (3)?", TOTAL_BIPS_METTATON, 40);
                        cin >> resposta;
                        switch (resposta) {
                            case 1: {
                                double adicao;
                                cout << "Quanto voce deseja adicionar?" << endl;
                                cin >> adicao;
                                saldo.addSaldo(adicao);
                                cout << "Seu saldo atual: " << saldo.getSaldo() << endl;
                                break;
                            }
                            case 2: {
                                double remocao;
                                cout << "Quanto voce deseja retirar?" << endl;
                                cin >> remocao;
                                saldo.subSaldo(remocao);
                                cout << "Seu saldo atual: " << saldo.getSaldo() << endl;
                                break;
                            }
                            case 3:
                                vendo_saldo = false;
                                break;
                            default:
                                cout << "Numero invalido. Digite novamente." << endl;
                                break;
                        }
                    }
                    break;
                }

            case 0:
                falar("Ate a proxima, darling! Nao mude de canal!", TOTAL_BIPS_METTATON, 50);
                ativo = false;
                break;
            default:
                cout << "Numero invalido. Digite novamente." << endl;
                limparBufferEntrada();
    }}

    return 0;
}

void limparBufferEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}