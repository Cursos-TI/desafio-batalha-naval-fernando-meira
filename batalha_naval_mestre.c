#include <stdio.h>

// Nivel Mestre — Habilidades em matrizes 0/1 com loops aninhados
// Reproduz exatamente os exemplos do enunciado em 5x5:
// CONE, OCTAEDRO(=losango), CRUZ

#define N 5

void print_matrix(const int m[N][N]) {
    for (int r=0;r<N;r++){ for(int c=0;c<N;c++) printf("%d ", m[r][c]); printf("\n"); }
}
void fill_matrix(int m[N][N], int v) {
    for (int r=0;r<N;r++) for (int c=0;c<N;c++) m[r][c]=v;
}

void habilidade_cone(int m[N][N]) {
    fill_matrix(m,0);
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    // (demais linhas 0)
    m[0][2] = 1;
    m[1][1] = m[1][2] = m[1][3] = 1;
    for (int c=0;c<5;c++) m[2][c] = 1;
}
void habilidade_octaedro(int m[N][N]) {
    fill_matrix(m,0);
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    m[0][2] = 1;
    m[1][1] = m[1][2] = m[1][3] = 1;
    m[2][2] = 1;
}
void habilidade_cruz(int m[N][N]) {
    fill_matrix(m,0);
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    m[0][2] = 1;
    for (int c=0;c<5;c++) m[1][c] = 1;
    m[2][2] = 1;
}

int main(void){
    int cone[N][N], oct[N][N], cruz[N][N];

    habilidade_cone(cone);
    habilidade_octaedro(oct);
    habilidade_cruz(cruz);

    printf("Habilidade: CONE\n"); print_matrix(cone); printf("\n");
    printf("Habilidade: OCTAEDRO (losango)\n"); print_matrix(oct); printf("\n");
    printf("Habilidade: CRUZ\n"); print_matrix(cruz); printf("\n");
    return 0;
}
