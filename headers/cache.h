#ifndef TP3_OC1_MEMORIA_HEADERS_CACHE_H
#define TP3_OC1_MEMORIA_HEADERS_CACHE_H

#include "memoria.h"

struct Bloco;

class Cache {
    public:
        Cache();
        //Retorna true se for hit e false se for miss
        bool LerDado(int endereco);
        void EscreverDado(int endereco, int dado);
    private:
        Memoria memoria;
        vector<Bloco> cache;
        const int BYTE_OFFSET = 2;
        const int WORD_OFFSET = 2;
        const int INDEX = 6;
};

#endif //TP3_OC1_MEMORIA_HEADERS_CACHE_H