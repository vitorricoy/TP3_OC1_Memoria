#ifndef TP3_OC1_MEMORIA_HEADERS_CACHE_H
#define TP3_OC1_MEMORIA_HEADERS_CACHE_H

#include "memoria.h"

class Cache {
    public:
        Cache();
        //Retorna true se for hit e false se for miss
        bool LerDado();
        void EscreverDado();
    private:
        Memoria memoria;
};

#endif //TP3_OC1_MEMORIA_HEADERS_CACHE_H