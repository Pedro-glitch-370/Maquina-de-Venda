#include "../inc/interface.h"
#include "../inc/caixa.h"
#include "../inc/conta.h"
#include <iostream>
#include <thread> //pro delay dos caracteres
#include <chrono> //pro delay dos caracteres
#include <string>
#include <random>
#include <filesystem>
#include <vector>
#include <mutex>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

void delay(const int milissegundos) {
    this_thread::sleep_for(chrono::milliseconds(milissegundos));
}

//metodo unico para simular a fala da Mettatton
void falar(const string& texto, const int delay_caractere, const int delay_final) {
    // Inicializa lista de arquivos de audio uma vez (procura em paths comuns)
    static std::vector<std::string> audio_files;
    static std::once_flag init_flag;
    static std::mt19937 rng((std::random_device())());

    std::call_once(init_flag, [&]() {
        using namespace std::filesystem;
        std::vector<std::string> candidates = {"./assets", "assets", "build/assets", "./build/assets", "../build/assets"};
        for (const auto &c : candidates) {
            path p(c);
            if (exists(p) && is_directory(p)) {
                for (const auto &entry : directory_iterator(p)) {
                    if (entry.is_regular_file()) {
                        std::string ext = entry.path().extension().string();
                        std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
                        if (ext == ".wav" || ext == ".mp3" || ext == ".ogg") {
                            audio_files.push_back(entry.path().string());
                        }
                    }
                }
            }
            if (!audio_files.empty()) break;
        }
    });

    //imprime caractere, toca som aleatorio e aguarda
    for (const char c : texto) {
        cout << c << flush;

        if (!audio_files.empty()) {
            // escolhe um arquivo aleatório
            std::uniform_int_distribution<size_t> dist(0, audio_files.size() - 1);
            std::string choice = audio_files[dist(rng)];

            std::thread([choice]() {
#ifdef _WIN32
                PlaySoundA(choice.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
#else
                std::string cmd = "aplay -q \"" + choice + "\" >/dev/null 2>&1 &";
                std::system(cmd.c_str());
#endif
            }).detach();
        }

        delay(delay_caractere);
    }

    //pula linha e aguarda
    cout << endl;
    delay(delay_final);
}

void msgInicial() {
    falar("Bem-vindos, queridos, a maquina de vendas mais glamourosa de todo o subsolo!!", 80, 300);
    falar("Voce eh ADM (1) ou um usuario qualquer (2)?", 60, 100);
}

int invalidoUmOuDois(int entrada) {
    while (cin.fail() || (entrada != 1 and entrada != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        falar("Entrada invalida! Digite apenas 1 ou 2, darling! Nao eh dificil!", 60, 100);
        cin >> entrada;
    }

    return entrada;
}

void primeiraMsgADM() {
    falar("Ohh, um ADM! Um Assistente totalmente Dependente de Mim!!! Eh um prazer ter um de voces aqui!", 80, 300);
    falar("Mas antes, preciso saber se voce nao esta mentindo!!", 60, 100);
}

void segundaMsgADM(const int seletor) {
    if (seletor == 1) {
        falar("Digite seu login:", 60, 100);
    } else if (seletor == 2) {
        falar("Digite a senha:", 60, 100);
    } else if (seletor == 3) {
        falar("Eh voce mesmo!! Bom te ver de novo!", 80, 200);
    } else if (seletor == 4) {
        falar("Senha errada, darling! Digite novamente!", 60, 100);
    } else if (seletor == 5) {
        falar("Que nome eh esse?? Nao consta aqui entre meus admins!!", 80, 200);
    }
}

void primeiraMsgUser() {
    falar("Oh! Mais um fan!!! Quer que eu explique como funciona essa belezinha?", 80, 200);
    falar("Sim (1) ou Nao (2)?", 60, 100);
}

void interfaceADM(Caixa& fluxoDeCaixa) {
    cout << "------------------------------------" << endl;
    falar("O que deseja fazer, estrela?", 60, 100);
    cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << endl;
    cout << "Pressione 1 pra adicionar produto" << endl;
    cout << "Pressione 2 pra retirar produto" << endl;
    cout << "Pressione 3 pra ver os produtos" << endl;
    cout << "Pressione 4 pra alterar a senha da maquina" << endl;
    cout << "------------------------------------" << endl;
    cout << "Pressione 9 pra acessar o fluxo de caixa" << endl;
    cout << "Pressione 0 pra sair" << endl;
    cout << "------------------------------------" << endl;
}

void interfaceUser(Conta& contaUsuario) {
    cout << "------------------------------------" << endl;
    falar("O que deseja fazer agora, estrela?", 60, 100);
    cout << "Saldo atual: " << contaUsuario.getSaldo() << " G" << endl;
    cout << "Pressione 1 pra ver nossos produtos" << endl;
    cout << "Pressione 2 pra comprar um produto" << endl;
    cout << "------------------------------------" << endl;
    cout << "Pressione 9 pra acessar o seu saldo" << endl;
    cout << "Pressione 0 pra sair" << endl;
    cout << "------------------------------------" << endl;
}

void msgExplicar1() {
    falar("Adicione a quantidade de saldo que voce vai usar nas compras. Depois, eh so curtir e torrar!!", 80, 200);
    falar("E nao se preocupe se restar algum valor aqui dentro. Tenho ouro suficiente no caixa para qualquer troco!", 80, 200);
    falar("Agora, insira a quantidade de ouro que voce vai gastar!", 60, 100);
}

void msgExplicar2() {
    falar("Hunf, ta bom.", 60, 100);
    falar("E quanto de ouro voce vai gastar agora, meu bem?", 60, 100);
}

void msgInvalido(const int seletor) {
    if (seletor == 1) {
        falar("Oooops! Entrada invalida! Digite um numero inteiro!", 60, 100);
    } else if (seletor == 2) {
        falar("Oooops! Numero invalido! Digite novamente!", 60, 100);
    } else if (seletor == 3) {
        falar("Oooops! Entrada invalida! Digite um NOME!", 60, 100);
    } else if (seletor == 4) {
        falar("Oooops! Saldo invalido! Digite novamente!", 60, 100);
    } else if (seletor == 5) {
        falar("Oooops! Entrada invalida! Digite um NUMERO!", 60, 100);
    } else if (seletor == 6) {
        falar("Oh! Voce tentou colocar 0 de ouro ou menos?!", 80, 200);
        falar("Com esse saldo, nem uma bala de hortela voce compra, docinho!", 80, 200);
        falar("Digite novamente!", 60, 100);
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
        falar("Porem, se quiser retornar, digite agora Voltar.", 30, 15);
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
    falar("Se quiser retornar, digite Voltar.", 30, 15);
    falar("Se nao, digite o nome do produto a ser retirado:", 30, 15);
}

void msgAddOuro() { falar("Quanto de ouro voce deseja adicionar?", 30, 15); }

void msgTirarOuro() { falar("Quanto de ouro voce deseja retirar?", 30, 15); }

void msgComprarProduto(const int seletor) {
    if (seletor == 1) {
        falar("Enfim, as compras! Qual produto voce deseja?", 30, 15);
        falar("Se quiser retornar, escreva Voltar!", 30, 15);
    } else if (seletor == 2) {
        falar("Digite novamente, meu bem.", 30, 15);
    } else if (seletor == 3) {
        falar("Parece que algo deu errado... Digite novamente! Para retornar, digite Voltar!", 30, 15);
    }
}

void msgDefault() { falar("Darling, nao faco ideia de como voce chegou aqui!\nTe mandando de volta!", 30, 15); }

void msgDevolverSaldo(Conta &contaUsuario) {
    if (const double saldoCliente = contaUsuario.devolverSaldoConta(); saldoCliente > 0) {
        falar("Ja vai? Ah... Tome de volta seu ouro!", 30, 15);
        cout << "Foram devolvidos " << saldoCliente << " G!" << endl;
    } else {
        falar("Vejo aqui que voce torrou toda sua grana! Que nunca nos falte o superfluo, nao eh mesmo?", 30, 15);
    }
}

void msgAteMais() { falar("Ate a proxima, darling! Nao mude de canal!", 30, 15); }

void msgPedirSenha() {
    falar("Vai mudar a senha?? Eu gostava da antiga...", 30, 15);
    falar("Mas fiquei curiosa agora! Qual sera a nova senha?", 30, 15);
}