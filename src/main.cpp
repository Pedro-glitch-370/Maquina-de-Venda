#include "../inc/produtos.h"
#include "../inc/conta.h"
#include "../inc/caixa.h"
#include "../inc/interface.h"
#include "../inc/adm.h"
#include <iostream>
using namespace std;

int invalidoUmOuDois(int entrada);

int main() {
    //valores fixos (por ora)
    constexpr int TOTAL_BIPS_METTATON = 9;
    Caixa fluxoDeCaixa(0);

    Produto refri(1, "Refri", 5.00, 6);
    Produto cheetos(2, "Cheetos", 6.75, 6);
    Produto agua(3, "Agua", 2.35, 6);
    Produto fini(4, "Fini", 2.55, 6);

    //comeco
    falar("Bem-vindos, queridas, a maquina de vendas mais glamourosa de todo o subsolo!!", TOTAL_BIPS_METTATON, 20);
    int tipoUsuario;
    falar("Voce eh ADM (1) ou um usuario qualquer (2)?", TOTAL_BIPS_METTATON, 15);
    cin >> tipoUsuario;

    //entrada invalida
    while (tipoUsuario != 1 and tipoUsuario != 2) {
        tipoUsuario = invalidoUmOuDois(tipoUsuario);
    }

    //duas opcoes de usuario
    if (tipoUsuario == 1) {
        //cadastro
        falar("Ohh, um ADM! Um Assistente totalmente Dependente de Mim!!! Eh um prazer ter um de voces aqui!", TOTAL_BIPS_METTATON, 15);
        falar("Mas antes, preciso saber se voce nao esta mentindo!!", TOTAL_BIPS_METTATON, 15);
        string login, senha;
        falar("Digite seu login:", TOTAL_BIPS_METTATON, 10);
        cin >> login;
        falar("Digite a senha:", TOTAL_BIPS_METTATON, 10);
        cin >> senha;

        //entrada invalida
        while (senha != fluxoDeCaixa.getSenha()) {
            falar("Senha errada, Darling! Digite novamente!", TOTAL_BIPS_METTATON, 10);
            cin >> senha;
        }

        Adm voce(login, senha);
        falar("Eh voce mesmo!! Bom te ver de novo!", TOTAL_BIPS_METTATON, 10);

        int resposta;
        bool ativo = true;

        //interface de opcoes para adm
        while (ativo) {
            cout << "------------------------------------" << endl;
            falar("O que deseja fazer, estrela?", TOTAL_BIPS_METTATON, 5);
            cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << endl;
            cout << "Pressione 1 pra adicionar produto" << endl;
            cout << "Pressione 2 pra retirar produto" << endl;
            cout << "Pressione 3 pra ver os produtos" << endl;
            cout << "Pressione 4 pra acessar o fluxo de caixa" << endl;
            cout << "Pressione 5 pra alterar a senha da maquina" << endl;
            cout << "------------------------------------" << endl;
            cout << "Pressione 0 pra sair" << endl;
            cout << "------------------------------------" << endl;

            cin >> resposta;
            switch (resposta) {
                case 1: {
                    //parametros de adicionarProduto
                    int id, qnt;
                    string nome;
                    double preco;

                    //passagem de dados
                    falar("Uhh, novo produto! Me diga tudo sobre ele!", TOTAL_BIPS_METTATON, 5);
                    cout << "ID: ";
                    cin >> id;
                    cout << "Nome: ";
                    cin >> nome;
                    cout << "Preco: ";
                    cin >> preco;
                    cout << "Quantidade: ";
                    cin >> qnt;
                    Adm::adicionarProduto(id, nome, preco, qnt); //Static member accessed through instance - what???
                    break;
                }

                case 2:
                    falar("Ahhh... vai tirar um? Que pena...", TOTAL_BIPS_METTATON, 5);
                    Adm::retirarProduto();
                    break;

                case 3:
                    refri.mostrarDetalhes();
                    cheetos.mostrarDetalhes();
                    agua.mostrarDetalhes();
                    fini.mostrarDetalhes();
                    break;

                case 4: {
                        cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << endl;

                        bool vendo_fluxo = true;
                        while (vendo_fluxo) {
                            falar("Deseja adicionar (1), retirar (2) ou retornar (3)?", TOTAL_BIPS_METTATON, 40);
                            cin >> resposta;

                            while (resposta != 1 and resposta != 2 and resposta != 3) {
                                cout << "Numero invalido. Digite novamente." << endl;
                                cin >> resposta;
                            }

                            switch (resposta) {
                                case 1: {
                                    double adicao;
                                    cout << "Quanto voce deseja adicionar?" << endl;
                                    cin >> adicao;
                                    fluxoDeCaixa.adicionarSaldo(adicao);
                                    cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << endl;
                                    break;
                                }
                                case 2: {
                                    double remocao;
                                    cout << "Quanto voce deseja retirar?" << endl;
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
                    falar("Ate a proxima, darling! Nao mude de canal!", TOTAL_BIPS_METTATON, 50);
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
        falar("Oh! Mais um fan!!! Quer que eu explique como funciona essa belezinha?", TOTAL_BIPS_METTATON, 10);
        cout << "Pressione 1 para Sim" << endl;
        cout << "Pressione 2 para Nao" << endl;
        cin >> explicar;

        while (explicar != 1 and explicar != 2) {
            explicar = invalidoUmOuDois(explicar);
        }

        if (explicar == 1) {
            falar("Adicione a quantidade de saldo que voce vai usar nas compras. Depois, eh so curtir e torrar!!", TOTAL_BIPS_METTATON, 10);
            falar("E nao se preocupe se restar algum valor aqui dentro. Tenho ouro suficiente no caixa para qualquer troco!", TOTAL_BIPS_METTATON, 15);
            falar("Agora, insira o seu saldo:", TOTAL_BIPS_METTATON, 10);
        } else if (explicar == 2) {
            falar("Hunf, ta bom.", TOTAL_BIPS_METTATON, 10);
            falar("Insira o seu saldo entao:", TOTAL_BIPS_METTATON, 10);
        }

        //inserir saldo inicial do usuario
        double valorInicial;
        cin >> valorInicial;

        while(cin.fail()) {
            cout << "Entrada invalida. Por favor, insira um numero (com ou sem casas decimais)." << endl;
            cin >> valorInicial;
        }

        //interface de opcoes para usuario
        Conta contaUsuario(valorInicial);
        int resposta;
        bool ativo = true;

        while (ativo) {
            cout << "------------------------------------" << endl;
            falar("O que deseja fazer agora, estrela?", TOTAL_BIPS_METTATON, 40);
            cout << "Saldo atual: " << contaUsuario.getSaldo() << endl;
            cout << "Pressione 1 pra ver Refri" << endl;
            cout << "Pressione 2 pra ver Cheetos" << endl;
            cout << "Pressione 3 pra ver Agua" << endl;
            cout << "Pressione 4 pra ver Fini" << endl;
            cout << "------------------------------------" << endl;
            cout << "Pressione 9 pra acessar o saldo" << endl;
            cout << "Pressione 0 pra sair" << endl;
            cout << "------------------------------------" << endl;

            cin >> resposta;

            while (resposta != 1 and resposta != 2 and resposta != 3
                and resposta != 4 and resposta != 9 and resposta != 0) {
                cout << "Numero invalido. Digite novamente." << endl;
                cin >> resposta;
            }

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
                        cout << "Seu saldo atual: " << contaUsuario.getSaldo() << "." << endl;

                        bool vendo_saldo = true;
                        while (vendo_saldo) {
                            falar("Deseja adicionar saldo (1), retirar saldo (2) ou retornar (3)?", TOTAL_BIPS_METTATON, 40);
                            cin >> resposta;

                            while (resposta != 1 and resposta != 2 and resposta != 3) {
                                cout << "Numero invalido. Digite novamente." << endl;
                            }

                            switch (resposta) {
                                case 1: {
                                    double adicao;
                                    cout << "Quanto voce deseja adicionar?" << endl;
                                    cin >> adicao;
                                    contaUsuario.adicionarSaldo(adicao);
                                    cout << "Seu saldo atual: " << contaUsuario.getSaldo() << endl;
                                    break;
                                }

                                case 2: {
                                    double remocao;
                                    cout << "Quanto voce deseja retirar?" << endl;
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
                    falar("Ate a proxima, darling! Nao mude de canal!", TOTAL_BIPS_METTATON, 50);
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
    cout << "Entrada invalida. Por favor, digite 1 ou 2." << endl;
    cin >> entrada;
    return entrada;
}