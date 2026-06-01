#include <stdio.h>
#include <stdlib.h>
#include "verifica_cubo.h" 

int faces[6][3][3]; 

// Ajustadas as assinaturas para aceitar a matriz de 3 dimensões corretamente
void imprime_cubo(int cubo[6][3][3]);
void gera_sequencia(char ** seq, int cubo[6][3][3]); 

int cubo_esta_resolvido() {
    for (int face = 0; face < 6; face++) {
        int cor_centro = faces[face][1][1]; // referência da cor da face
        
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (faces[face][l][c] != cor_centro) {
                    return 0; // Se um quadrado for diferente do centro, não está resolvido
                }
            }
        }
    }
    return 1; 
}

int main(int argc, char ** argv) {
    
    // Chama a função verifica_cubo.c essa funcao verifica o ARQUIVO CUBO
    if (!verifica_cubo()) {
        printf("Execução interrompida: Falha na validação do arquivo.\n");
        return 1; 
    }

    // //aplica solução
    // //cada operação do cubo

    return 0;
}