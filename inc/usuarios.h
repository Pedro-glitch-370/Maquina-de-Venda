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

        void setLogin();
        void setSenha();
        string getLogin() const;
        string getSenha() const;
};

#endif //MAQUINA_DE_VENDA_USUARIOS_H