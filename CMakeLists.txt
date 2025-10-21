cmake_minimum_required(VERSION 4.0)
project(maquina_venda)

set(CMAKE_CXX_STANDARD 20)

add_executable(maquina_venda src/main.cpp
        src/adm/adm.cpp
        src/usuarios/usuarios.cpp
        src/produtos/produtos.cpp
        src/maquina/maquina.cpp
        src/interface/interface.cpp
)

target_link_libraries(maquina_venda winmm)