#ifndef TP3_OC1_MEMORIA_HEADERS_MEMORIA_H
#define TP3_OC1_MEMORIA_HEADERS_MEMORIA_H

#include <vector>

using namespace std;

class Memoria {
    public:

        //Constroi a Memoria, inicializando seus dados
        Memoria();

        //Le um dado da memória, retornando o dado lido
        int LerDado(int endereco);

        //Escreve um dado na memória
        void EscreverDado(int endereco, int dado);

    private:

        //Representação da memória que guarda cada palavra
        vector<int> memoria;
        
};

#endif //TP3_OC1_MEMORIA_HEADERS_MEMORIA_H