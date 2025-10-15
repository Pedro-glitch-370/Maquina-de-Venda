//#include "usuario.h"
#include <iostream>
using namespace std;

Usuario::Usuario(const string &i_login, const string &i_senha){}

void Usuario::setLogin(string login){
    this->login = login;
}

void Usuario::setSenha(string senha){
    this->senha = senha;
}

string Usuario::getLogin() const{
    return login;
}

string Usuario::getSenha() const{
    return senha;
}