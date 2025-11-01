#ifdef _WIN32
#include <windows.h>
#endif

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

void delay(const int milissegundos) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milissegundos));
}

//metodo unico para simular a fala da Mettatton
//a implementacao do som foi somente um extra permitido pelo tempo restante disponivel
void falar(const string& texto, const int delay_caractere, const int delay_final) {

    //cria uma unica vez um vetor para armazenar os caminhos dos arquivos de audio
    static std::vector<std::string> arquivosDeSom;
    static std::once_flag init_flag;
    //gerador de numero aleatorio
    static std::mt19937 rng((random_device())());

    //a flag aqui garante que o codigo so ocorra uma vez
    call_once(init_flag, [&] {
        using namespace std::filesystem;

        //vetor com os possiveis caminhos onde a funcao vai procurar os audios
        std::vector<std::string> candidatos = {"./assets", "assets", "build/assets", "./build/assets", "../build/assets"};
        for (const auto &c : candidatos) {
            //cada caminho eh verificado no for each por meio do objeto path
            path p(c);
            if (exists(p) && is_directory(p)) {

                //itera sobre cada item dentro do diretorio encontrado
                for (const auto &item : directory_iterator(p)) {
                    if (item.is_regular_file()) {
                        //pega a extensao do arquivo
                        std::string ext = item.path().extension().string();
                        transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
                        if (ext == ".wav" || ext == ".mp3" || ext == ".ogg") {
                            arquivosDeSom.push_back(item.path().string());
                        }
                    }
                }
            }
            //se ja achou pelo menos um arquivo de som, para a busca
            if (!arquivosDeSom.empty()) break;
        }
    });

    //imprime caractere, toca som aleatorio e aguarda
    for (const char c : texto) {
        std::cout << c << std::flush;

        if (!arquivosDeSom.empty()) {
            //escolhe um arquivo aleatório
            std::uniform_int_distribution<size_t> dist(0, arquivosDeSom.size() - 1);
            std::string choice = arquivosDeSom[dist(rng)];

            thread([choice] {
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
    std::cout << std::endl;
    delay(delay_final);
}

void msgInicial() {
    falar("Bem-vindos, queridos, a maquina de vendas mais glamourosa de todo o subsolo!!", 40, 300);
    falar("Voce eh ADM (1) ou um usuario qualquer (2)?", 60, 100);
}

int invalidoUmOuDois(int entrada) {
    while (std::cin.fail() || (entrada != 1 and entrada != 2)) {
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        falar("Entrada invalida! Digite apenas 1 ou 2, darling! Nao eh dificil!", 60, 100);
        std::cin >> entrada;
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
    std::cout << "------------------------------------" << std::endl;
    falar("O que deseja fazer, estrela?", 60, 100);
    std::cout << "Fluxo de Caixa: " << fluxoDeCaixa.getSaldo() << " G" << std::endl;
    std::cout << "Pressione 1 pra adicionar produto" << std::endl;
    std::cout << "Pressione 2 pra retirar produto" << std::endl;
    std::cout << "Pressione 3 pra ver os produtos" << std::endl;
    std::cout << "Pressione 4 pra alterar a senha da maquina" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Pressione 9 pra acessar o fluxo de caixa" << std::endl;
    std::cout << "Pressione 0 pra sair" << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

void interfaceUser(Conta& contaUsuario) {
    std::cout << "------------------------------------" << std::endl;
    falar("O que deseja fazer agora, estrela?", 60, 100);
    std::cout << "Saldo atual: " << contaUsuario.getSaldo() << " G" << std::endl;
    std::cout << "Pressione 1 pra ver nossos produtos" << std::endl;
    std::cout << "Pressione 2 pra comprar um produto" << std::endl;
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Pressione 9 pra acessar o seu saldo" << std::endl;
    std::cout << "Pressione 0 pra sair" << std::endl;
    std::cout << "------------------------------------" << std::endl;
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
        falar("Ja vai? Ah... Tome de volta seu ouro!", 40, 15);
        std::cout << "Foram devolvidos " << saldoCliente << " G!" << std::endl;
    } else {
        falar("Vejo aqui que voce torrou toda sua grana! Que nunca nos falte o superfluo, nao eh mesmo?", 30, 15);
    }
}

void msgAteMais() { falar("Ate a proxima, darling! Nao mude de canal!", 40, 15); }

void msgPedirSenha() {
    falar("Vai mudar a senha?? Eu gostava da antiga...", 30, 15);
    falar("Mas fiquei curiosa agora! Qual sera a nova senha?", 30, 15);
}