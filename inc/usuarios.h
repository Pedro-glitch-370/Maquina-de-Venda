#ifndef MAQUINA_DE_VENDA_USUARIOS_H
#define MAQUINA_DE_VENDA_USUARIOS_H

#include <iostream>
using namespace std;

class Usuario{
    private:
        string login;
        string senha;

    public:
        //construtor
        Usuario(const string &login, const string &senha);

        //setters
        void setLogin();
        void setSenha();

        //getters
        string getLogin() const;
        string getSenha() const;
};

#endif //MAQUINA_DE_VENDA_USUARIOS_H