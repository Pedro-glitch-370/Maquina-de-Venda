#include "../../inc/interface/interface.h"
#include <iostream> //pro cout
#include <thread> //pro delay dos caracteres
#include <chrono> //pro delay dos caracteres
#include <cstdlib> //traz as duas de baixo? Não acho que precise
#include <random> //pros números aleatórios
#include <ctime> //para semente do random

#ifdef _WIN32 //se for no windows
#include <windows.h> //necessário para tocar som
#endif

using namespace std;

void inicializarGeradorAleatorio() {
    //mantém o valor de sementeDefinida entre as chamadas da função
    static bool sementeDefinida = false;

    //srand é chamado apenas uma vez
    if (!sementeDefinida) {
        srand(time(0));
        sementeDefinida = true;
    }
}

//basicamente o nosso registro de tela
void falar(const string& texto, int totalDeBips, int delay, int delay_final) {
    inicializarGeradorAleatorio();

    for (char c : texto) {
        //gera um número entre 1 e o total de bips e cria o nome do arquivo de som
        int numeroAleatorio = (rand() % totalDeBips) + 1;
        string arquivoSom = "bip" + to_string(numeroAleatorio) + ".wav";

#ifdef _WIN32 //requisitos especiais pro sistema operacional usado
        PlaySound(TEXT(arquivoSom.c_str()), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
#else
        string comando = "aplay " + arquivoSom + " > /dev/null 2>&1 &";
        system(comando.c_str());
#endif

        //imprime e espera o delay
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }

    //pula a linha dps de acabar e espera o delay
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(delay_final));

//para qualquer som que ainda esteja tocando no windows
#ifdef _WIN32
    PlaySound(NULL, 0, 0);
#endif
}