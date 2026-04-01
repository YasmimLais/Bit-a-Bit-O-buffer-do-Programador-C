#include <stdio.h>

int main() {
    char movimento;
    int x = 0, y = 0;

    // Recebenmos 20 carcteres
    for (int i = 0; i < 20; i++) {

        scanf(" %c", &movimento);

        switch (movimento) {
            case 'c': // Cima:  - (Y)
                y--;
                break;
            case 'b': // Baixo: + (Y)
                y++;
                break;
            case 'e': // Esquerda: - (X)
                x--;
                break;
            case 'd': // Direita: + (X)
                x++;
                break;
        }
    }

    printf("Coordenada X:%d, Y:%d\n", x, y);
    return 0;
}
