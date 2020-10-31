#include "cache.h"
#include "memoria.h"

//Constantes dos offsets e indices da cache
const int BYTE_OFFSET = 2;
const int WORD_OFFSET = 2;
const int INDEX = 6;

//Constroi a Cache, inicializando seus dados e a memória principal
Cache::Cache () {
    //Instancia a memória principal
    this->memoria = Memoria();
    //Inicializa a cache com 64 blocos
    cache = vector<Bloco>(64);
}

//Retorna true se for hit e false se for miss
//Simula uma leitura de um dado na cache
bool Cache::LerDado(int endereco) {
    //Determina o índice do bloco do endereço lido na cache
    int indice_bloco =  (endereco >> (BYTE_OFFSET + WORD_OFFSET)) % (1 << INDEX);
    //Determina o valor da tag do endereço lido
    int tag = (endereco >> (BYTE_OFFSET + WORD_OFFSET + INDEX));
    if (cache[indice_bloco].valid && cache[indice_bloco].tag == tag) { 
        //Se o bloco sendo lido na cache é válido e representa o endereço a ser lido
        //Retorna hit
        return true;
    } else {
        //Se o endereço sendo lido não foi encontrado na cache
        if (cache[indice_bloco].sujo) {
            //Se o bloco a ser substituido está sujo
            //Atualiza o valor do bloco sujo na memória
            for (int i = 0; i < 4; i++) { //Para cada palavra do bloco sujo
                //Calcula o endereço da palavra i do bloco sujo
                int endereco_sujo = cache[indice_bloco].tag;
                endereco_sujo <<= (BYTE_OFFSET + WORD_OFFSET + INDEX);
                endereco_sujo += (indice_bloco << (BYTE_OFFSET + WORD_OFFSET));
                endereco_sujo += (i << WORD_OFFSET);
                endereco_sujo += endereco % (1 << BYTE_OFFSET);
                //Escreve o dado da palavra i do bloco sujo na memória
                this->memoria.EscreverDado(endereco_sujo, cache[indice_bloco].data[i]);
            }
        }
        //Define os valores de controle do bloco na cache
        cache[indice_bloco].valid = true;
        cache[indice_bloco].sujo = false;
        cache[indice_bloco].tag = tag;
        for (int i = 0; i < 4; i++) { //Para cada palavra do bloco
            //Calcula o endereço da palavra i do bloco do endereço lido
            int novo_endereco = (endereco >> (BYTE_OFFSET + WORD_OFFSET));
            novo_endereco <<= WORD_OFFSET;
            novo_endereco += i;
            novo_endereco <<= BYTE_OFFSET;
            novo_endereco += endereco % (1 << BYTE_OFFSET);
            //Lê o valor da palavra i do bloco do endereço lido
            cache[indice_bloco].data[i] = this->memoria.LerDado(novo_endereco);
        }
        //Retorna miss
        return false;
    }
}

//Simula a escrita de um dado na cache
void Cache::EscreverDado(int endereco, int dado) {
    //Determina o índice da palavra no bloco do endereço lido na cache
    int indice_palavra = (endereco >> BYTE_OFFSET) % (1 << WORD_OFFSET);
    //Determina o índice do bloco do endereço lido na cache
    int indice_bloco =  (endereco >> (BYTE_OFFSET + WORD_OFFSET)) % (1 << INDEX);
    //Determina o valor da tag do endereço lido
    int tag = (endereco >> (BYTE_OFFSET + WORD_OFFSET + INDEX));
    if (cache[indice_bloco].valid && cache[indice_bloco].tag == tag) {
        //Se o bloco sendo lido na cache é válido e representa o endereço a ser lido
        //Escreve o dado sendo escrito na palavra do bloco
        cache[indice_bloco].data[indice_palavra] = dado;
        //Marca o bloco como sujo
        cache[indice_bloco].sujo = true;
    } else {
        //Se o endereço sendo lido não foi encontrado na cache
        if (cache[indice_bloco].sujo) {
            //Se o bloco a ser substituido está sujo
            //Atualiza o valor do bloco sujo na memória
            for (int i = 0; i < 4; i++) { //Para cada palavra do bloco sujo
                //Calcula o endereço da palavra i do bloco sujo
                int endereco_sujo = cache[indice_bloco].tag;
                endereco_sujo <<= (BYTE_OFFSET + WORD_OFFSET + INDEX);
                endereco_sujo += (indice_bloco << (BYTE_OFFSET + WORD_OFFSET));
                endereco_sujo += (i << WORD_OFFSET);
                endereco_sujo += endereco % (1 << BYTE_OFFSET);
                //Escreve o dado da palavra i do bloco sujo na memória
                this->memoria.EscreverDado(endereco_sujo, cache[indice_bloco].data[i]);
            }
        }
        //Define os valores de controle do bloco na cache
        cache[indice_bloco].valid = true;
        cache[indice_bloco].sujo = true;
        cache[indice_bloco].tag = tag;
        for (int i = 0; i < 4; i++) { //Para cada palavra do bloco
            if (i == indice_palavra) {
                //Caso a palavra i do bloco seja a palavra sendo escrita, ela não é lida da memória
                //Guarda o dado sendo escrito na palavra i do bloco do endereço no cache
                cache[indice_bloco].data[i] = dado;
                continue;
            }
            //Calcula o endereço da palavra i do bloco do endereço lido
            int novo_endereco = (endereco >> (BYTE_OFFSET + WORD_OFFSET));
            novo_endereco <<= WORD_OFFSET;
            novo_endereco += i;
            novo_endereco <<= BYTE_OFFSET;
            novo_endereco += endereco % (1 << BYTE_OFFSET);
            //Lê o valor da palavra i do bloco do endereço lido
            cache[indice_bloco].data[i] = this->memoria.LerDado(novo_endereco);
        }
    }
}