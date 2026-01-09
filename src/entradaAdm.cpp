#include "../inc/entradaAdm.h"
#include "../inc/interface.h"
#include "../inc/adm.h"
#include "../inc/caixa.h"
#include "../inc/produtos.h"
#include <limits>
using namespace std;

enum OpcaoADM { ADD_PRODUTO = 1, REMOVER_PRODUTO = 2, LISTAR_PRODUTOS = 3, ALTERAR_SENHA = 4, FLUXO_CAIXA = 9, SAIR_ADM = 0 };
enum OpcaoFluxo { ADD_FLUXO = 1, REMOVER_FLUXO = 2, RETORNAR_MENU = 3};

void loginADM() {
    //cadastro e checagem dos dados
    primeiraMsgADM();
    string login, senha;

    do {
        segundaMsgADM(1);
        cin >> login;
        segundaMsgADM(2);
        cin >> senha;

        if (Adm::checarLogin(login) && Adm::checarSenha(senha)) {
            //entrada valida confirmada
            Adm adm(login);
            segundaMsgADM(3);
            break;
        }

        if (!Adm::checarLogin(login)) {
            segundaMsgADM(5);
        } else if (!Adm::checarSenha(senha)) {
            segundaMsgADM(4);
        }
    } while (true);
}

void menuADM(Caixa& fluxoDeCaixa) {
    //interface de opcoes para adm
    bool ativo = true;
    while (ativo) {
        interfaceADM(fluxoDeCaixa);

        switch (lerOpcao({1, 2, 3, 4, 9, 0})) {
            case ADD_PRODUTO:
                adicionarProduto();
                break;

            case REMOVER_PRODUTO:
                removerProduto();
                break;

            case LISTAR_PRODUTOS:
                listarProdutos();
                break;

            case ALTERAR_SENHA:
                alterarSenha();
                break;

            case FLUXO_CAIXA:
                acessarFluxoCaixa(fluxoDeCaixa);
                break;

            case SAIR_ADM:
                msgAteMais();
                ativo = false;
                break;

            default:
                msgDefault();
                break;
        }

    }
}

void adicionarProduto() {
    int qnt;
    string produtoAAdicionar;
    double preco;

    //passagem de dados
    msgAddProduto(1);

    do {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, produtoAAdicionar);

        //entrada invalida
        if (Produto::checarProdutoIgual(produtoAAdicionar)) {
            msgAddProduto(4);
        }

    } while (Produto::checarProdutoIgual(produtoAAdicionar));

    msgAddProduto(2);
    cin >> preco;
    msgAddProduto(3);
    cin >> qnt;
    Adm::adicionarProduto(produtoAAdicionar, preco, qnt);
}

void removerProduto() {
    msgTirarProduto();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string produtoARetirar;
    getline(cin, produtoARetirar);

    while (true) {
        //nao acontece, mas por precaucao
        if (cin.fail()) {
            limparEntrada();
            msgInvalido(3);
            continue;
        }

        if (produtoARetirar == "Voltar") {
            break;
        }

        if (Adm::retirarProduto(produtoARetirar)) {
            break;
        }

        limparEntrada();
        msgComprarProduto(3);
        getline(cin, produtoARetirar);
    }
}

void listarProdutos() {
    Produto::listarProdutos();
    cin.get();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void alterarSenha() {
    string novaSenha;
    msgPedirSenha();
    cin >> novaSenha;
    Adm::alterarSenha(novaSenha);
}

void acessarFluxoCaixa(Caixa& fluxoDeCaixa) {
    fluxoDeCaixa.mostrarFluxoCaixa();
    bool vendo_fluxo = true;

    while (vendo_fluxo) {
        interfaceSaldo(1);

        switch (lerOpcao({1, 2, 3})) {
            case ADD_FLUXO:
                adicionarAoFluxo(fluxoDeCaixa);
                break;

            case REMOVER_FLUXO:
                removerDoFluxo(fluxoDeCaixa);
                break;

            case RETORNAR_MENU:
                vendo_fluxo = false;
                break;

            default:
                msgDefault();
                break;
        }
    }
}

void adicionarAoFluxo(Caixa& fluxoDeCaixa) {
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

    fluxoDeCaixa.adicionarSaldo(adicao);
    fluxoDeCaixa.mostrarFluxoCaixa();
}

void removerDoFluxo(Caixa& fluxoDeCaixa) {
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

    fluxoDeCaixa.subtrairSaldo(remocao);
    fluxoDeCaixa.mostrarFluxoCaixa();
}