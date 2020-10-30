#ifndef TP3_OC1_MEMORIA_HEADERS_MEMORIA_H
#define TP3_OC1_MEMORIA_HEADERS_MEMORIA_H

#include <vector>

using namespace std;

class Memoria {
    public:
        Memoria();
        int LerDado(int endereco);
        void EscreverDado(int endereco, int dado);
    private:
        vector<int> memoria;
};

#endif //TP3_OC1_MEMORIA_HEADERS_MEMORIA_H