# Máquina de Vendas Mettaton

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![JSON](https://img.shields.io/badge/JSON-Armazenamento-000000?style=for-the-badge&logo=json&logoColor=white)
![Plataforma](https://img.shields.io/badge/Plataforma-Linux%20%7C%20Windows%20%7C%20macOS-0078D6?style=for-the-badge)

## 📋 Visão Geral do Projeto

Sistema avançado de gerenciamento de máquinas de vendas desenvolvido em C++ para a disciplina de Estruturas de Dados Orientadas a Objetos da UFPE. Inspirado no carismático Mettaton de Undertale, o sistema implementa uma suíte completa de operações CRUD com modos de usuário duplos e persistência de dados baseada em JSON.
**OBS**: Rodável tanto no Visual Studio Code quanto no CLion.

<div align="center">
  <img src="https://c.tenor.com/rFfEUaNjtDMAAAAd/tenor.gif" width="30%" height="30%">
</div>

## ✨ Funcionalidades

### 🔐 Sistema de Usuários Duplos
- **Modo Administrador**: Gerenciamento completo do ciclo de vida de produtos
- **Modo Cliente**: Navegação de produtos e operações de compra

### 💾 Gerenciamento de Dados
- Persistência de dados baseada em JSON usando biblioteca nlohmann/json
- Manipulação robusta de arquivos com recuperação de erros
- Acompanhamento de inventário em tempo real

### 🏗️ Arquitetura Orientada a Objetos
- Implementação completa de herança e polimorfismo
- Classes bem definidas com encapsulamento rigoroso

## 🛠️ Tecnologias Utilizadas

- **Linguagem**: C++17
- **Biblioteca JSON**: nlohmann/json
- **Persistência**: Arquivos JSON
- **Paradigma**: Orientação a Objetos Pura

## 📁 Estrutura do Projeto

```
Maquina-de-Venda/
├── db/
│   ├── admExistentes.json
│   ├── fluxoCaixa.json
│   └── products.json
├── inc/
│   ├── admin
│   ├── caixa.h
│   ├── conta.h
│   ├── interface.h
│   ├── maquina.h
│   └── products.h
├── json/
│   └── json.hpp
├── src/
│   ├── adm.cpp
│   ├── caixa.cpp
│   ├── conta.cpp
│   ├── interface.cpp
│   ├── main.cpp
│   ├── maquina.cpp
│   └── products.cpp
├── CMakeLists.txt
└── README.md
```

## 🚀 Instalação e Compilação

### Pré-requisitos
- Compilador C++17 (g++ ou clang++)
- CMake
- Biblioteca nlohmann/json (incluída no projeto)

### Compilação com CMake
```bash
# Clone o repositório
git clone https://github.com/Pedro-glitch-370/Maquina-de-Venda.git
cd Maquina-de-Venda
```

## 💻 Como Usar

### Modo Cliente
1. Selecione "Listar Produtos" para ver o inventário disponível
2. Escolha "Comprar Produto" para realizar uma compra
3. O sistema atualiza automaticamente o estoque

### Modo Administrador
1. Acesse o modo administrador com as credenciais configuradas
2. Gerencie produtos: adicionar, editar, remover
3. Visualize relatórios de vendas e estoque
4. Monitore o fluxo de caixa

## 📊 Estrutura de Dados

### Produtos (db/products.json)
```json
{
    "produtos": [
        {
            "nome": "Sorvete",
            "preco": 4.5,
            "quantidade": 4
        },
        {
            "nome": "Bombom",
            "preco": 4.8,
            "quantidade": 2
        }
    ]
}
```

### Administradores (db/admExistentes.json)
- Gerencia usuários administradores do sistema

### Fluxo de Caixa (db/fluxoCaixa.json)
- Controla o histórico de transações e saldo

## 👥 Autores

- **Pedro-glitch-370**
- **andersoncabrall**
- **ITHALO-FS**  
- **GabrielCarvalhoSI**

## Relatório Oficial do Projeto
- [Link para Relatório (docs)](https://docs.google.com/document/d/1GF5C01rqBJlJBsXLeghznUPUu5SOB7ExUnj-RCg2AcM/edit?usp=sharing)

### Instituição
- Universidade Federal de Pernambuco (UFPE)
- Centro de Informática
- Disciplina: Estruturas de Dados Orientadas a Objetos
