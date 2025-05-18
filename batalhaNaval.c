#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se uma posição está dentro dos limites do tabuleiro
int dentroDosLimites(int linha, int coluna) {
    return (linha >= 0 && linha < TAMANHO_TABULEIRO && coluna >= 0 && coluna < TAMANHO_TABULEIRO);
}

// Função para verificar se há sobreposição em uma determinada posição
int verificarSobreposicao(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    return (dentroDosLimites(linha, coluna) && tabuleiro[linha][coluna] == 3);
}

// Função para posicionar um navio horizontalmente no tabuleiro
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe dentro dos limites do tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal excede os limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }

    // Verifica se há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (verificarSobreposicao(tabuleiro, linha, coluna + i)) {
            printf("Erro: Sobreposição detectada ao posicionar navio horizontalmente.\n");
            return 0; // Falha no posicionamento
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1; // Sucesso no posicionamento
}

// Função para posicionar um navio verticalmente no tabuleiro
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe dentro dos limites do tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical excede os limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }

    // Verifica se há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (verificarSobreposicao(tabuleiro, linha + i, coluna)) {
            printf("Erro: Sobreposição detectada ao posicionar navio verticalmente.\n");
            return 0; // Falha no posicionamento
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1; // Sucesso no posicionamento
}

// Função para posicionar um navio diagonalmente (aumentando linha e coluna)
int posicionarNavioDiagonalCrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe dentro dos limites do tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio diagonal (crescente) excede os limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }

    // Verifica se há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (verificarSobreposicao(tabuleiro, linha + i, coluna + i)) {
            printf("Erro: Sobreposição detectada ao posicionar navio diagonal (crescente).\n");
            return 0; // Falha no posicionamento
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    return 1; // Sucesso no posicionamento
}

// Função para posicionar um navio diagonalmente (aumentando linha e diminuindo coluna)
int posicionarNavioDiagonalDecrescente(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe dentro dos limites do tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) {
        printf("Erro: Navio diagonal (decrescente) excede os limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }

    // Verifica se há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (verificarSobreposicao(tabuleiro, linha + i, coluna - i)) {
            printf("Erro: Sobreposição detectada ao posicionar navio diagonal (decrescente).\n");
            return 0; // Falha no posicionamento
        }
    }

    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
    return 1; // Sucesso no posicionamento
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j); // Imprime os números das colunas com alinhamento
    }
    printf("\n");
    printf("  +");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("+\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d|", i); // Imprime os números das linhas com alinhamento
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("  +");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("+\n\n");
}

int main() {
    // Declara e inicializa o tabuleiro 10x10 com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    printf("Posicionando quatro navios (dois horizontais/verticais e dois diagonais)...\n\n");

    // Define as coordenadas iniciais para os navios
    int linhaHorizontal = 1;
    int colunaHorizontal = 2;

    int linhaVertical = 5;
    int colunaVertical = 7;

    int linhaDiagonalCrescente = 0;
    int colunaDiagonalCrescente = 0;

    int linhaDiagonalDecrescente = 0;
    int colunaDiagonalDecrescente = 9;

    // Tenta posicionar os navios
    if (posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Navio horizontal posicionado em (%d, %d) a (%d, %d).\n",
               linhaHorizontal, colunaHorizontal, linhaHorizontal, colunaHorizontal + TAMANHO_NAVIO - 1);
    }

    if (posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Navio vertical posicionado em (%d, %d) a (%d, %d).\n",
               linhaVertical, colunaVertical, linhaVertical + TAMANHO_NAVIO - 1, colunaVertical);
    }

    if (posicionarNavioDiagonalCrescente(tabuleiro, linhaDiagonalCrescente, colunaDiagonalCrescente)) {
        printf("Navio diagonal (crescente) posicionado em (%d, %d) a (%d, %d).\n",
               linhaDiagonalCrescente, colunaDiagonalCrescente, linhaDiagonalCrescente + TAMANHO_NAVIO - 1, colunaDiagonalCrescente + TAMANHO_NAVIO - 1);
    }

    if (posicionarNavioDiagonalDecrescente(tabuleiro, linhaDiagonalDecrescente, colunaDiagonalDecrescente)) {
        printf("Navio diagonal (decrescente) posicionado em (%d, %d) a (%d, %d).\n",
               linhaDiagonalDecrescente, colunaDiagonalDecrescente, linhaDiagonalDecrescente + TAMANHO_NAVIO - 1, colunaDiagonalDecrescente - TAMANHO_NAVIO + 1);
    }

    printf("\nTabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}