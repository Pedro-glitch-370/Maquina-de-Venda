#ifndef MAQUINA_DE_VENDA_ADM_H
#define MAQUINA_DE_VENDA_ADM_H
#include <iostream>
using namespace std;

class Adm {
    private:
        string login;

    public:
        //construtor
        Adm(const string &login);

        //setter
        void setLogin();

        //getter
        string getLogin() const;

        //metodo para criar um produto e adicionar
        static void adicionarProduto(const string &nome, double preco, int qnt);

        //metodo para remover um produto existente
        static void retirarProduto(const string &nome);

        //metodo para checar o login
        static bool checarLogin(const string &login);

        //metodo para checar a senha
        static bool checarSenha(const string &senha);

        //metodo para alterar senha
        static void alterarSenha(const string &novaSenha);
};

#endif //MAQUINA_DE_VENDA_ADM_H