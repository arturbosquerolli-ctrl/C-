#include <stdio.h>
#include <stdlib.h>
#include "verifica_cubo.h"

extern int faces[6][3][3]; 

int verifica_cubo() {
    // Altere para abrir o arquivo gerado de teste (ex: "cubo_1.txt")
    FILE *arquivo = fopen("cubo_1.txt", "r");
    
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir o arquivo 'cubo_1.txt'.\n");
        return 0; 
    }

    char buffer[100];
    // Pula a primeira linha de comentário
    fgets(buffer, sizeof(buffer), arquivo);

    // Lendo as 6 faces
    for (int f = 0; f < 6; f++) {
        char letra_face;
        // Lê a letra identificadora da face (U, D, L...) e a quebra de linha
        fscanf(arquivo, " %c", &letra_face); 

        for (int linha = 0; linha < 3; linha++) {
            for (int coluna = 0; coluna < 3; coluna++) {
                char letra_cor;
                // Lê caractere por caractere das cores (Y, G, R, O, W, B)
                fscanf(arquivo, " %c", &letra_cor);

                // Converte a letra lida para o número correspondente do seu enum Cores
                if (letra_cor == 'Y')      faces[f][linha][coluna] = 0; // AMARELO
                else if (letra_cor == 'G') faces[f][linha][coluna] = 1; // VERDE
                else if (letra_cor == 'R') faces[f][linha][coluna] = 2; // VERMELHO
                else if (letra_cor == 'O') faces[f][linha][coluna] = 3; // LARANJA
                else if (letra_cor == 'W') faces[f][linha][coluna] = 4; // BRANCO
                else if (letra_cor == 'B') faces[f][linha][coluna] = 5; // AZUL
                else {
                    printf("Erro: Cor inválida '%c' encontrada.\n", letra_cor);
                    fclose(arquivo);
                    return 0;
                }
            }
        }
    }

    fclose(arquivo);
    printf("Cubo carregado com sucesso a partir do arquivo do gerador!\n");
    return 1; 
}