#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5 // Tamanho das matrizes de habilidade (ímpar para ter um centro bem definido)
#include <stdlib.h>

// Função para inicializar o tabuleiro com água (valor 0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio horizontalmente no tabuleiro
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[linha][coluna + i] == 3) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[linha][coluna + i] = 3;
    return 1;
}

// Função para posicionar um navio verticalmente no tabuleiro
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) if (tabuleiro[linha + i][coluna] == 3) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) tabuleiro[linha + i][coluna] = 3;
    return 1;
}

// Função para criar a matriz de habilidade em forma de cone
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i >= centro && j >= centro - (i - centro) && j <= centro + (i - centro)) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro (losango)
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para aplicar a habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaOrigem, int colunaOrigem) {
    int centroHabilidade = TAMANHO_HABILIDADE / 2;
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTabuleiro = linhaOrigem - centroHabilidade + i;
                int colunaTabuleiro = colunaOrigem - centroHabilidade + j;
                if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO && tabuleiro[linhaTabuleiro][colunaTabuleiro] != 3) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5; // Marca como área afetada
                }
            }
        }
    }
}

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    printf("  +");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("+\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d|", i);
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
    // Declara e inicializa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posiciona alguns navios para visualização
    posicionarNavioHorizontal(tabuleiro, 2, 3);
    posicionarNavioVertical(tabuleiro, 6, 1);
    posicionarNavioHorizontal(tabuleiro, 8, 7);

    printf("Tabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    // Cria as matrizes de habilidade
    int habilidadeCone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeCruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidadeOctaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    printf("Matriz de habilidade Cone:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidadeCone[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriz de habilidade Cruz:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidadeCruz[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Matriz de habilidade Octaedro:\n");
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidadeOctaedro[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Define os pontos de origem das habilidades no tabuleiro
    int linhaOrigemCone = 1;
    int colunaOrigemCone = 4;

    int linhaOrigemCruz = 5;
    int colunaOrigemCruz = 5;

    int linhaOrigemOctaedro = 8;
    int colunaOrigemOctaedro = 2;

    // Aplica as habilidades ao tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, linhaOrigemCone, colunaOrigemCone);
    aplicarHabilidade(tabuleiro, habilidadeCruz, linhaOrigemCruz, colunaOrigemCruz);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, linhaOrigemOctaedro, colunaOrigemOctaedro);

    printf("Tabuleiro com habilidades aplicadas (5 representa a área de efeito):\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}