#include "cpu.h"
#include "cache.h"

        
//Constroi a CPU, inicializando a Cache
CPU::CPU() {
    this->cache = Cache();
}

//Simula uma escrita na memória pela CPU
void CPU::EscreverNaMemoria(int endereco, unsigned int dado) {
    cache.EscreverDado(endereco, dado);
}

//Retorna true se for hit e false se for miss
//Simula uma leitura na memória pela CPU
bool CPU::LerDaMemoria(int endereco) {
    return cache.LerDado(endereco);
}