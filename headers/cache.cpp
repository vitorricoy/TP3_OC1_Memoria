#include "cache.h"
#include "memoria.h"

struct Bloco {
    int tag;
    bool valid;
    bool sujo;
    vector<int> data;

    Entrada() {
        valid = false;
        sujo = false;
        data.resize(4);
    }
};

Cache::Cache () {
    this->memoria = Memoria();
    cache = vector<Bloco>(64);
}

bool Cache::LerDado(int endereco) {
    int indice_palavra = (endereco >> BYTE_OFFSET) % (1 << WORD_OFFSET);
    int indice_bloco =  (endereco >> (BYTE_OFFSET + WORD_OFFSET)) % (1 << INDEX);
    int tag = (endereco >> (BYTE_OFFSET + WORD_OFFSET + INDEX));
    if (cache[indice_bloco].valid && cache[indice_bloco].tag == tag) {
        return true;
    } else {
        if (cache[indice_bloco].sujo) {
            for (int i = 0; i < 4; i++) {
                int endereco_sujo = cache[indice_bloco].tag;
                endereco_sujo <<= (BYTE_OFFSET + WORD_OFFSET + INDEX);
                endereco_sujo += (indice_bloco << (BYTE_OFFSET + WORD_OFFSET));
                endereco_sujo += (i << WORD_OFFSET);
                endereco_sujo += endereco % (1 << BYTE_OFFSET);
                this->memoria.EscreverDado(endereco_sujo, cache[indice_bloco].data[i]);
            }
        }
        cache[indice_bloco].valid = true;
        cache[indice_bloco].sujo = false;
        cache[indice_bloco].tag = tag;
        for (int i = 0; i < 4; i++) {
            int novo_endereco = (endereco >> (BYTE_OFFSET + WORD_OFFSET));
            novo_endereco <<= WORD_OFFSET;
            novo_endereco += i;
            novo_endereco <<= BYTE_OFFSET;
            novo_endereco += endereco % (1 << BYTE_OFFSET);
            cache[indice_bloco].data[i] = this->memoria.LerDado(novo_endereco);
        }
        return false;
    }
}

Cache::EscreverDado(int endereco, int dado) {
    int indice_palavra = (endereco >> BYTE_OFFSET) % (1 << WORD_OFFSET);
    int indice_bloco =  (endereco >> (BYTE_OFFSET + WORD_OFFSET)) % (1 << INDEX);
    int tag = (endereco >> (BYTE_OFFSET + WORD_OFFSET + INDEX));
    if (cache[indice_bloco].valid && cache[indice_bloco].tag == tag) {
        cache[indice_bloco].data[indice_palavra] = dado;
        cache[indice_bloco].sujo = true;
    } else {
        if (cache[indice_bloco].sujo) {
            for (int i = 0; i < 4; i++) {
                int endereco_sujo = cache[indice_bloco].tag;
                endereco_sujo <<= (BYTE_OFFSET + WORD_OFFSET + INDEX);
                endereco_sujo += (indice_bloco << (BYTE_OFFSET + WORD_OFFSET));
                endereco_sujo += (i << WORD_OFFSET);
                endereco_sujo += endereco % (1 << BYTE_OFFSET);
                this->memoria.EscreverDado(endereco_sujo, cache[indice_bloco].data[i]);
            }
        }
        cache[indice_bloco].valid = true;
        cache[indice_bloco].sujo = true;
        cache[indice_bloco].tag = tag;
        for (int i = 0; i < 4; i++) {
            if (i == indice_palavra) {
                cache[indice_bloco].data[i] = dado;
                continue;
            }
            int novo_endereco = (endereco >> (BYTE_OFFSET + WORD_OFFSET));
            novo_endereco <<= WORD_OFFSET;
            novo_endereco += i;
            novo_endereco <<= BYTE_OFFSET;
            novo_endereco += endereco % (1 << BYTE_OFFSET);
            cache[indice_bloco].data[i] = this->memoria.LerDado(novo_endereco);
        }
    }
}