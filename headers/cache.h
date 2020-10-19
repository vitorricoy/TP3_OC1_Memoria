#ifndef TP3_OC1_MEMORIA_HEADERS_CACHE_H
#define TP3_OC1_MEMORIA_HEADERS_CACHE_H

#include "memoria.h"

class Cache {
    public:
        Cache();
        void LerDado();
        void EscreverDado();
    private:
        Memoria memoria;
};

#endif //TP3_OC1_MEMORIA_HEADERS_CACHE_H