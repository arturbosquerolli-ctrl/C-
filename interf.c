// Arquivo Interface 
#include <ncurses.h>
#include "cubo.h"

void inicia_ncurses() {
    initscr();             
    start_color();         
    cbreak();              
    noecho();              
    curs_set(0);           

    init_pair(AMARELO + 1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(VERDE + 1, COLOR_GREEN, COLOR_BLACK);
    init_pair(VERMELHO + 1, COLOR_RED, COLOR_BLACK);
    init_pair(LARANJA + 1, COLOR_MAGENTA, COLOR_BLACK); 
    init_pair(BRANCO + 1, COLOR_WHITE, COLOR_BLACK);
    init_pair(AZUL + 1, COLOR_BLUE, COLOR_BLACK);
}

void desenha_face(int face, int start_y, int start_x) {
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            int cor_adesivo = cubo[face][l][c];
            attron(COLOR_PAIR(cor_adesivo + 1));
            mvprintw(start_y + l, start_x + (c * 3), "[%c]", letras_cores[cor_adesivo]);
            attroff(COLOR_PAIR(cor_adesivo + 1));
        }
    }
}

void mostra_cubo_ncurses() {
    int y_centro = 8;
    int x_centro = 25;

    desenha_face(CIMA, y_centro - 4, x_centro);
    desenha_face(ESQUERDA, y_centro, x_centro - 10);
    desenha_face(FRENTE, y_centro, x_centro);
    desenha_face(DIREITA, y_centro, x_centro + 10);
    desenha_face(TRAS, y_centro, x_centro + 20);
    desenha_face(BAIXO, y_centro + 4, x_centro);

    refresh(); 
}

// Orquestrador da animação
void executaAnimacao(int total_passos, int* seq_face, int* seq_dir) {
    inicia_ncurses();

    mvprintw(0, 0, "CUBO CARREGADO: Pressione qualquer tecla para iniciar a animacao...");
    mostra_cubo_ncurses();
    getch(); 

    for (int p = 0; p < total_passos; p++) {
        clear(); 
        mvprintw(0, 0, "Passo %d de %d: Girando face %s no sentido %s", 
                 p + 1, total_passos, nome_faces[seq_face[p]], nome_direcoes[seq_dir[p]]);
        mvprintw(1, 0, "Pressione qualquer tecla para avancar...");
        
        rotacao(seq_face[p], seq_dir[p]);
        mostra_cubo_ncurses();
        getch(); 
    }

    clear();
    mvprintw(0, 0, "🎉 SUCESSO! Cubo resolvido em %d passos.", total_passos);
    mvprintw(1, 0, "Pressione qualquer tecla para encerrar.");
    mostra_cubo_ncurses();
    getch();

    endwin(); 
}
