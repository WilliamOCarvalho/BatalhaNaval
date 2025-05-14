#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com zeros
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// Função para verificar se é possível posicionar um navio horizontal ou vertical
int podePosicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            if (coluna + i >= TAMANHO_TABULEIRO || tabuleiro[linha][coluna + i] != 0)
                return 0;
        } else if (orientacao == 'V') {
            if (linha + i >= TAMANHO_TABULEIRO || tabuleiro[linha + i][coluna] != 0)
                return 0;
        }
    }
    return 1;
}

// Função para posicionar o navio horizontal ou vertical
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            tabuleiro[linha][coluna + i] = 3; // 3 representa parte do navio
        } else if (orientacao == 'V') {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para verificar se é possível posicionar navio na diagonal
int podePosicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'D') { // Diagonal principal ↘
            if (linha + i >= TAMANHO_TABULEIRO || coluna + i >= TAMANHO_TABULEIRO || tabuleiro[linha + i][coluna + i] != 0)
                return 0;
        } else if (direcao == 'E') { // Diagonal secundária ↙
            if (linha + i >= TAMANHO_TABULEIRO || coluna - i < 0 || tabuleiro[linha + i][coluna - i] != 0)
                return 0;
        }
    }
    return 1;
}

// Função para posicionar navio na diagonal
void posicionarNavioDiagonal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (direcao == 'D') { // Diagonal principal ↘
            tabuleiro[linha + i][coluna + i] = 3;
        } else if (direcao == 'E') { // Diagonal secundária ↙
            tabuleiro[linha + i][coluna - i] = 3;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n    ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf(" %2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios (fixas)
    int linhaNavioH = 2;
    int colunaNavioH = 4;
    char orientacaoH = 'H';

    int linhaNavioV = 5;
    int colunaNavioV = 6;
    char orientacaoV = 'V';

    int linhaDiagonal1 = 0;
    int colunaDiagonal1 = 0;
    char direcaoDiagonal1 = 'D'; // ↘

    int linhaDiagonal2 = 0;
    int colunaDiagonal2 = 9;
    char direcaoDiagonal2 = 'E'; // ↙

    // Posiciona navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, orientacaoH)) {
        posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, orientacaoH);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Posiciona navio vertical
    if (podePosicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, orientacaoV)) {
        posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, orientacaoV);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Posiciona navio diagonal ↘
    if (podePosicionarNavioDiagonal(tabuleiro, linhaDiagonal1, colunaDiagonal1, direcaoDiagonal1)) {
        posicionarNavioDiagonal(tabuleiro, linhaDiagonal1, colunaDiagonal1, direcaoDiagonal1);
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal ↘.\n");
    }

    // Posiciona navio diagonal ↙
    if (podePosicionarNavioDiagonal(tabuleiro, linhaDiagonal2, colunaDiagonal2, direcaoDiagonal2)) {
        posicionarNavioDiagonal(tabuleiro, linhaDiagonal2, colunaDiagonal2, direcaoDiagonal2);
    } else {
        printf("Erro: Não foi possível posicionar o navio diagonal ↙.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
