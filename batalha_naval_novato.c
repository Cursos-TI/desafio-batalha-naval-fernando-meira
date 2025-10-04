#include <stdio.h>

// Nivel Novato — Tabuleiro 5x5, dois navios (len=3): um horizontal e um vertical
// Imprime coordenadas e a matriz resultante (0=agua, 3=navio)

#define R 5
#define C 5
#define LEN 3
#define NAV 3

void print_matrix(const int m[R][C]) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) printf("%d ", m[r][c]);
        printf("\n");
    }
}
void fill_matrix(int m[R][C], int v) {
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) m[r][c] = v;
}

int cabe_horizontal(int row, int col) { return row >= 0 && row < R && col >= 0 && col + LEN - 1 < C; }
int cabe_vertical  (int row, int col) { return row >= 0 && row + LEN - 1 < R && col >= 0 && col < C; }

int livre_horizontal(const int b[R][C], int row, int col) { for (int i=0;i<LEN;i++) if (b[row][col+i]!=0) return 0; return 1; }
int livre_vertical  (const int b[R][C], int row, int col) { for (int i=0;i<LEN;i++) if (b[row+i][col]!=0) return 0; return 1; }

void coloca_horizontal(int b[R][C], int row, int col) { for (int i=0;i<LEN;i++) b[row][col+i]=NAV; }
void coloca_vertical  (int b[R][C], int row, int col) { for (int i=0;i<LEN;i++) b[row+i][col]=NAV; }

int main(void) {
    int board[R][C]; fill_matrix(board, 0);

    // Coordenadas escolhidas (0-based)
    int h_row=1, h_col=1; // (1,1)-(1,3)
    int v_row=0, v_col=4; // (0,4)-(2,4)

    if (!cabe_horizontal(h_row,h_col) || !livre_horizontal(board,h_row,h_col)) {
        printf("ERRO: horizontal invalido em (%d,%d)\n", h_row, h_col); return 0;
    }
    coloca_horizontal(board,h_row,h_col);

    if (!cabe_vertical(v_row,v_col) || !livre_vertical(board,v_row,v_col)) {
        printf("ERRO: vertical invalido em (%d,%d)\n", v_row, v_col); return 0;
    }
    coloca_vertical(board,v_row,v_col);

    printf("Coordenadas navio horizontal:\n");
    for (int i=0;i<LEN;i++) printf("(%d,%d)\n", h_row, h_col+i);
    printf("Coordenadas navio vertical:\n");
    for (int i=0;i<LEN;i++) printf("(%d,%d)\n", v_row+i, v_col);

    printf("Tabuleiro 5x5 (0=agua, 3=navio):\n");
    print_matrix(board);
    return 0;
}
