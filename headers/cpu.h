#ifndef TP3_OC1_MEMORIA_HEADERS_CPU_H
#define TP3_OC1_MEMORIA_HEADERS_CPU_H

#include "cache.h"

class CPU {
    public:
        CPU();
        //Retorna true se for hit e false se for miss
        bool EscreverNaMemoria(int endereco, int dado);
        bool LerDaMemoria(int endereco);
    private:
        Cache cache;
};

#endif //TP3_OC1_MEMORIA_HEADERS_CPU_H