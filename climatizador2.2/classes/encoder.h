#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <defines.h>

class Encoder {
  private:
    //vetor com estados para leitura do encoder em modo de quadratura
    int8_t estados[16] = { 0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0 };
    int16_t posicaoEncoder;
    int16_t posicaoPasso;
    uint16_t escala;
  public:
    //construtor
    Encoder(uint16_t esc = 1) {
      escala = esc;
    }
    //manipulacao dos atributos
    inline void encoder(int16_t pos) {
      posicaoEncoder += estados[pos];
    }
    inline void atualiza() {
      posicaoPasso = (posicaoEncoder >> 2) * escala;
    }
    inline int16_t passo() {
      return posicaoPasso;
    }
    inline int16_t posicao() {
      return posicaoPasso;
    }
    inline int16_t posicao(int16_t pos) {
      posicaoPasso = pos;
      posicaoEncoder = (pos / 5) | (posicaoEncoder & 0x03);
    }
    //teste de condicoes
    inline uint8_t limite(int16_t min, int16_t max) {
      return ( posicaoPasso >= min && posicaoPasso <= max );
    }
};


#endif
