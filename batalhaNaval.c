#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro 10x10 e inicialização com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Declaração dos navios
    int navio_horizontal[TAMANHO_NAVIO] = {3, 3, 3};
    int navio_vertical[TAMANHO_NAVIO] = {3, 3, 3};

    // Coordenadas iniciais dos navios (definidas diretamente)
    int linha_horizontal = 2; // Linha onde o navio horizontal começará
    int coluna_horizontal = 4; // Coluna inicial do navio horizontal

    int linha_vertical = 5; // Linha inicial do navio vertical
    int coluna_vertical = 7; // Coluna onde o navio vertical começará

    // Posicionamento do navio horizontal no tabuleiro
    // Validação para garantir que cabe no tabuleiro
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Garantir que não sobrepõe outro navio
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == 0) {
                tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            }
        }
    } else {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
    }

    // Posicionamento do navio vertical no tabuleiro
    // Validação para garantir que cabe no tabuleiro
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Garantir que não sobrepõe outro navio
            if (tabuleiro[linha_vertical + i][coluna_vertical] == 0) {
                tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
            }
        }
    } else {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
    }

    // Exibição do tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
