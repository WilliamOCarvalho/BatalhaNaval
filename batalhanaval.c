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

// Função para verificar se é possível posicionar um navio nas coordenadas fornecidas
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

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (orientacao == 'H') {
            tabuleiro[linha][coluna + i] = 3; // 3 representa parte do navio
        } else if (orientacao == 'V') {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas dos navios (definidas diretamente no código)
    int linhaNavioH = 2;
    int colunaNavioH = 4;
    char orientacaoH = 'H'; // Horizontal

    int linhaNavioV = 5;
    int colunaNavioV = 6;
    char orientacaoV = 'V'; // Vertical

    // Verifica se é possível posicionar o navio horizontal
    if (podePosicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, orientacaoH)) {
        posicionarNavio(tabuleiro, linhaNavioH, colunaNavioH, orientacaoH);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal.\n");
    }

    // Verifica se é possível posicionar o navio vertical
    if (podePosicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, orientacaoV)) {
        posicionarNavio(tabuleiro, linhaNavioV, colunaNavioV, orientacaoV);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
