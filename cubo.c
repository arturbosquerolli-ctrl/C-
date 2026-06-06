// Arquivo: SOLUÇÃO CUBO
#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

// Leitor do arquivo de texto
int carregar_cubo(const char* nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) return 0;

    char buffer[100];
    fgets(buffer, sizeof(buffer), arquivo); 

    for (int f = 0; f < 6; f++) {
        char letra_face;
        fscanf(arquivo, " %c", &letra_face); 

        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                char letra_cor;
                fscanf(arquivo, " %c", &letra_cor);
                for(int i=0; i<6; i++) {
                    if (letra_cor == letras_cores[i]) {
                        cubo[f][l][c] = i;
                        break;
                    }
                }
            }
        }
    }
    fclose(arquivo);
    return 1;
}

// Algoritmo de Backtracking
int resolve(int qtd_atual, int limite, int* passos_face, int* passos_direcao) {
    if (cubo_esta_resolvido()) return 1; 
    if (qtd_atual >= limite) return 0; 

    for (int f = 0; f < 6; f++) {
        for (int d = 0; d < 2; d++) {
            rotacao(f, d); 
            passos_face[qtd_atual] = f;
            passos_direcao[qtd_atual] = d;
            
            if (resolve(qtd_atual + 1, limite, passos_face, passos_direcao)) {
                return 1; 
            }
            
            // Backtracking
            int direcao_oposta = (d == HORARIO) ? ANTIHORARIO : HORARIO;
            rotacao(f, direcao_oposta); 
        }
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Uso: ./solucao_cubo <arquivo_do_cubo.txt>\n");
        return 1;
    }

    if (!carregar_cubo(argv[1])) {
        printf("Erro ao ler o arquivo %s\n", argv[1]);
        return 1;
    }

    int seq_face[20], seq_dir[20];
    int limite = 6; 
    int resolvido = 0;
    int total_passos = 0;

    printf("Calculando...\n");
    for (int i = 1; i <= limite; i++) {
        if (resolve(0, i, seq_face, seq_dir)) {
            total_passos = i;
            resolvido = 1;
            break;
        }
    }

    if (!resolvido) {
        printf("Nao foi possivel resolver em ate %d movimentos.\n", limite);
        return 1;
    }

    printf("Solucao encontrada em %d passos:\n", total_passos);
    
    carregar_cubo(argv[1]); 

    for (int p = 0; p < total_passos; p++) {
        printf("\nPasso %d: Gire %s no sentido %s\n", p+1, nome_faces[seq_face[p]], nome_direcoes[seq_dir[p]]);
        rotacao(seq_face[p], seq_dir[p]);
        imprime_cubo();
    }

    return 0;
}