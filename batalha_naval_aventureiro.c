#include <stdio.h>

// Nivel Aventureiro — Tabuleiro 10x10, quatro navios (len=3):
// 1 horizontal, 1 vertical, 1 diagonal ↘, 1 diagonal ↗
// Valida limites/sobreposicao e imprime a matriz (0=agua, 3=navio)

#define R 10
#define C 10
#define LEN 3
#define NAV 3

void print_matrix(const int m[R][C]) {
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) printf("%d ", m[r][c]);
        printf("\n");
    }
}
void fill_matrix(int m[R][C], int v) {
    for (int r=0;r<R;r++) for (int c=0;c<C;c++) m[r][c]=v;
}

int cabe_horizontal(int row,int col){return row>=0&&row<R&&col>=0&&col+LEN-1<C;}
int cabe_vertical  (int row,int col){return row>=0&&row+LEN-1<R&&col>=0&&col<C;}
int cabe_drd       (int row,int col){return row>=0&&col>=0&&row+LEN-1<R&&col+LEN-1<C;} // ↘
int cabe_urd       (int row,int col){return row-(LEN-1)>=0&&col+(LEN-1)<C;}             // ↗

int livre_horizontal(const int b[R][C],int row,int col){for(int i=0;i<LEN;i++) if(b[row][col+i]!=0)return 0;return 1;}
int livre_vertical  (const int b[R][C],int row,int col){for(int i=0;i<LEN;i++) if(b[row+i][col]!=0)return 0;return 1;}
int livre_drd       (const int b[R][C],int row,int col){for(int i=0;i<LEN;i++) if(b[row+i][col+i]!=0)return 0;return 1;}
int livre_urd       (const int b[R][C],int row,int col){for(int i=0;i<LEN;i++) if(b[row-i][col+i]!=0)return 0;return 1;}

void coloca_horizontal(int b[R][C],int row,int col){for(int i=0;i<LEN;i++) b[row][col+i]=NAV;}
void coloca_vertical  (int b[R][C],int row,int col){for(int i=0;i<LEN;i++) b[row+i][col]=NAV;}
void coloca_drd       (int b[R][C],int row,int col){for(int i=0;i<LEN;i++) b[row+i][col+i]=NAV;}
void coloca_urd       (int b[R][C],int row,int col){for(int i=0;i<LEN;i++) b[row-i][col+i]=NAV;}

int main(void){
    int board[R][C]; fill_matrix(board,0);

    // Coordenadas (0-based) sem sobreposição:
    int h_row=2,h_col=2;   // horizontal (2,2)-(2,4)
    int v_row=5,v_col=1;   // vertical   (5,1)-(7,1)
    int d1_row=0,d1_col=6; // ↘         (0,6)-(2,8)
    int d2_row=9,d2_col=3; // ↗         (9,3)-(7,5)

    if(!cabe_horizontal(h_row,h_col)||!livre_horizontal(board,h_row,h_col)){printf("ERRO horizontal\n");return 0;}
    coloca_horizontal(board,h_row,h_col);

    if(!cabe_vertical(v_row,v_col)||!livre_vertical(board,v_row,v_col)){printf("ERRO vertical\n");return 0;}
    coloca_vertical(board,v_row,v_col);

    if(!cabe_drd(d1_row,d1_col)||!livre_drd(board,d1_row,d1_col)){printf("ERRO diagonal ↘\n");return 0;}
    coloca_drd(board,d1_row,d1_col);

    if(!cabe_urd(d2_row,d2_col)||!livre_urd(board,d2_row,d2_col)){printf("ERRO diagonal ↗\n");return 0;}
    coloca_urd(board,d2_row,d2_col);

    printf("Tabuleiro 10x10 (0=agua, 3=navio):\n");
    print_matrix(board);
    return 0;
}
