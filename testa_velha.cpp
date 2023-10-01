#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Verifica vitória do jogador X na linha horizontal") {
    int jogo[3][3] = {
        {1, 1, 1},
        {2, 2, 0},
        {0, 0, 0}
    };
    REQUIRE(verificarVencedorX(jogo) == 1);
}

TEST_CASE("Verificar vitória do jogador X na diagonal") {
    int jogo[3][3] = {
        {1, 2, 2},
        {0, 1, 0},
        {0, 0, 1}
    };
    REQUIRE(verificarVencedorXDiagonal(jogo) == 1);
}

TEST_CASE("Verificar vitória do jogador X na vertical") {
    int jogo [3][3] = {
        {1, 0, 0},
        {1, 2, 0},
        {1, 0, 2}
    };
    REQUIRE(verificarVencedorXVertical(jogo) == 1);
}

TEST_CASE("Verifica vitória do jogador O na linha horizontal") {
    int jogo[3][3] = {
        {2, 2, 2},
        {1, 1, 0},
        {0, 0, 0}
    };
    REQUIRE(verificarVencedorO(jogo) == 2);
}

TEST_CASE("Verifica vitória do jogador O na diagonal") {
    int jogo[3][3] = {
        {1, 1, 2},
        {0, 2, 0},
        {2, 0, 0}
    };
    REQUIRE(verificarVencedorODiagonal(jogo) == 2);
}

TEST_CASE("Verificar vitória do jogador O na vertical") {
    int jogo[3][3] = {
        {0, 0, 2},
        {0, 0, 2},
        {0, 0, 2}
    };
    REQUIRE(verificarVencedorOVertical(jogo) == 2);
}

TEST_CASE("Verifica empate") {
    int jogo[3][3] = {
        {1, 2, 1},
        {1, 2, 2},
        {2, 1, 1}
    };
    REQUIRE(verificarEmpate(jogo) == 0);
}

TEST_CASE("Verifica jogo indefinido") {
    int jogo[3][3] = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificarJogoIndefinido(jogo) == -1);
}

TEST_CASE("Verifica jogo impossível") {
    int jogo[3][3] = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };
    REQUIRE(verificarJogoImpossivel(jogo) == -2);
}