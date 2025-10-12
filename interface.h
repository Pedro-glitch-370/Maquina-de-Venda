#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>

// A declaração da função foi atualizada.
// Em vez de um nome de arquivo, ela agora recebe o número total de bips.
void falar(const std::string& texto, int totalDeBips, int delay, int delay_final = 1000);

#endif
