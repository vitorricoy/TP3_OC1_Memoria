#ifndef TP3_OC1_MEMORIA_HEADERS_MEMORIA_H
#define TP3_OC1_MEMORIA_HEADERS_MEMORIA_H

class Memoria {
    public:
        Memoria();
        void LerDado();
        void EscreverDado();
    private:
        vector<vector<int> > memoria;
};

#endif //TP3_OC1_MEMORIA_HEADERS_MEMORIA_H