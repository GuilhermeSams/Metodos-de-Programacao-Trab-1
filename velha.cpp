#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Guilherme Pereira Sampaio
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

int verificarVencedorX(int jogo[3][3]) {
    // Verificar vitória na linha horizontal para o jogador X
    for (int i = 0; i < 3; ++i) {
        if (jogo[i][0] == 1 && jogo[i][1] == 1 && jogo[i][2] == 1)
            return 1;
    }
}