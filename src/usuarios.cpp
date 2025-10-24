#include "../inc/usuarios.h"
#include <iostream>
using namespace std;

Usuario::Usuario(const string &, const string &) {}

void Usuario::setLogin() {
    this->login = login;
}

void Usuario::setSenha() {
    this->senha = senha;
}

string Usuario::getLogin() const{
    return login;
}

string Usuario::getSenha() const{
    return senha;
}