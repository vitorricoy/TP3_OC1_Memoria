#include <cstdio>
#include <iostream>
#include <bitset>
#include "headers/cache.h"
#include "headers/cpu.h"
#include "headers/memoria.h"

using namespace std;

//Estrutura para armazenar as informações das operações
struct InformacaoOperacao {
    int endereco;
    int tipo;
    int dado;
    bool hit;
    InformacaoOperacao(int end_, int tipo_, int dado_, bool hit_) : endereco(end_), tipo(tipo_), dado(dado_), hit(hit_) {
        //Vazio
    }
};

int main() {
    //Determina que a saída e entrada padrão serão nos determinados arquivos
    freopen("input.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    
    //Declara as variáveis dos dados que serão lidos
    int enderecoMemoria, tipoOperacao, dado;
    string dadoBinario;

    //Declara a cpu que é responsável por disparar a operação lida da entrada
    CPU cpu;

    //Vetor para salvar as informações das operações executadas
    vector<InformacaoOperacao> informacoes;

    //Lê as operações até encontrar um EOF
    while(cin >> enderecoMemoria >> tipoOperacao) {
        if(tipoOperacao == 0) {
            //Simula a cpu lendo da memória, retornando se foi hit ou miss
            bool hit = cpu.LerDaMemoria(enderecoMemoria);
            //Salva a informação da operação para imprimir as estatisticas no fim da execução
            informacoes.push_back(InformacaoOperacao(enderecoMemoria, tipoOperacao, 0, hit));
        } else {
            //Lê o dado a ser escrito
            cin >> dadoBinario;
            //Converte a string binaria para um inteiro
            dado = std::stoi(dadoBinario, nullptr, 2);
            //Simula a cpu escrevendo na memória
            cpu.EscreverNaMemoria(enderecoMemoria, dado);
            //Salva a informação da operação 'para imprimir as estatisticas no fim da execução
            informacoes.push_back(InformacaoOperacao(enderecoMemoria, tipoOperacao, dado, false));
        }
    }

    //Declara os contadores
    int contMiss = 0, contHit = 0, contRead = 0, contWrite = 0;

    //Conta cada estado para os cálculos da estatística
    for(InformacaoOperacao informacao : informacoes) {
        if(informacao.tipo == 0) {
            if(informacao.hit) {
                contHit++;
            } else {
                contMiss++;
            }
            contRead++;
        } else {
            contWrite++;
        }
    }

    //Calcula o miss rate e o hit rate
    double missRate = ((double)contMiss)/((double)contRead);
    double hitRate = ((double)contHit)/((double)contRead);

    //Imprime as estatisticas calculadas
    cout << "READS: " << contRead << endl;
    cout << "WRITES: " << contWrite << endl;
    cout << "HITS: " << contHit << endl;
    cout << "MISSES: " << contMiss << endl;
    cout << "HIT RATE: " << hitRate << endl;
    cout << "MISS RATE: " << missRate << endl;
    cout << endl;

    //Imprime cada instrução seguida da identificação de que se foi uma escrita, hit ou um miss
    for(InformacaoOperacao informacao : informacoes) {
        if(informacao.tipo == 0) {
            cout << informacao.endereco << " " << informacao.tipo << " ";
            if(informacao.hit) {
                cout << "H" << endl;
            } else {
                cout << "M" << endl;
            }
        } else {
            cout << informacao.endereco << " " << informacao.tipo << " " << bitset<32>(informacao.dado) << " W" << endl;
        }
    }
    return 0;
}