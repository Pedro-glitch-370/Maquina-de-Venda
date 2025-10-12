#include "interface.h" // Inclui a própria declaração para garantir consistência
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <random> // Necessário para gerar números aleatórios
#include <ctime>   // Necessário para a semente do gerador aleatório

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Função auxiliar para garantir que a semente do gerador aleatório
// seja definida apenas uma vez durante a execução do programa.
void inicializarGeradorAleatorio() {
    static bool sementeDefinida = false;
    if (!sementeDefinida) {
        srand(time(0));
        sementeDefinida = true;
    }
}

// A função 'falar' foi modificada.
// Ela não recebe mais um nome de arquivo, mas sim o número total de bips.
void falar(const string& texto, int totalDeBips, int delay, int delay_final) {
    inicializarGeradorAleatorio();

    // Imprime o texto caractere por caractere
    for (char c : texto) {
        // Gera um número aleatório entre 1 e o total de bips disponíveis
        int numeroAleatorio = (rand() % totalDeBips) + 1;

        // Constrói o nome do arquivo de som dinamicamente (ex: "bip1.wav", "bip2.wav", etc.)
        string arquivoSom = "bip" + to_string(numeroAleatorio) + ".wav";

        // Toca o som aleatório escolhido em segundo plano
#ifdef _WIN32
        // A flag SND_NODEFAULT impede o som de "erro" do Windows se o arquivo não for encontrado.
        PlaySound(TEXT(arquivoSom.c_str()), NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
#else
        string comando = "aplay " + arquivoSom + " > /dev/null 2>&1 &";
        system(comando.c_str());
#endif

        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;

    this_thread::sleep_for(chrono::milliseconds(delay_final));
    
    // Para o som que estiver tocando ao final da frase (funciona melhor no Windows)
#ifdef _WIN32
    PlaySound(NULL, 0, 0);
#endif
}

