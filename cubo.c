#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verifica_cubo.h" 

// --- DEFINIÇÕES ---
enum Cores { AMARELO, VERDE, VERMELHO, LARANJA, BRANCO, AZUL };
enum Rotacao { NORTE, SUL, LESTE, OESTE };
enum Direcao { HORARIO, ANTIHORARIO };
enum Face { CIMA, BAIXO, ESQUERDA, DIREITA, FRENTE, TRAS };

// Matriz global do cubo
int faces[6][3][3]; 

// Strings para os passos
const char* movimentos[] = {
    "CIMA_HORARIO", "CIMA_ANTI_HORARIO",
    "BAIXO_HORARIO", "BAIXO_ANTI_HORARIO",
    "ESQUERDA_HORARIO", "ESQUERDA_ANTI_HORARIO",
    "DIREITA_HORARIO", "DIREITA_ANTI_HORARIO"
};

// --- FUNÇÕES DE ROTAÇÃO ---
// Esta função deve aplicar as regras de girar a face e as faixas vizinhas 
void aplicar_movimento(int mov) {
    // Exemplo de algoritmo:
    // if (mov == 0) { /* Gira face CIMA no sentido HORARIO e move suas faixas adjacentes */ }
    // if (mov == 1) { /* Gira face CIMA no sentido ANTIHORARIO e move suas faixas adjacentes */ }
}

// --- VERIFICAÇÃO SE O CUBO FOI RESOLVIDO ---
int cubo_esta_resolvido() {
    for (int face = 0; face < 6; face++) {
        int cor_centro = faces[face][1][1]; // O centro fixo determina a cor da face
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (faces[face][l][c] != cor_centro) {
                    return 0; // Se um adesivo for diferente do centro, não está resolvido
                }
            }
        }
    }
    return 1; 
}

// --- SOLUÇÃO POR BACKTRACKING ---
int resolve(int qtd_atual, int limite, int* passos) {
    if (cubo_esta_resolvido()) {
        return 1; 
    }
    if (qtd_atual >= limite) {
        return 0; 
    }

    // Varre os 8 movimentos básicos da nossa lista de teste
    for (int mov = 0; mov < 8; mov++) {
        
        aplicar_movimento(mov);   // Faz a rotação nas faixas e na face
        passos[qtd_atual] = mov;  // Registra movimentações
        
        // Tenta o próximo passo recursivamente
        if (resolve(qtd_atual + 1, limite, passos)) {
            return 1; 
        }
        
        // BACKTRACK: Se deu errado, desfaz o movimento aplicando o inverso
        int movimento_oposto = (mov % 2 == 0) ? (mov + 1) : (mov - 1);
        aplicar_movimento(movimento_oposto); 
    }

    return 0; 
}

// Função para exibir a solução na tela
void imprime_passos(int* passos, int total) {
    printf("\nSequência de movimentos para resolver:\n");
    for (int i = 0; i < total; i++) {
        printf("  Passo %d: %s\n", i + 1, movimentos[passos[i]]);
    }
}

// --- FUNÇÃO PRINCIPAL MAIN ---
int main(int argc, char ** argv) {
    
    // Lê a partir do arquivo e converte para a estrutura de dados
    if (!verifica_cubo()) {
        printf("Execução interrompida: Falha na validação do arquivo.\n");
        return 1; 
    }

    // Produz a sequência de movimentos que resolve a instância
    int passos[20]; 
    int resolvido = 0;

    printf("Buscando solução para o cubo carregado...\n");

    // Testa soluções curtas de 1 até 6 movimentos
    for (int limite_movimentos = 1; limite_movimentos <= 6; limite_movimentos++) {
        if (resolve(0, limite_movimentos, passos)) {
            printf("\n🎉 SUCESSO! Instância resolvida com %d movimentos.\n", limite_movimentos);
            imprime_passos(passos, limite_movimentos);
            resolvido = 1;
            break;
        }
    }

    if (!resolvido) {
        printf("\nNão foi possível resolver o cubo dentro do limite de movimentos de teste.\n");
    }

    return 0;
}