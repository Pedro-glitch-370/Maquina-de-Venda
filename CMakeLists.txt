cmake_minimum_required(VERSION 4.0)
project(maquina_venda)

set(CMAKE_CXX_STANDARD 20)

add_executable(maquina_venda src/main.cpp
        src/adm.cpp
        src/produtos.cpp
        src/maquina.cpp
        src/interface.cpp
        src/conta.cpp
        src/caixa.cpp
        json/json.hpp
        json/json.hpp
        json/json.hpp
)

if(WIN32)
        # Link with winmm on Windows only
        target_link_libraries(maquina_venda PRIVATE winmm)
endif()