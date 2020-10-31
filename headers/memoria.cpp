#include "memoria.h"

Memoria::Memoria(){
    memoria = vector<int>(1024);
}

int Memoria::LerDado(int endereco){
    return memoria[endereco / 4];
}

void Memoria::EscreverDado(int endereco, int dado){
    memoria[endereco / 4] = dado;
}