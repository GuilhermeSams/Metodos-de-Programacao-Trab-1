#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Guilherme Pereira Sampaio
 * @param  velha descreve o parametro
 */ 

int verificarVencedorX(int jogo[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (jogo[i][0] == 1 && jogo[i][1] == 1 && jogo[i][2] == 1)
            return 1;
    }
}

int verificarVencedorXDiagonal(int jogo[3][3]) {
    if (jogo[0][0] == 1 && jogo[1][1] == 1 && jogo[2][2] == 1)
        return 1;
    if (jogo[0][2] == 1 && jogo[1][1] == 1 && jogo[2][0] == 1)
        return 1;

    return 0;
}

int verificarVencedorXVertical(int jogo[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (jogo[0][i] == 1 && jogo[1][i] == 1 && jogo[2][i] == 1)
            return 1;
    }
    return 0;
}

int verificarVencedorO(int jogo[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (jogo[i][0] == 2 && jogo[i][1] == 2 && jogo[i][2] == 2)
            return 2;
    }
}

int verificarVencedorODiagonal(int jogo[3][3]) {
    if (jogo[0][0] == 2 && jogo[1][1] == 2 && jogo[2][2] == 2)
        return 2;
    if (jogo[0][2] == 2 && jogo[1][1] == 2 && jogo[2][0] == 2)
        return 2;

    return 0;
}

int verificarVencedorOVertical(int jogo[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (jogo[0][i] == 2 && jogo[1][i] == 2 && jogo[2][i] == 2)
            return 2;
    }
    return 0;
}

int verificarEmpate(int jogo[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (jogo[i][j] == 0)
                return 0;
        }
    }
    return 0;  // Se não há posição vazia, o jogo está empatado
}

int verificarJogoIndefinido(int jogo[3][3]) {
    int contadorX = 0;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (jogo[i][j] == 1)
                contadorX++;
        }
    }

    if (contadorX == 1)
        return -1;  // O jogo está indefinido

    return 0;  // O jogo não está indefinido
}

int verificarJogoImpossivel(int jogo[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (jogo[i][j] != 1)
                return 0;  // O jogo não é impossível, pois há pelo menos uma posição que não é X
        }
    }

    return -2;  // O jogo é impossível, pois todas as posições são X
}