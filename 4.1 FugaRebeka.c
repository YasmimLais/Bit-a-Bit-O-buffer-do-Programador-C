#include <stdio.h>

int main(){
    int linhas, colunas;
    scanf("%dx%d", &linhas, &colunas);

    char labirinto[linhas][colunas];
    int visitado[linhas][colunas];
    int origemL = 0, origemC = 0;

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            scanf(" %c", &labirinto[i][j]);
            visitado[i][j] = 0;
            if(labirinto[i][j] == 'o'){
                origemL = i;
                origemC = j;
            }
        }
    }

    int posLinhas[10000], posColunas[10000], posDistancia[10000];
    int inicio = 0, fim = 0;

    posLinhas[fim]    = origemL;
    posColunas[fim]   = origemC;
    posDistancia[fim] = 0;
    fim++;
    visitado[origemL][origemC] = 1;

    int dl[] = {-1, 1,  0, 0}; // Cima, baixo
    int dc[] = { 0, 0, -1, 1}; // Esquerda, direita
    int achou = 0;
0
    while(inicio < fim){
        int l  = posLinhas[inicio];
        int c  = posColunas[inicio];
        int km = posDistancia[inicio];
        inicio++;

        if(labirinto[l][c] == 'd'){
            printf("Apos correr %d metros e quase desistir por causa da dist�ncia, Rebeka conseguiu escapar!\n", km);
            achou = 1;
            break;
        }

        for(int i = 0; i < 4; i++){
            int nl = l + dl[i];
            int nc = c + dc[i];

            if(nl >= 0 && nl < linhas && nc >= 0 && nc < colunas && !visitado[nl][nc] && labirinto[nl][nc] != '#'){
                visitado[nl][nc] = 1;
                posLinhas[fim]    = nl;
                posColunas[fim]   = nc;
                posDistancia[fim] = km + 1;
                fim++;
            }
        }
    }

    if(!achou){
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    }

    return 0;
}
