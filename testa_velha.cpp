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