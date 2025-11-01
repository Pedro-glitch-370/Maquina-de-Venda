#include "../inc/produtos.h"
#include "../inc/conta.h"
#include "../inc/caixa.h"
#include "../inc/interface.h"
#include "../inc/adm.h"
#include <iostream>
#include <limits>
using namespace std;

int main() {
    //comeco
    Caixa fluxoDeCaixa = Caixa::carregarDoJSON();
    msgInicial();
    int tipoUsuario;
    cin >> tipoUsuario;
    tipoUsuario = invalidoUmOuDois(tipoUsuario);

    //duas opcoes de usuario
    if (tipoUsuario == 1) {
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

        int resposta;
        bool ativo = true;

        //interface de opcoes para adm
        while (ativo) {
            interfaceADM(fluxoDeCaixa);

            //entrada invalida
            //o que ta no ignore descarta o que sobrou do buffer ate encontrar uma \n
            do {
                cin >> resposta;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    msgInvalido(1);
                    resposta = -1;
                } else if (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 9 && resposta != 0) {
                    msgInvalido(2);
                }

            } while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 9 && resposta != 0);

            switch (resposta) {
                //adicionar produtos
                case 1: {
                    int qnt;
                    string nome;
                    double preco;

                    //passagem de dados
                    msgAddProduto(1);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, nome);

                    //entrada invalida
                    do {
                        msgAddProduto(4);
                        getline(cin, nome);
                    } while (Produto::checarProdutoIgual(nome));

                    msgAddProduto(2);
                    cin >> preco;
                    msgAddProduto(3);
                    cin >> qnt;
                    Adm::adicionarProduto(nome, preco, qnt);
                    break;
                }

                //retirar produtos
                case 2: {
                    msgTirarProduto();
                    string produtoARetirar;
                    cin >> produtoARetirar;

                    while (true) {
                        //nao acontece, mas por precaucao
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            msgInvalido(3);
                            continue;
                        }

                        if (Adm::retirarProduto(produtoARetirar)) {
                            break;
                        }

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        msgComprarProduto(3);
                        cin >> produtoARetirar;
                    }
                    break;
                }

                //listar produtos
                case 3:
                    Produto::listarProdutos();
                    break;

                //redefinir senha
                case 4: {
                    string novaSenha;
                    msgPedirSenha();
                    cin >> novaSenha;
                    Adm::alterarSenha(novaSenha);
                    break;
                }

                //acessar fluxo de caixa
                case 9: {
                        fluxoDeCaixa.mostrarFluxoCaixa();

                        bool vendo_fluxo = true;
                        while (vendo_fluxo) {
                            do {
                                msgAddSaldo(1);
                                cin >> resposta;

                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    msgInvalido(1);
                                    resposta = 0; //pra forcar a repeticao
                                } else if (resposta != 1 && resposta != 2 && resposta != 3) {
                                    msgInvalido(2);
                                }
                            } while (resposta != 1 && resposta != 2 && resposta != 3);

                            switch (resposta) {
                                //adicionar ao fluxo
                                case 1: {
                                    double adicao;
                                    msgAddOuro();
                                    cin >> adicao;

                                    while (adicao <= 0) {
                                        msgInvalido(4);
                                    }

                                    fluxoDeCaixa.adicionarSaldo(adicao);
                                    fluxoDeCaixa.mostrarFluxoCaixa();
                                    break;
                                }

                                //retirar do fluxo
                                case 2: {
                                    double remocao;
                                    msgTirarOuro();
                                    cin >> remocao;
                                    fluxoDeCaixa.subtrairSaldo(remocao);
                                    fluxoDeCaixa.mostrarFluxoCaixa();
                                    break;
                                }

                                //retornar a interface principal
                                case 3:
                                    vendo_fluxo = false;
                                    break;

                                //caso algo de muito errado
                                default:
                                    msgDefault();
                                    break;
                            }
                        }
                        break;
                    }

                //sair do programa
                case 0:
                    msgAteMais();
                    ativo = false;
                    break;

                //caso algo de muito errado
                default:
                    msgDefault();
                    break;
            }

        }

    // =================================================================================================================

    } else if (tipoUsuario == 2) {
        //explicacao inicial para o usuario
        int explicar;
        primeiraMsgUser();
        cin >> explicar;
        explicar = invalidoUmOuDois(explicar);

        //entrada valida confirmada
        if (explicar == 1) {
            msgExplicar1();
        } else if (explicar == 2) {
            msgExplicar2();
        }

        //depositar saldo inicial
        double valorInicial;
        cin >> valorInicial;

        while (cin.fail() || valorInicial <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (valorInicial <= 0) {
                msgInvalido(6);
            } else {
                msgInvalido(5);
            }

            cin >> valorInicial;
        }

        //interface de opcoes para usuario
        Conta contaUsuario(valorInicial);
        contaUsuario.adicionarSaldo(valorInicial);
        int resposta;
        bool ativo = true;

        while (ativo) {
            interfaceUser(contaUsuario);

            //entrada invalida
            do {
                cin >> resposta;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    msgInvalido(1);
                    resposta = -1;
                } else if (resposta != 1 && resposta != 2 && resposta != 9 && resposta != 0) {
                    msgInvalido(2);
                }

            } while (resposta != 1 && resposta != 2 && resposta != 9 && resposta != 0);

            switch (resposta) {
                //listar produtos
                case 1:
                    Produto::listarProdutos();
                    break;

                //comprar produto
                case 2: {
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
                    break;
                }

                //acessar saldo da conta
                case 9: {
                        contaUsuario.mostrarSaldoConta();

                        bool vendo_saldo = true;
                        while (vendo_saldo) {
                            do {
                                msgAddSaldo(2);
                                cin >> resposta;

                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    msgInvalido(1);
                                    resposta = 0; //pra forcar a repeticao
                                } else if (resposta != 1 && resposta != 2 && resposta != 3) {
                                    msgInvalido(2);
                                }
                            } while (resposta != 1 && resposta != 2 && resposta != 3);

                            switch (resposta) {
                                //adicionar ao saldo
                                case 1: {
                                    msgAddOuro();
                                    double adicao;
                                    cin >> adicao;

                                    //entrada invalida
                                    do {
                                        if (cin.fail()) {
                                            msgInvalido(1);
                                        } else if (adicao <= 0) {
                                            msgInvalido(2);
                                        }
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin >> adicao;

                                    } while (cin.fail() || adicao <= 0);

                                    contaUsuario.adicionarSaldo(adicao);
                                    contaUsuario.mostrarSaldoConta();
                                    break;
                                }

                                //retirar do saldo
                                case 2: {
                                    double remocao;
                                    msgTirarOuro();
                                    cin >> remocao;

                                    //entrada invalida
                                    do {
                                        if (cin.fail()) {
                                            msgInvalido(1);
                                        } else if (remocao <= 0) {
                                            msgInvalido(2);
                                        }
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cin >> remocao;

                                    } while (cin.fail() || remocao <= 0);

                                    contaUsuario.subtrairSaldo(remocao);
                                    contaUsuario.mostrarSaldoConta();
                                    break;
                                }

                                //retornar a interface principal
                                case 3:
                                    vendo_saldo = false;
                                    break;

                                //caso algo de muito errado
                                default:
                                    msgDefault();
                                    break;
                            }
                        }
                        break;
                    }

                //sair do programa
                case 0:
                    msgDevolverSaldo(contaUsuario);
                    msgAteMais();
                    ativo = false;
                    break;

                //caso algo de muito errado
                default:
                    msgDefault();
                    break;
            }
        }
    }
    return 0;
}