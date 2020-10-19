#include <cstdio>
#include <iostream>
#include "headers/cache.h"
#include "headers/cpu.h"
#include "headers/memoria.h"

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    int enderecoMemoria, tipoOperacao, dado;
    string dadoBinario;
    CPU cpu;
    while(cin >> enderecoMemoria >> tipoOperacao) {
        if(tipoOperacao == 0) {
            bool hitOuMiss = cpu.LerDaMemoria(enderecoMemoria);
            //Tratar hit ou miss
        } else {
            cin >> dadoBinario;
            //Converte a string binaria para um inteiro
            dado = std::stoi(dadoBinario, nullptr, 2);
            bool hitOuMiss = cpu.EscreverNaMemoria(enderecoMemoria, dado);
            //Tratar hit ou miss
        }
    }
    return 0;
}