cmake_minimum_required(VERSION 4.0)
project(maquina_venda)

set(CMAKE_CXX_STANDARD 20)

add_executable(maquina_venda src/main.cpp
        src/adm.cpp
        src/usuarios.cpp
        src/produtos.cpp
        src/maquina.cpp
        src/interface.cpp
        src/conta.cpp
        src/caixa.cpp
)

target_link_libraries(maquina_venda winmm)