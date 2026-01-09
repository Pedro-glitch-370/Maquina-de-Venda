#include "../inc/entradaUser.h"
#include "../inc/interface.h"
#include "../inc/produtos.h"
#include <limits>

enum OpcaoUser { VER_PRODUTOS = 1, COMPRAR_PRODUTO = 2, SALDO_CONTA = 9, SAIR_USER = 0 };
enum OpcaoSaldo { ADD_SALDO = 1, REMOVER_SALDO = 2, RETORNAR_MENU = 3 };

double instrucoes() {
    //explicacao inicial para o usuario
    int explicar;
    primeiraMsgUser();
    cin >> explicar;
    explicar = invalidoUmOuDois(explicar);

    //entrada valida confirmada
    explicar == 1 ? msgExplicar1() : msgExplicar2();

    //depositar saldo inicial
    double valorInicial;
    cin >> valorInicial;

    while (cin.fail() || valorInicial <= 0) {
        limparEntrada();
        valorInicial <= 0 ? msgInvalido(6) : msgInvalido(5);
        cin >> valorInicial;
    }

    return valorInicial;
}

void menuUser(Caixa& fluxoDeCaixa, const double valorInicial) {
    //interface de opcoes para usuario
    Conta contaUsuario(valorInicial);
    contaUsuario.adicionarSaldo(valorInicial);
    bool ativo = true;

    while (ativo) {
        interfaceUser(contaUsuario);

        switch (lerOpcao({1, 2, 9, 0})) {
            case VER_PRODUTOS:
                verProdutos();
                break;

            case COMPRAR_PRODUTO: {
                comprarProduto(contaUsuario, fluxoDeCaixa);
                break;
            }

            case SALDO_CONTA:
                verSaldo(contaUsuario);
                break;

            case SAIR_USER:
                msgDevolverSaldo(contaUsuario);
                msgAteMais();
                ativo = false;
                break;

            default:
                msgDefault();
                break;
        }
    }
}

void verProdutos() {
    Produto::listarProdutos();
    cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void comprarProduto(Conta& contaUsuario, Caixa& fluxoDeCaixa) {
    msgComprarProduto(1);

    string nomeProduto;
    getline(cin >> ws, nomeProduto);

    //laco enquanto o cliente nao compra ou nao retorna
    while (true) {
        if (nomeProduto == "Voltar") {
            break;
        }

        if (Produto::comprarProduto(nomeProduto, contaUsuario, fluxoDeCaixa)) {
            Produto::tirarSeEsgotado(nomeProduto);
            break;
        }

        msgComprarProduto(2);
        cin >> nomeProduto;
    }
}

void verSaldo(Conta& contaUsuario) {
    contaUsuario.mostrarSaldoConta();
    bool vendo_saldo = true;

    while (vendo_saldo) {
        interfaceSaldo(2);

        switch (lerOpcao({1, 2, 3})) {
            case ADD_SALDO: {
                adicionarNoSaldo(contaUsuario);
                break;
            }

            case REMOVER_SALDO: {
                removerDoSaldo(contaUsuario);
                break;
            }

            case RETORNAR_MENU:
                vendo_saldo = false;
                break;

            default:
                msgDefault();
                break;
        }
    }
}

void adicionarNoSaldo(Conta& contaUsuario) {
    msgAddOuro();
    double adicao;

    while (true) {
        if (!(cin >> adicao)) {
            limparEntrada();
            msgInvalido(5);
            continue;
        }
        if (adicao <= 0) {
            msgInvalido(4);
            continue;
        }
        break;
    }

    contaUsuario.adicionarSaldo(adicao);
    contaUsuario.mostrarSaldoConta();
}

void removerDoSaldo(Conta& contaUsuario) {
    msgTirarOuro();
    double remocao;

    while (true) {
        if (!(cin >> remocao)) {
            limparEntrada();
            msgInvalido(5);
            continue;
        }
        if (remocao <= 0) {
            msgInvalido(2);
            continue;
        }
        break;
    }

    contaUsuario.subtrairSaldo(remocao);
    contaUsuario.mostrarSaldoConta();
}