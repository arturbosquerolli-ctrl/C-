// Arquivo: cubo.h
#ifndef CUBO_H
#define CUBO_H

// Definições padronizadas
enum Cores { AMARELO, VERDE, VERMELHO, LARANJA, BRANCO, AZUL };
enum Face { CIMA, BAIXO, ESQUERDA, DIREITA, FRENTE, TRAS };
enum Direcao { HORARIO, ANTIHORARIO };

// A matriz global que representa o estado do cubo
extern int cubo[6][3][3];

// Arrays de texto para facilitar os prints
extern const char* nome_faces[6];
extern const char* nome_direcoes[2];
extern const char letras_cores[6];

// Protótipos das funções compartilhadas
void inicializa_cubo_resolvido();
void rotacao(int face, int direcao);
int cubo_esta_resolvido();
void imprime_cubo();

#endif