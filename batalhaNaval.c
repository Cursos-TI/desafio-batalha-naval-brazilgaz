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

// Função para posicionar um navio horizontalmente no tabuleiro
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe dentro dos limites do tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal excede os limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }

    // Verifica se há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] == 3) {
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
        if (tabuleiro[linha + i][coluna] == 3) {
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

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Imprime os números das colunas
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime os números das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Declara e inicializa o tabuleiro 10x10 com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Define as coordenadas iniciais para o navio horizontal
    int linhaHorizontal = 2;
    int colunaHorizontal = 1;

    // Define as coordenadas iniciais para o navio vertical
    int linhaVertical = 6;
    int colunaVertical = 4;

    printf("Posicionando navios...\n\n");

    // Tenta posicionar o navio horizontal
    if (posicionarNavioHorizontal(tabuleiro, linhaHorizontal, colunaHorizontal)) {
        printf("Navio horizontal posicionado em (%d, %d) a (%d, %d).\n",
               linhaHorizontal, colunaHorizontal, linhaHorizontal, colunaHorizontal + TAMANHO_NAVIO - 1);
    }

    // Tenta posicionar o navio vertical
    if (posicionarNavioVertical(tabuleiro, linhaVertical, colunaVertical)) {
        printf("Navio vertical posicionado em (%d, %d) a (%d, %d).\n",
               linhaVertical, colunaVertical, linhaVertical + TAMANHO_NAVIO - 1, colunaVertical);
    }

    printf("\nTabuleiro com navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}