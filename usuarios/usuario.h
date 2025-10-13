#ifndef _USUARIO_
#define _USUARIO_

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

#endif