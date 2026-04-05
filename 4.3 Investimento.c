#include <stdio.h>

int main() {
    char movimento;
    int x = 0, y = 0;
    int matriz[4][4] = {0};

    matriz[y][x]++;  // conta a posi��o inicial

    for (int i = 0; i < 20; i++) {
        scanf(" %c", &movimento);

        int nx = x, ny = y; 

        switch (movimento) {
            
            case 'c': ny--; break;  // cima
            case 'b': ny++; break;  // baixo
            case 'e': nx--; break;  // esquerda
            case 'd': nx++; break;  // direita
        }

        // S� move se n�o sair da matriz
        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
            x = nx;
            y = ny;
        }

        matriz[y][x]++;
    }

    int maxVisitas = -1, melhorCol = 0, melhorLin = 0; // Encontra a c�lula mais visitada
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matriz[i][j] > maxVisitas) {
                maxVisitas = matriz[i][j];
                melhorLin = i;  // linha
                melhorCol = j;  // coluna
            }
        }
    }

    printf("Coordenada X:%d, Y:%d\n", melhorCol, melhorLin);
    return 0;
}
