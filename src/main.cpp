#include "../inc/produtos.h"
#include "../inc/maquina.h"
#include "../inc/interface.h"
#include "../inc/adm.h"
#include <iostream>
#include <map> //pra std::map
#include <limits> //para limpar o buffer de entrada
using namespace std;

void limparBufferEntrada(); //tentando decifrar isso daqui

int main() {
    constexpr int TOTAL_BIPS_METTATON = 9;
    Maquina fluxo(0);

    Produto refri(1, "Refri", 5.00, 6);
    Produto cheetos(2, "Cheetos", 6.75, 6);
    Produto agua(3, "Agua", 2.35, 6);
    Produto fini(4, "Fini", 2.55, 6);

    //print inicial
    falar("Bem-vindos, queridas, a maquina de vendas mais glamourosa de todo o subsolo!", TOTAL_BIPS_METTATON, 30);

    //definir tipo de usuario
    int tipoUsuario;
    falar("Voce eh ADM (1) ou um usuario normal (2)?", TOTAL_BIPS_METTATON, 15);
    cin >> tipoUsuario;
3
    //entrada invalida
    while (tipoUsuario != 1 and tipoUsuario != 2) {
        cout << "Entrada invalida. Por favor, insira um numero." << endl;
        limparBufferEntrada();
        cin >> tipoUsuario;
    }

    //duas opcoes de usuario
    if (tipoUsuario == 1) {
        //cadastro
        falar("Ohh, ADM! Assistente totalmente Dependente de Mim!!! Eh um prazer te-lo de volta!", TOTAL_BIPS_METTATON, 15);
        falar("Mas antes, preciso saber se eh voce mesmo!!", TOTAL_BIPS_METTATON, 15);

        string login, senha;
        falar("Digite seu login:", TOTAL_BIPS_METTATON, 10);
        cin >> login;
        falar("Digite sua senha:", TOTAL_BIPS_METTATON, 10);
        cin >> senha;

        //entrada invalida
        while (senha != "mettattonehdemais") {
            falar("Senha errada, Darling! Digite novamente!", TOTAL_BIPS_METTATON, 10);
            limparBufferEntrada();
            cin >> senha;
        }

        Adm voce(login, senha);
        falar("Eh voce mesmo!! Bom te ver de novo!", TOTAL_BIPS_METTATON, 10);

        int resposta;
        bool ativo = true;

        //interface de opcoes
        while (ativo) {
            cout << "\n------------------------------------" << endl;
            falar("O que deseja fazer, estrela?", TOTAL_BIPS_METTATON, 5);
            cout << "Fluxo de Caixa: " << fluxo.getSaldo() << endl;
            cout << "Pressione 1 pra adicionar produto" << endl;
            cout << "Pressione 2 pra retirar produto" << endl;
            cout << "Pressione 3 pra ver os produtos" << endl;
            cout << "Pressione 4 pra acessar o fluxo de caixa" << endl;
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
                    voce.adicionarProduto(id, nome, preco, qnt); //Static member accessed through instance - what???
                    break;
                }

                case 2:
                    falar("Ahhh... vai tirar um? Que pena...", TOTAL_BIPS_METTATON, 5);
                    voce.retirarProduto();
                    break;

                case 3:
                    refri.mostrarDetalhes();
                    cheetos.mostrarDetalhes();
                    agua.mostrarDetalhes();
                    fini.mostrarDetalhes();
                    break;

                case 4: {
                        cout << "Fluxo de Caixa: " << fluxo.getSaldo() << endl;

                        bool vendo_fluxo = true;
                        while (vendo_fluxo) {
                            falar("Deseja adicionar (1), retirar (2) ou retornar (3)?", TOTAL_BIPS_METTATON, 40);
                            cin >> resposta;
                            switch (resposta) {
                                case 1: {
                                    double adicao;
                                    cout << "Quanto voce deseja adicionar?" << endl;
                                    cin >> adicao;
                                    fluxo.addSaldo(adicao);
                                    cout << "Fluxo de Caixa: " << fluxo.getSaldo() << endl;
                                    break;
                                }
                                case 2: {
                                    double remocao;
                                    cout << "Quanto voce deseja retirar?" << endl;
                                    cin >> remocao;
                                    fluxo.subSaldo(remocao);
                                    cout << "Fluxo de Caixa: " << fluxo.getSaldo() << endl;
                                    break;
                                }
                                case 3:
                                    vendo_fluxo = false;
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
            }

        }

    } else if (tipoUsuario == 2) {

        //colocar saldo inicial
        double valorInicial;
        falar("Oh! Mais um fan!!! Deixe-me explicar como essa belezinha funciona!!!", TOTAL_BIPS_METTATON, 10);
        falar("Adicione a quantidade de saldo que voce vai usar nas compras. Depois, eh so curtir e torrar!!", TOTAL_BIPS_METTATON, 10);
        falar("E nao se preocupe se restar algum valor aqui dentro. Tenho fluxo suficiente para te dar troco!", TOTAL_BIPS_METTATON, 10);
        falar("Agora, insira o seu saldo:", TOTAL_BIPS_METTATON, 10);
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
            falar("O que deseja fazer agora, estrela?", TOTAL_BIPS_METTATON, 40);
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
                            falar("Deseja adicionar saldo (1), retirar saldo (2) ou retornar (3)?", TOTAL_BIPS_METTATON, 40);
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
            }
        }
    }
    return 0;
}

void limparBufferEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}