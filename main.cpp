#include "produto.h"
#include "maquina.h"
#include "interface.h" 
#include "maquina.cpp"
#include "produto.cpp"
#include "interface.cpp"
#include <iostream>
#include <map>         // Necessário para o std::map
#include <limits>      // Necessário para limpar o buffer de entrada

using namespace std;

// Função auxiliar para limpar o buffer de entrada em caso de erro
void limparBufferEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // --- Configuração dos Bips da Voz ---
    const int TOTAL_BIPS_METTATON = 9;

    // --- Criação do Estoque de Produtos usando um map ---
    map<int, Produto> estoque;
    estoque.insert({1, Produto(1, "Refri", 5.00, 6)});
    estoque.insert({2, Produto(2, "Cheetos", 6.75, 6)});
    estoque.insert({3, Produto(3, "Agua", 2.35, 6)});
    estoque.insert({4, Produto(4, "Fini", 2.55, 6)});

    // --- Início do Programa ---
    falar("Bem-vindos, queridas, a maquina de vendas mais glamourosa de todas!", TOTAL_BIPS_METTATON, 50);

    double valorInicial = 0;
    cout << "\nQuanto voce deseja adicionar ao saldo inicial? G ";
    cin >> valorInicial;
    while(cin.fail()) { // Validação de entrada
        cout << "Entrada invalida. Por favor, insira um numero." << endl;
        limparBufferEntrada();
        cin >> valorInicial;
    }

    Maquina maquina(valorInicial);
    
    int resposta;
    bool ativo = true;

    while (ativo) {
        cout << "\n------------------------------------" << endl;
        falar("O que deseja fazer, estrela?", TOTAL_BIPS_METTATON, 40);
        cout << "Saldo atual: G " << maquina.getSaldo() << endl;
        cout << "--- MENU DE PRODUTOS ---" << endl;

        // Menu é gerado dinamicamente a partir do estoque
        for (auto const& [id, produto] : estoque) {
            cout << "Pressione " << id << " para ver " << produto.getNome() << endl;
        }
        cout << "------------------------" << endl;
        cout << "Pressione 9 para gerenciar seu saldo." << endl;
        cout << "Pressione 0 para sair." << endl;
        cout << "Sua escolha: ";
        cin >> resposta;
        
        if (cin.fail()) {
            cout << "Opcao invalida. Por favor, digite um numero." << endl;
            limparBufferEntrada();
            continue; // Volta para o início do loop
        }

        if (resposta == 0) {
            ativo = false;
            falar("Ate a proxima, darling! Nao mude de canal!", TOTAL_BIPS_METTATON, 50);
        } else if (resposta == 9) {
            // Lógica para gerenciar o saldo
            double valor;
            falar("Deseja adicionar (1) ou retirar (2) saldo?", TOTAL_BIPS_METTATON, 40);
            int sub_resposta;
            cin >> sub_resposta;
            if(sub_resposta == 1) {
                cout << "Quanto deseja adicionar? G ";
                cin >> valor;
                maquina.addSaldo(valor);
            } else if (sub_resposta == 2) {
                cout << "Quanto deseja retirar? G ";
                cin >> valor;
                maquina.subSaldo(valor);
            }
        } else if (estoque.count(resposta)) {
            // .count() verifica se a chave (ID) existe no map
            Produto& produtoSelecionado = estoque.at(resposta); // .at() acessa o produto
            produtoSelecionado.mostrarDetalhes();
            // Aqui você poderia adicionar a lógica de compra do produto
        } else {
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}

