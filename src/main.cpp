#include "../inc/produtos.h"
#include "../inc/conta.h"
#include "../inc/caixa.h"
#include "../inc/interface.h"
#include "../inc/adm.h"
#include "../inc/pagamentodinheiro.h"
#include "../inc/pagamentocartao.h"
#include <iostream>
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
            cin >> resposta;
            //entrada invalida
            while (resposta != 1 and resposta != 2 and resposta != 3 and resposta != 4 and resposta != 0) {
                falar("Oooops! Numero invalido! Digite novamente!", 30, 15);
                cin >> resposta;
            }

            switch (resposta) {
                case 1: {
                    //parametros de adicionarProduto
                    int id, qnt;
                    string nome;
                    double preco;

                    //passagem de dados
                    falar("Uhh, novo produto! Me diga tudo sobre ele!", 30, 15);
                    falar("Digite o nome:", 30, 15);
                    cin >> nome;

                    //entrada invalida
                    do {
                        if (Produto::checarProdutoIgual(nome)) {
                            cout << "Ja existe um produto com o nome " << nome << ".\n";
                        }

                        falar("Digite outro nome:", 30, 15);
                        cin >> nome;
                    } while (Produto::checarProdutoIgual(nome));

                    falar("Digite o preco:", 30, 15);
                    cin >> preco;
                    falar("Digite a quantidade:", 30, 15);
                    cin >> qnt;
                    Adm::adicionarProduto(nome, preco, qnt);
                    break;
                }

                case 2: {
                    falar("Ahhh... vai tirar um? Que pena...", 30, 15);
                    string produtoARetirar;
                    cin >> produtoARetirar;

                    while (cin.fail()) {
                        falar("Entrada invalida! Digite novamente!", 30, 15);
                        cin >> produtoARetirar;
                    }
                    Adm::retirarProduto(produtoARetirar);
                    break;
                }

                case 3:
                    /*refri.mostrarDetalhes();
                    cheetos.mostrarDetalhes();
                    agua.mostrarDetalhes();
                    fini.mostrarDetalhes();*/
                    break;

                case 4: {
                        cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << endl;

                        bool vendo_fluxo = true;
                        while (vendo_fluxo) {
                            falar("Deseja adicionar (1), retirar (2) ou retornar (3)?", 30, 15);
                            cin >> resposta;

                            while (resposta != 1 and resposta != 2 and resposta != 3) {
                                falar("Oooops! Numero invalido! Digite novamente!", 30, 15);
                                cin >> resposta;
                            }

                            switch (resposta) {
                                case 1: {
                                    double adicao;
                                    falar("Quanto voce deseja adicionar?", 30, 15);
                                    cin >> adicao;
                                    fluxoDeCaixa.adicionarSaldo(adicao);
                                    cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << endl;
                                    break;
                                }
                                case 2: {
                                    double remocao;
                                    falar("Quanto voce deseja retirar?", 30, 15);
                                    cin >> remocao;
                                    fluxoDeCaixa.subtrairSaldo(remocao);
                                    cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << endl;
                                    break;
                                }
                                case 3:
                                    vendo_fluxo = false;
                                    break;
                                default:
                                    cout << "Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!" << endl;
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
                    cout << "Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!" << endl;
                    break;
            }

        }

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

        //selecao entre formas de pagamento
        int formaInserir;
        cin >> formaInserir;
        formaInserir = invalidoUmOuDois(formaInserir);
        double valorInicial = 0.0;

        //inserir saldo inicial
        if (formaInserir == 1) {
            pagarComOuro();
            cin >> valorInicial;

            PagamentoDinheiro pagOuro;
            pagOuro.inserirDinheiro(valorInicial);

        } else if (formaInserir == 2) {
            falar("Ooohhh! Voce tem um MettaCard?! Abalou!! Vamos estourar o cartao entao!", 30, 15);

            falar("Digite o numero do cartao:", 30, 15);
            int numeroCartao;
            cin >> numeroCartao;

            falar("Digite o nome do titular:", 30, 15);
            string nomeTitular;
            cin >> nomeTitular;

            falar("Tudo cadastrado! Agora, digite a quantidade de saldo a ser inserida:", 30, 15);
            cin >> valorInicial;

            PagamentoCartao pagCartao(numeroCartao, nomeTitular);
            pagCartao.inserirDinheiro(valorInicial);
        }

        //interface de opcoes para usuario
        Conta contaUsuario(valorInicial);
        int resposta;
        bool ativo = true;

        while (ativo) {
            interfaceUser(contaUsuario);
            cin >> resposta;

            //entrada invalida
            while (resposta != 1 and resposta != 2 and resposta != 3
                and resposta != 4 and resposta != 9 and resposta != 0) {
                falar("Oooops! Numero invalido! Digite novamente!", 30, 15);
                cin >> resposta;
            }

            switch (resposta) {
                /*case 1:
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
                    break;*/
                case 9: {
                        cout << "Seu saldo atual: " << contaUsuario.getSaldo() << "." << endl;

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
                                    formaPagamento();
                                    int novaFormaInserir;
                                    cin >> novaFormaInserir;
                                    novaFormaInserir = invalidoUmOuDois(novaFormaInserir);
                                    double adicao = 0.0;

                                    if (novaFormaInserir == 1) {
                                        pagarComOuro();
                                        cin >> adicao;
                                    } else if (novaFormaInserir == 2) {
                                        cin >> adicao;
                                    }

                                    contaUsuario.adicionarSaldo(adicao);
                                    cout << "Seu saldo atual: " << contaUsuario.getSaldo() << endl;
                                    break;
                                }

                                case 2: {
                                    double remocao;
                                    falar("Quanto voce deseja retirar?", 30, 15);
                                    cin >> remocao;
                                    contaUsuario.subtrairSaldo(remocao);
                                    cout << "Seu saldo atual: " << contaUsuario.getSaldo() << endl;
                                    break;
                                }

                                case 3:
                                    vendo_saldo = false;
                                    break;

                                default:
                                    cout << "Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!" << endl;
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
                    cout << "Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!" << endl;
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