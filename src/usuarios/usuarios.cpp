#include "../../inc/usuarios/usuarios.h"
#include <iostream>
using namespace std;

Usuario::Usuario(const string &, const string &){}

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