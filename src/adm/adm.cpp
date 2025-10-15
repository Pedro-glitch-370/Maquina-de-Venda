#include "../../inc/adm/adm.h"
#include "../../inc/produtos/produtos.h"
#include <iostream>

using namespace std;

Adm::Adm(const string &login, const string &senha) : Usuario(login, senha){}

void Adm::adicionarProduto(int i_id, const string &i_nome, double i_preco, int i_qnt){
    Produto* produto = new Produto(i_id, i_nome, i_preco, i_qnt);

    cout << produto->getNome() + " foi adicionado" <<endl;
}