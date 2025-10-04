# 🚢 Desafio Batalha Naval — MateCheck

Implementação em **C** dos três níveis do desafio Batalha Naval:

## 📌 Níveis
- **Novato (`batalha_naval_novato.c`)**
  Tabuleiro 5×5, dois navios (horizontal e vertical), impressão de coordenadas e tabuleiro.

- **Aventureiro (`batalha_naval_aventureiro.c`)**
  Tabuleiro 10×10, quatro navios (horizontal, vertical, diagonal ↘ e diagonal ↗), validação e exibição do tabuleiro.

- **Mestre (`batalha_naval_mestre.c`)**
  Matrizes 5×5 de habilidades especiais (cone, cruz, octaedro).

## ⚙️ Compilar e Executar
```bash
# Novato
gcc batalha_naval_novato.c -o novato && ./novato

# Aventureiro
gcc batalha_naval_aventureiro.c -o aventureiro && ./aventureiro

# Mestre
gcc batalha_naval_mestre.c -o mestre && ./mestre

📷 Saídas Esperadas

Novato: imprime coordenadas dos navios e tabuleiro 5×5.

Aventureiro: exibe tabuleiro 10×10 com navios posicionados.

Mestre: mostra padrões das habilidades (cone, cruz, octaedro).

👨‍💻 Autor: Fernando Meira — Desafio MateCheck
