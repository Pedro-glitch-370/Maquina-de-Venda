#include "../inc/interface.h"
#include "../inc/caixa.h"
#include "../inc/conta.h"
#include <iostream>
#include <thread> //pro delay dos caracteres
#include <chrono> //pro delay dos caracteres
#include <string>
using namespace std;

void delay(const int milissegundos) {
    this_thread::sleep_for(chrono::milliseconds(milissegundos));
}

//metodo unico para simular a fala da Mettatton
void falar(const string& texto, const int delay_caractere, const int delay_final) {
    //imprime caractere e aguarda
    for (const char c : texto) {
        cout << c << flush;
        delay(delay_caractere);
    }

    //pula linha e aguarda
    cout << endl;
    delay(delay_final);
}

void msgInicial() {
    falar("Bem-vindos, queridos, a maquina de vendas mais glamourosa de todo o subsolo!!", 30, 100);
    falar("Voce eh ADM (1) ou um usuario qualquer (2)?", 30, 15);
}

int invalidoUmOuDois(int entrada) {
    while (entrada != 1 and entrada != 2) {
        falar("Entrada invalida! Digite apenas 1 ou 2, darling! Nao eh dificil!", 30, 15);
        cin >> entrada;
    }
    return entrada;
}

void primeiraMsgADM() {
    falar("Ohh, um ADM! Um Assistente totalmente Dependente de Mim!!! Eh um prazer ter um de voces aqui!", 30, 100);
    falar("Mas antes, preciso saber se voce nao esta mentindo!!", 30, 15);
}

void segundaMsgADM(const int seletor) {
    if (seletor == 1) {
        falar("Digite seu login:", 30, 15);
    } else if (seletor == 2) {
        falar("Digite a senha:", 30, 15);
    } else if (seletor == 3) {
        falar("Eh voce mesmo!! Bom te ver de novo!", 30, 15);
    } else if (seletor == 4) {
        falar("Senha errada, darling! Digite novamente!", 15, 15);
    }
}

void primeiraMsgUser() {
    falar("Oh! Mais um fan!!! Quer que eu explique como funciona essa belezinha?", 30, 15);
    falar("Sim (1) ou Nao (2)?", 30, 10);
}

void interfaceADM(Caixa& fluxoDeCaixa) {
    cout << "------------------------------------" << endl;
    falar("O que deseja fazer, estrela?", 30, 15);
    cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << endl;
    cout << "Pressione 1 pra adicionar produto" << endl;
    cout << "Pressione 2 pra retirar produto" << endl;
    cout << "Pressione 3 pra ver os produtos" << endl;
    cout << "Pressione 4 pra acessar o fluxo de caixa" << endl;
    //cout << "Pressione 5 pra alterar a senha da maquina" << endl;
    cout << "------------------------------------" << endl;
    cout << "Pressione 0 pra sair" << endl;
    cout << "------------------------------------" << endl;
}

void interfaceUser(Conta& contaUsuario) {
    cout << "------------------------------------" << endl;
    falar("O que deseja fazer agora, estrela?", 30, 15);
    cout << "Saldo atual: " << contaUsuario.getSaldo() << endl;
    cout << "Pressione 1 pra ver nossos produtos" << endl;
    cout << "Pressione 2 para comprar um produto" << endl;
    cout << "------------------------------------" << endl;
    cout << "Pressione 9 pra acessar o saldo" << endl;
    cout << "Pressione 0 pra sair" << endl;
    cout << "------------------------------------" << endl;
}

void msgExplicar1() {
    falar("Adicione a quantidade de saldo que voce vai usar nas compras. Depois, eh so curtir e torrar!!", 30, 15);
    falar("E nao se preocupe se restar algum valor aqui dentro. Tenho ouro suficiente no caixa para qualquer troco!", 30, 45);
    falar("Agora, insira a quantidade de ouro que voce vai gastar!", 30, 15);
}

void msgExplicar2() {
    falar("Hunf, ta bom.", 30, 35);
    falar("E quanto de ouro voce vai gastar agora, meu bem?", 30, 15);
}

void msgInvalido(const int seletor) {
    if (seletor == 1) {
        falar("Oooops! Entrada invalida! Digite um numero inteiro!", 30, 15);
    } else if (seletor == 2) {
        falar("Oooops! Numero invalido! Digite novamente!", 30, 15);
    } else if (seletor == 3) {
        falar("Oooops! Entrada invalida! Digite um NOME!", 30, 15);
    } else if (seletor == 4) {
        falar("Oooops! Saldo invalido! Digite novamente!", 30, 15);
    } else if (seletor == 5) {
        falar("Oooops! Entrada invalida! Digite um NUMERO!", 30, 15);
    }
}

void msgAddSaldo(const int seletor) {
    if (seletor == 1) {
        falar("Deseja adicionar ao fluxo (1), retirar (2) ou retornar (3)?", 30, 15);
    } else if (seletor == 2) {
        falar("Deseja adicionar saldo (1), retirar saldo (2) ou retornar (3)?", 30, 15);
    }
}

void msgAddProduto(const int seletor) {
    if (seletor == 1) {
        falar("Uhh, novo produto! Me diga tudo sobre ele!", 30, 15);
        falar("Digite o nome:", 30, 15);
    } else if (seletor == 2) {
        falar("Digite o preco:", 30, 15);
    } else if (seletor == 3) {
        falar("Digite a quantidade:", 30, 15);
    } else if (seletor == 4) {
        falar("Ja existe um produto com esse nome!", 30, 25);
        falar("Digite outro nome:", 30, 15);
    }
}

void msgTirarProduto() {
    falar("Ahhh... vai tirar um? Que pena...", 30, 15);
    falar("Digite o nome do produto a ser retirado:", 30, 15);
}

void msgAddOuro() { falar("Quanto de ouro voce deseja adicionar?", 30, 15); }

void msgTirarOuro() { falar("Quanto de ouro voce deseja retirar?", 30, 15); }

void msgComprarProduto() {
    falar("Enfim, as compras! Qual produto voce deseja?", 30, 15);
    falar("Se quiser retornar, escreva Voltar!", 30, 15);
}

void msgDefault() { falar("Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!", 30, 15); }

void msgAteMais() { falar("Ate a proxima, darling! Nao mude de canal!", 30, 15); }