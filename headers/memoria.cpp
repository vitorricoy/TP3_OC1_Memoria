#include "memoria.h"

Memoria::Memoria(){
    memoria = vector<int>(1024);
}

int Memoria::LerDado(int endereco){
    return memoria[endereco];
}

void Memoria::EscreverDado(int endereco, int dado){
    endereco = endereco/4;
    memoria[endereco] = dado;
}