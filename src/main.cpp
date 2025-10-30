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
        //cadastro
        primeiraMsgADM();
        string login, senha;
        segundaMsgADM(1);
        cin >> login;
        segundaMsgADM(2);
        cin >> senha;

        //entrada invalida (a senha eh aa)
        while (senha != fluxoDeCaixa.getSenha()) {
            segundaMsgADM(4);
            cin >> senha;
        }

        //entrada valida confirmada
        Adm adm(login, senha);
        segundaMsgADM(3);

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
                } else if (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 0) {
                    msgInvalido(2);
                }

            } while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 0);

            switch (resposta) {
                case 1: {
                    //parametros de adicionarProduto
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

                case 2: {
                    //paramentro de retirarProduto
                    msgTirarProduto();
                    string produtoARetirar;
                    cin >> produtoARetirar;

                    //entrada invalida
                    while (cin.fail()) {
                        msgInvalido(3);
                        cin >> produtoARetirar;
                    }

                    Adm::retirarProduto(produtoARetirar);
                    break;
                }

                case 3:
                    Usuario::listarProdutos();
                    break;

                case 4: {
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
                                case 2: {
                                    double remocao;
                                    msgTirarOuro();
                                    cin >> remocao;
                                    fluxoDeCaixa.subtrairSaldo(remocao);
                                    fluxoDeCaixa.mostrarFluxoCaixa();
                                    break;
                                }
                                case 3:
                                    vendo_fluxo = false;
                                    break;
                                default:
                                    msgDefault();
                                    break;
                            }
                        }
                        break;
                    }

                /*case 5: {
                    string novaSenha;
                    fluxoDeCaixa.mudarSenha(novaSenha);
                    break;
                }*/

                case 0:
                    msgAteMais();
                    ativo = false;
                    break;

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

        double valorInicial;
        cin >> valorInicial;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            msgInvalido(5);
        }

        //interface de opcoes para usuario
        Conta contaUsuario(valorInicial);
        contaUsuario.adicionarSaldo(valorInicial);
        int resposta;
        bool ativo = true;

        while (ativo) {
            interfaceUser(contaUsuario);
            cin >> resposta;

            //entrada invalida
            while (resposta != 1 and resposta != 2 and resposta != 9 and resposta != 0) {
                msgInvalido(2);
                cin >> resposta;
            }

            switch (resposta) {
                case 1:
                    Usuario::listarProdutos();
                    break;

                case 2: {
                    msgComprarProduto();

                    string nomeProduto;
                    getline(cin >> ws, nomeProduto);

                    if (nomeProduto == "Voltar") {
                        break;
                    }

                    //a compra aqui ocorre ja na condicao do if
                    if (Produto::comprarProduto(nomeProduto, contaUsuario, fluxoDeCaixa)) {
                        Produto::tirarSeEsgotado(nomeProduto);
                    }
                    break;
                }

                case 9: {
                        contaUsuario.mostrarSaldoConta();

                        bool vendo_saldo = true;
                        while (vendo_saldo) {
                            msgAddSaldo(2);
                            cin >> resposta;

                            while (resposta != 1 and resposta != 2 and resposta != 3) {
                                msgInvalido(2);
                                cin >> resposta;
                            }

                            switch (resposta) {
                                case 1: {
                                    msgAddOuro();
                                    double adicao;
                                    cin >> adicao;
                                    contaUsuario.adicionarSaldo(adicao);
                                    contaUsuario.mostrarSaldoConta();
                                    break;
                                }

                                case 2: {
                                    double remocao;
                                    msgTirarOuro();
                                    cin >> remocao;
                                    contaUsuario.subtrairSaldo(remocao);
                                    contaUsuario.mostrarSaldoConta();
                                    break;
                                }

                                case 3:
                                    vendo_saldo = false;
                                    break;

                                default:
                                    msgDefault();
                                    break;
                            }
                        }
                        break;
                    }

                case 0:
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
    return 0;
}