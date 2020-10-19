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
            cpu.LerDaMemoria(enderecoMemoria);
        } else {
            cin >> dadoBinario;
            //Converte a string binaria para um inteiro
            dado = std::stoi(dadoBinario, nullptr, 2);
            cpu.EscreverNaMemoria(enderecoMemoria, dado);
        }
    }
    return 0;
}