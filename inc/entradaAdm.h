#ifndef MAQUINA_VENDA_ENTRADAADM_H
#define MAQUINA_VENDA_ENTRADAADM_H

#include "caixa.h"
void loginADM();
void menuADM(Caixa& fluxoDeCaixa);
void adicionarProduto();
void removerProduto();
void listarProdutos();
void alterarSenha();
void acessarFluxoCaixa(Caixa& fluxoDeCaixa);
void adicionarAoFluxo(Caixa& fluxoDeCaixa);
void removerDoFluxo(Caixa& fluxoDeCaixa);

#endif //MAQUINA_VENDA_ENTRADAADM_H