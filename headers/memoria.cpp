#include "memoria.h"


//Constante do ByteOffset do endereço
const int BYTE_OFFSET = 2;

//Constroi a Memoria, inicializando seus dados
Memoria::Memoria(){
    //Inicializa a memória com 1024 palavras
    memoria = vector<int>(1024);
}

//Le um dado da memória, retornando o dado lido
int Memoria::LerDado(int endereco){
    //Calcula o endereço da palavra, utilizando o ByteOffset
    endereco = (endereco >> BYTE_OFFSET);
    //Retorna a palavra lida
    return memoria[endereco];
}

//Escreve um dado na memória
void Memoria::EscreverDado(int endereco, int dado){
    //Calcula o endereço da palavra, utilizando o ByteOffset
    endereco = (endereco >> BYTE_OFFSET);
    //Atribui o novo dado à palavra
    memoria[endereco] = dado;
}