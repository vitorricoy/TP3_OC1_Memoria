#ifndef TP3_OC1_MEMORIA_HEADERS_CPU_H
#define TP3_OC1_MEMORIA_HEADERS_CPU_H

#include "cache.h"

class CPU {
    public:

        //Constroi a CPU, inicializando a Cache
        CPU();

        //Simula uma escrita na memória pela CPU
        void EscreverNaMemoria(int endereco, int dado);

        //Retorna true se for hit e false se for miss
        //Simula uma leitura na memória pela CPU
        bool LerDaMemoria(int endereco);

    private:
    
        //Memória cache que faz a interface entre a CPU e a memória principal
        Cache cache;
};

#endif //TP3_OC1_MEMORIA_HEADERS_CPU_H