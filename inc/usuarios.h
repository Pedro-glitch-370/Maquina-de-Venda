#ifndef MAQUINA_DE_VENDA_USUARIOS_H
#define MAQUINA_DE_VENDA_USUARIOS_H

#include <iostream>
using namespace std;

class Usuario{
    private:
        string login;
        string senha;

    public:
        Usuario(const string &login, const string &senha);

        void setLogin(string login);
        string getLogin() const;

        void setSenha(string senha);
        string getSenha() const;
};

#endif //MAQUINA_DE_VENDA_USUARIOS_H