#include "velha.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Verifica vitória do jogador X na linha horizontal") {
    int jogo[3][3] = {
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificarVencedorX(jogo) == 1);
}

TEST_CASE("Verifica vitória do jogador O na linha horizontal") {
    int jogo[3][3] = {
        {2, 2, 2},
        {0, 0, 0},
        {0, 0, 0}
    };
    REQUIRE(verificarVencedorO(jogo) == 2);
}

TEST_CASE("Verifica empate") {
    int jogo[3][3] = {
        {1, 2, 1},
        {1, 2, 2},
        {2, 1, 1}
    };
    REQUIRE(verificarEmpate(jogo) == 0);
}