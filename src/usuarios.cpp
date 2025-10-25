#include "../inc/usuarios.h"
#include <iostream>
using namespace std;

//construtor
Usuario::Usuario(const string &, const string &) {}

//setters
void Usuario::setLogin() {
    this->login = login;
}

void Usuario::setSenha() {
    this->senha = senha;
}

//getters
string Usuario::getLogin() const{
    return login;
}

string Usuario::getSenha() const{
    return senha;
}