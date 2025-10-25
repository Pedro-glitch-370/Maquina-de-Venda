cmake_minimum_required(VERSION 4.0)
project(maquina_venda)

set(CMAKE_CXX_STANDARD 20)

include_directories(json)

# Arquivos do projeto
add_executable(maquina_venda
        src/main.cpp
        src/adm.cpp
        src/usuarios.cpp
        src/produtos.cpp
        src/maquina.cpp
        src/interface.cpp
        json/json.hpp
)

# Link com bibliotecas
target_link_libraries(maquina_venda winmm)