#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define STOP 0
#define ESQD 1
#define DIRT 2
#define CIMA 3
#define BAIX 4
#define MURO 178
#define COBR 219
#define FRUT 149

int fimdojogo;
const int largura = 20;
const int altura = 20;

int x, y, frutax, frutay, pontos, direcao;


void inicializa() {
    time_t t;
    fimdojogo = 0;
    pontos = 0;
    direcao = STOP;

    x = largura / 2;
    y = altura / 2;

    srand(time(&t));
    frutax = rand() % largura + 1;
    frutay = rand() % largura + 1;

}

void desenha() {
    int i, j;
    system("cls");

    for (i = 0; i <= largura + 2; i++) {
        printf("%c", char(MURO));

    }
    for (j = 1; j <= altura + 1; j++) {
        printf("\n");
        for (i = 0; i <= largura + 2; i++) {
            if (i == 0 || i == largura + 2) {
                printf("%c", char(MURO));
            }
            else {
                if (i == x && j == y) {
                    printf("%c", char(COBR));
                }
                else if (i == frutax && j == frutay) {
                    printf("%c", char(FRUT));
                }
                else printf(" ");
            }
        }

    }
    printf("\n");

    for (i = 0; i <= largura + 2; i++) {
        printf("%c", char(MURO));

    }
    printf("\npontos = %d", pontos);
}
void entrada()
{
    if (_kbhit()) {
        switch (_getch())
        {
        case 'w':
            direcao = CIMA;
            y--;
            break;
        case 's':
            direcao = BAIX;
            y++;
            break;
        case 'a':
            direcao = ESQD;
            x--;
            break;
        case 'd':
            direcao = DIRT;
            x++;
            break;
        case 'x':
            fimdojogo = 1;
            break;
        case 'X':
            fimdojogo = 1;
            break;
        default:
            break;
        }

    }
}

void logica()
{
  
    if (x == 0 || x == largura + 2 || y == 0 || y == altura + 2) {
        fimdojogo = 1;
    }
    if (x == frutax && y == frutay) {
        pontos = pontos + 10;
        frutax = rand() % largura + 1;
        frutay = rand() % largura + 1;

    }
}

void finaliza() {
    system("cls");
    printf("\n\n***FIM DE JOGO ***\n\n\n\nSua pontuacao foi de: %d", pontos);
}
int main()
{
    inicializa();
    while (!fimdojogo) {
        desenha();
        Sleep(10);
        logica();
        entrada();
    }
    finaliza();
}

