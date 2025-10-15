cmake_minimum_required(VERSION 3.16)
project(Maquina_de_Venda)

set(CMAKE_CXX_STANDARD 20)

add_executable(maquina_venda
        src/main.cpp
        src/interface/interface.cpp
        src/adm/adm.cpp
        src/usuarios/usuarios.cpp
        src/maquina/maquina.cpp
        src/produtos/produtos.cpp
)

target_include_directories(maquina_venda PRIVATE
        inc
)