#include "memoria.h"

Memoria::Memoria(){
    memoria = vector<int>(1024);
}

int Memoria::LerDado(int endereco){
    endereco = (endereco >> BYTE_OFFSET);
    return memoria[endereco];
}

void Memoria::EscreverDado(int endereco, int dado){
    endereco = (endereco >> BYTE_OFFSET);
    memoria[endereco] = dado;
}