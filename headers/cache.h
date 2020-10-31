#ifndef TP3_OC1_MEMORIA_HEADERS_CACHE_H
#define TP3_OC1_MEMORIA_HEADERS_CACHE_H

#include "memoria.h"

//Estrutura representando uma entrada de um bloco na cache
struct Bloco {
    int tag;
    bool valid;
    bool sujo;
    vector<unsigned int> data;

    //Construtor vazio da entrada
    Bloco() {
        valid = false;
        sujo = false;
        data.resize(4);
    }
};

class Cache {
    public:

        //Constroi a Cache, inicializando seus dados e a memória principal
        Cache();

        //Retorna true se for hit e false se for miss
        //Simula uma leitura de um dado na cache
        bool LerDado(int endereco);

        //Simula a escrita de um dado na cache
        void EscreverDado(int endereco, unsigned int dado);

    private:
        //Memória principal que é utilizada pela cache
        Memoria memoria;
        
        //Representação da cache que guarda os seus blocos
        vector<Bloco> cache;
        
};

#endif //TP3_OC1_MEMORIA_HEADERS_CACHE_H