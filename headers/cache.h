#ifndef TP3_OC1_MEMORIA_HEADERS_CACHE_H
#define TP3_OC1_MEMORIA_HEADERS_CACHE_H

#include "memoria.h"

struct Bloco;

class Cache {
    public:

        //Constroi a Cache, inicializando seus dados e a memória principal
        Cache();

        //Retorna true se for hit e false se for miss
        //Simula uma leitura de um dado na cache
        bool LerDado(int endereco);

        //Simula a escrita de um dado na cache
        void EscreverDado(int endereco, int dado);

    private:
        //Memória principal que é utilizada pela cache
        Memoria memoria;
        
        //Representação da cache que guarda os seus blocos
        vector<Bloco> cache;
        
        //Constantes dos offsets e indices da cache
        const int BYTE_OFFSET = 2;
        const int WORD_OFFSET = 2;
        const int INDEX = 6;
};

#endif //TP3_OC1_MEMORIA_HEADERS_CACHE_H