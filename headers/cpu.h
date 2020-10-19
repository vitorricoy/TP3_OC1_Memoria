#ifndef TP3_OC1_MEMORIA_HEADERS_CPU_H
#define TP3_OC1_MEMORIA_HEADERS_CPU_H

#include "cache.h"

class CPU {
    public:
        CPU();
        void EscreverNaMemoria(int endereco, int dado);
        void LerDaMemoria(int endereco);
    private:
        Cache cache;
};

#endif //TP3_OC1_MEMORIA_HEADERS_CPU_H