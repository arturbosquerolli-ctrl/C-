//Arquivo: cubo.h
#ifndef CUBO_H
#define CUBO_H

// --- DEFINIÇÕES DE DADOS ---
enum Cores { AMARELO, VERDE, VERMELHO, LARANJA, BRANCO, AZUL };
enum Face { CIMA, BAIXO, ESQUERDA, DIREITA, FRENTE, TRAS };
enum Direcao { HORARIO, ANTIHORARIO };

// VARIÁVEIS GLOBAIS 
extern int cubo[6][3][3];

// ARRAYS DE TEXTO
extern const char* nome_faces[6];
extern const char* nome_direcoes[2];
extern const char letras_cores[6];

// FUNÇÕES
void inicializa_cubo_resolvido();
void rotacao(int face, int direcao);
int cubo_esta_resolvido();
void imprime_cubo();

// INTERFACE GRÁFIC
void executaAnimacao(int total_passos, int* seq_face, int* seq_dir);

#endif
