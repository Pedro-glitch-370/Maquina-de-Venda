#include "../inc/produtos.h"
#include "../inc/conta.h"
#include "../inc/caixa.h"
#include "../inc/interface.h"
#include "../inc/adm.h"
#include "../inc/pagamentodinheiro.h"
#include "../inc/pagamentocartao.h"
#include <iostream>
#include <limits>
using namespace std;

int invalidoUmOuDois(int entrada);

int main() {
    //valores fixos (por ora)
    Caixa fluxoDeCaixa(0);

    //comeco
    mensagemInicial();
    int tipoUsuario;
    cin >> tipoUsuario;
    tipoUsuario = invalidoUmOuDois(tipoUsuario);

    //duas opcoes de usuario
    if (tipoUsuario == 1) {
        //cadastro
        primeiraMsgADM();
        string login, senha;
        falar("Digite seu login:", 30, 15);
        cin >> login;
        falar("Digite a senha:", 30, 15);
        cin >> senha;

        //entrada invalida (a senha eh aa)
        while (senha != fluxoDeCaixa.getSenha()) {
            falar("Senha errada, darling! Digite novamente!", 15, 15);
            cin >> senha;
        }

        //entrada valida confirmada
        Adm adm(login, senha);
        falar("Eh voce mesmo!! Bom te ver de novo!", 30, 15);

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
                    falar("Oooops! Entrada invalida! Digite um numero inteiro!", 30, 15);
                    resposta = -1;
                } else if (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 0) {
                    falar("Oooops! Numero invalido! Digite novamente!", 30, 15);
                }

            } while (resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4 && resposta != 0);

            switch (resposta) {
                case 1: {
                    //parametros de adicionarProduto
                    int qnt;
                    string nome;
                    double preco;

                    //passagem de dados
                    falar("Uhh, novo produto! Me diga tudo sobre ele!", 30, 15);
                    falar("Digite o nome:", 30, 15);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, nome);

                    //entrada invalida
                    do {
                        falar("Ja existe um produto com esse nome!", 30, 25);
                        falar("Digite outro nome:", 30, 15);
                        getline(cin, nome);
                    } while (Produto::checarProdutoIgual(nome));

                    falar("Digite o preco:", 30, 15);
                    cin >> preco;
                    falar("Digite a quantidade:", 30, 15);
                    cin >> qnt;
                    Adm::adicionarProduto(nome, preco, qnt);
                    break;
                }

                case 2: {
                    //paramentro de retirarProduto
                    falar("Ahhh... vai tirar um? Que pena...", 30, 15);
                    falar("Digite o nome do produto a ser retirado:", 30, 15);
                    string produtoARetirar;
                    cin >> produtoARetirar;

                    //entrada invalida
                    while (cin.fail()) {
                        falar("Oooops! Entrada invalida! Digite um NOME!", 30, 15);
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
                                falar("Deseja adicionar (1), retirar (2) ou retornar (3)?", 30, 15);
                                cin >> resposta;

                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    falar("Oooops! Entrada invalida! Digite um numero inteiro!", 30, 15);
                                    resposta = 0; //pra forcar a repeticao
                                } else if (resposta != 1 && resposta != 2 && resposta != 3) {
                                    falar("Oooops! Numero invalido! Digite novamente!", 30, 15);
                                }
                            } while (resposta != 1 && resposta != 2 && resposta != 3);

                            switch (resposta) {
                                case 1: {
                                    double adicao;
                                    falar("Quanto voce deseja adicionar?", 30, 15);
                                    cin >> adicao;
                                    fluxoDeCaixa.adicionarSaldo(adicao);
                                    fluxoDeCaixa.mostrarFluxoCaixa();
                                    break;
                                }
                                case 2: {
                                    double remocao;
                                    falar("Quanto voce deseja retirar?", 30, 15);
                                    cin >> remocao;
                                    fluxoDeCaixa.subtrairSaldo(remocao);
                                    fluxoDeCaixa.mostrarFluxoCaixa();
                                    break;
                                }
                                case 3:
                                    vendo_fluxo = false;
                                    break;
                                default:
                                    falar("Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!", 30, 15);
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
                    falar("Ate a proxima, darling! Nao mude de canal!", 30, 15);
                    ativo = false;
                    break;

                default:
                    falar("Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!", 30, 15);
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
            explicar1();
        } else if (explicar == 2) {
            explicar2();
        }

        double valorInicial;
        cin >> valorInicial;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            falar("Oooops! Entrada invalida! Digite um numero!", 30, 15);
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
                falar("Oooops! Numero invalido! Digite novamente!", 30, 15);
                cin >> resposta;
            }

            switch (resposta) {
                case 1:
                    Usuario::listarProdutos();
                    break;
                case 9: {
                        contaUsuario.mostrarSaldoConta();

                        bool vendo_saldo = true;
                        while (vendo_saldo) {
                            falar("Deseja adicionar saldo (1), retirar saldo (2) ou retornar (3)?", 30, 15);
                            cin >> resposta;

                            while (resposta != 1 and resposta != 2 and resposta != 3) {
                                falar("Oooops! Numero invalido! Digite novamente!", 30, 15);
                                cin >> resposta;
                            }

                            switch (resposta) {
                                case 1: {
                                    falar("Quanto de ouro voce deseja adicionar?", 30, 15);
                                    double adicao;
                                    cin >> adicao;
                                    contaUsuario.adicionarSaldo(adicao);
                                    contaUsuario.mostrarSaldoConta();
                                    break;
                                }

                                case 2: {
                                    double remocao;
                                    falar("Quanto de ouro voce deseja retirar?", 30, 15);
                                    cin >> remocao;
                                    contaUsuario.subtrairSaldo(remocao);
                                    contaUsuario.mostrarSaldoConta();
                                    break;
                                }

                                case 3:
                                    vendo_saldo = false;
                                    break;

                                default:
                                    falar("Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!", 30, 15);
                                    break;
                            }
                        }
                        break;
                    }

                case 0:
                    falar("Ate a proxima, darling! Nao mude de canal!", 30, 15);
                    ativo = false;
                    break;
                default:
                    falar("Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!", 30, 15);
                    break;
            }
        }
    }
    return 0;
}

int invalidoUmOuDois(int entrada) {
    while (entrada != 1 and entrada != 2) {
        falar("Entrada invalida! Digite apenas 1 ou 2, darling! Nao eh dificil!", 30, 15);
        cin >> entrada;
    }
    return entrada;
}